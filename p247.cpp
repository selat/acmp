#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> a(n);
	vector <vector <int> > d(n ,vector <int>(n, 100000));
	vector <vector <int> > coupons_num(n, vector <int>(n, 0));
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	if(n == 0) {
		cout << 0 << endl;
		cout << "0 0" << endl;
		return 0;
	}
	d[0][0] = a[0];
	coupons_num[0][0] = ((a[0] > 100)?1:0);
	for(int i = 1; i < n; ++i) {
		d[i][0] = d[i - 1][0] + a[i];
		coupons_num[i][0] = coupons_num[i - 1][0] + ((a[i] > 100)?1:0);
		cout << d[i][0] << " " << i << " " << 0 << endl;
		for(int j = 1; j < n; ++j) {
			d[i][j] = d[i - 1][j] + a[i];
			coupons_num[i][j] = coupons_num[i - 1][j] + ((a[i] > 100)?1:0);
			cout << d[i][j] << " ";
			int sum = 0;
			for(int k = i; k >= 1; --k) {
				if(coupons_num[k - 1][j - 1] >= j) {
					if(d[k - 1][j - 1] + sum < d[i][j]) {
						d[i][j] = d[k - 1][j - 1] + sum;
						cout << "I: " << d[i][j] << " " << k << endl;
						coupons_num[i][j] = coupons_num[k - 1][j - 1];
					} else if(d[k - 1][j - 1] + sum == d[i][j]) {
						coupons_num[i][j] = max(coupons_num[i][j], coupons_num[k - 1][j - 1]);
					}
				}
				sum += a[k];
			}
			cout << d[i][j] << " " << i << " " << j << endl;
		}
	}
	int ans = 100000;
	int left_coupons = 0;
	int spent_coupons = 0;
	for(int i = 0; i < n; ++i) {
		if(d[n - 1][i] < ans) {
			ans = d[n - 1][i];
			left_coupons = coupons_num[n - 1][i] - i;
			spent_coupons = i;
		} else if(d[n - 1][i] == ans) {
			if(coupons_num[n - 1][i] - i > left_coupons) {
				left_coupons = coupons_num[n - 1][i] - i;
				spent_coupons = i;
			}
		}
	}
	cout << ans << endl;
	cout << left_coupons << " " << spent_coupons << endl;
	return 0;
}
