#include <iostream>
#include <fstream>

using namespace std;

int a[20][20];
int d[20][20];

int main()
{
	ifstream cin("INPUT.TXT");
	ofstream cout("OUTPUT.TXT");
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	d[0][0] = a[0][0];
	for(int i = 1; i < n; ++i) {
		d[i][0] = a[i][0] + d[i - 1][0];
	}
	for(int i = 1; i < m; ++i) {
		d[0][i] = a[0][i] + d[0][i - 1];
	}
	for(int i = 1; i < n; ++i) {
		for(int j = 1; j < m; ++j) {
			d[i][j] = min(d[i - 1][j], d[i][j - 1]) + a[i][j];
		}
	}
	cout << d[n - 1][m - 1] << endl;
	return 0;
}
