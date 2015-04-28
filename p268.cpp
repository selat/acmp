#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

short int d[5000][5000];

inline int getChangesNum(const string &s, int l, int r)
{
	int m = (r - l + 1) / 2;
	int res = 0;
	for(int i = 0; i < m; ++i) {
		if(s[i + l] != s[r - i]) {
			++res;
		}
	}
	return res;
}

int solve1(const string &s, int k)
{
	int n = s.length();
	int res = 0;
	for(int l = 0; l < n; ++l) {
		for(int r = l; r < n; ++r) {
			if(getChangesNum(s, l, r) <= k) {
				++res;
			}
		}
	}
	return res;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;

	for(int i = 0; i + 1 < n; ++i) {
		d[i][i] = 0;
		d[i][i + 1] = (s[i] == s[i + 1])?0:1;
	}
	d[n - 1][n - 1] = 0;

	for(int len = 3; len <= n; ++len) {
		for(int start = 0; start + len - 1 < n; ++start) {
			int end = start + len - 1;
			d[start][end] = (s[start] == s[end])?0:1;
			d[start][end] += d[start + 1][end - 1];
		}
	}

	int ans = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = i; j < n; ++j) {
			if(d[i][j] <= k) {
				++ans;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
