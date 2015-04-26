#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string s;
	cin >> s;
	int n = s.length();
	vector <vector <int> > d(n, vector <int> (n, 0));

	for(int i = 0; i < n; ++i) {
		d[i][i] = 1;
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j + i < n; ++j) {
			if(i == 0) {
				d[j][j] = 1;
			} else if(i == 1) {
				if(s[j] == s[j + 1]) {
					d[j][j + 1] = 3;
				} else {
					d[j][j + 1] = 2;
				}
			} else if(s[j] == s[i + j]) {
				d[j][i + j] = 1 + d[j + 1][i + j] + d[j][i + j - 1];
			} else {
				d[j][i + j] = d[j + 1][i + j] + d[j][i + j - 1] - d[j + 1][i + j - 1];
			}
		}
	}
	cout << d[0][n - 1] << endl;
	return 0;
}
