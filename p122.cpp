#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector <int> a(n);
	vector <int> d(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		d[i] = 1;
	}
	for(int i = 1; i < n; ++i) {
		d[i] = 1;
		for(int j = 0; j < i; ++j) {
			if(a[j] < a[i]) {
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}
	int res = 0;
	for(int i = 0; i < n; ++i) {
		res = max(res, d[i]);
	}
	cout << res << endl;
	return 0;
}
