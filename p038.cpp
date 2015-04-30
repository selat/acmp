#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector <vector <int> > d(n, vector <int> (n, 0));
	vector <int> s(n);
	vector <int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		s[i] = a[i];
		if(i > 0) {
			s[i] += s[i - 1];
		}
		d[i][i] = a[i];
	}

	for(int len = 2; len <= n; ++len) {
		for(int j = 0; j + len <= n; ++j) {
			int l = j;
			int r = j + len - 1;
			d[l][r] = max(a[l] + (s[r] - s[l]) - d[l + 1][r],
			              a[r] + (s[r - 1] - ((l>0)?s[l - 1]:0)) - d[l][r - 1]);
		}
	}


	if(d[0][n - 1] * 2 > s[n - 1]) {
		cout << 1 << endl;
	} else if(d[0][n - 1] * 2 == s[n - 1]) {
		cout << 0 << endl;
	} else {
		cout << 2 << endl;
	}

	return 0;
}
