#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int myabs(int a)
{
	if(a < 0) {
		return -a;
	} else {
		return a;
	}
}

int mymin(int a, int b)
{
	if(a < b) {
		return a;
	} else {
		return b;
	}
}

int main()
{
	ifstream cin("INPUT.TXT");
	ofstream cout("OUTPUT.TXT");
	int n;
	cin >> n;
	vector <int> a(n);
	vector <int> d(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	d[0] = 0;
	d[1] = myabs(a[1] - a[0]);
	for(int i = 2; i < n; ++i) {
		d[i] = mymin(d[i - 1] + myabs(a[i - 1] - a[i]),
		             d[i - 2] + 3 * myabs(a[i - 2] - a[i]));
	}
	cout << d[n - 1] << endl;
	return 0;
}
