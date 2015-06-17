#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

unsigned int myabs(int x)
{
	return (x<0)?-x:x;
}

int main()
{
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int n, k, tmp;
	cin >> n >> k;
	vector <int> m(n);
	vector <int> mres(n - 1);
	int x = 0;
	int total_change_num = 0;
	int change_num = 0;
	for(int i = 0; i < n; ++i) {
		cin >> m[i];
		x ^= myabs(m[i]);
	}
	for(int i = 0; i + 1 < n; ++i) {
		cin >> mres[i];
		x ^= myabs(mres[i]);
	}
	for(int i = 0; i < k; ++i) {
		cin >> tmp;
		if(tmp == x) {
			++change_num;
		}
	}
	for(int i = 0; i < n; ++i) {
		if(myabs(m[i]) == x) {
			++total_change_num;
		}
	}
	for(int i = 0; i + 1 < n; ++i) {
		if(myabs(mres[i]) == x) {
			--total_change_num;
		}
	}
	unsigned int diff = myabs(total_change_num - change_num);
	if(diff & 1) {
		x = -x;
	}
	cout << x << endl;
	return 0;
}
