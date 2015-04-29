#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int k, p;
	cin >> k >> p;
	if(p >= 2) {
		vector <int> d(max(k, 2) + 1, 0);
		d[0] = 0;
		d[1] = 0;
		d[2] = 1;
		for(int i = 0; i < k; ++i) {
			if(2 * i <= k) {
				d[2 * i] = (d[i] + d[2 * i]) % p;
			}
			d[i + 1] = (d[i] + d[i + 1]) % p;
		}
		cout << d[k] << endl;
	} else {
		cout << 0 << endl;
	}
	return 0;
}
