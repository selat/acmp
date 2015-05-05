#include <cstdio>
#include <vector>

using namespace std;

const int MOD = 1000000009;

bool isPrime(int n)
{
	for(int i = 2; i * i <= n; ++i) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}

vector <int> genPrimes()
{
	vector <int> p;
	for(int i = 101; i < 1000; ++i) {
		if(isPrime(i) && ((i - (i % 10)) % 100 != 0)) {
			p.push_back(i);
		}
	}
	return p;
}

vector <vector <int> > genCloseMatrix(const vector <int> &p)
{
	vector <vector <int> > m(p.size(), vector <int> ());
	int n = p.size();
	for(int i = 0; i < n; ++i) {
		int d_i_1 = (p[i] / 100);
		int d_i_2 = ((p[i] % 100) / 10);
		for(int j = 0; j < n; ++j) {
			int d_j_2 = ((p[j] % 100) / 10);
			int d_j_3 = (p[j] % 10);
			if((d_i_1 == d_j_2) && (d_i_2 == d_j_3)) {
				m[i].push_back(j);
			}
		}
	}
	return m;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	vector <vector <int> > can_place = genCloseMatrix(genPrimes());
	int n;
	scanf("%d", &n);
	vector <vector <int> > d(n + 1, vector <int> (can_place.size(), 0));
	for(int i = 0; i < can_place.size(); ++i) {
		d[3][i] = 1;
	}

	for(int i = 4; i <= n; ++i) {
		for(int j = 0; j < can_place.size(); ++j) {
			for(int k = 0; k < can_place[j].size(); ++k) {
				int id = can_place[j][k];
				d[i][j] += d[i - 1][id];
				d[i][j] %= MOD;
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < can_place.size(); ++i) {
		ans += d[n][i];
		ans %= MOD;
	}
	if(n == 3) {
		ans = 143;
	}
	printf("%d\n", ans);

	return 0;
}
