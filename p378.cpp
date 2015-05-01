#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int MAXA = 100;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector <int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector <bool> d(n * MAXA + 1, false);
	d[0] = true;
	for(int i = 0; i < n; ++i) {
		int max_sum = (i + 1) * 100;
		for(int j = max_sum; j >= 0; --j) {
			d[j + a[i]] = d[j + a[i]] | d[j];
		}
	}
	int ans = 0;
	for(int i = 0; i < d.size(); ++i) {
		if(d[i]) {
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
