#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 70;
int a[MAXN][MAXN];
int d[MAXN][MAXN];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	d[0][0] = 1;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if((i < n - 1) || (j < m - 1)) {
				int len = a[i][j];
				if(i + len < n) {
					d[i + len][j] += d[i][j];
				}
				if(j + len < m) {
					d[i][j + len] += d[i][j];
				}
			}
		}
	}
	cout << d[n - 1][m - 1] << endl;
	return 0;
}
