#include <iostream>
#include <vector>

using namespace std;

struct State
{
	State() :
		min_money(1000000),
		used_coupons(0)
	{
	}
	int min_money;
	int used_coupons;
};

int main()
{
	int n;
	cin >> n;
	vector <int> a(n + 1);
	vector <vector <State> > d(n + 1 ,vector <State>(n + 1));
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if(n == 0) {
		cout << 0 << endl;
		cout << "0 0" << endl;
		return 0;
	}
	d[0][0].min_money = 0;
	d[0][0].used_coupons = 0;
	/*
	 * d[day][rem_coupons].min_money = min(
	 *     d[day - 1][rem_coupons - 1].min_money + a[day], here we buy lunch at current day, and it's cost is bigger than 100, therefore we get one additional coupon.
	 *     d[day - 1][rem_coupons].min_money + a[day], here we buy lunch at current day, but it's cost isn't bigger than 100, therefore we don't get one additional couopon.
	 *     d[day - 1][rem_coupons + 1].min_money, here we use on of coupons to get free lunch for current day.
	 * )
	 */
	for(int day = 1; day <= n; ++day) {
		for(int rem_coupons = 0; rem_coupons <= n; ++rem_coupons) {
			if((rem_coupons - 1 >= 0) && (a[day] > 100) && (d[day - 1][rem_coupons - 1].min_money + a[day] < d[day][rem_coupons].min_money)) {
				d[day][rem_coupons].min_money = d[day - 1][rem_coupons - 1].min_money + a[day];
				d[day][rem_coupons].used_coupons = d[day - 1][rem_coupons - 1].used_coupons;
			}
			if((a[day] <= 100) && (d[day - 1][rem_coupons].min_money + a[day] < d[day][rem_coupons].min_money)) {
				d[day][rem_coupons].min_money = d[day - 1][rem_coupons].min_money + a[day];
				d[day][rem_coupons].used_coupons = d[day - 1][rem_coupons].used_coupons;
			}
			if((rem_coupons + 1 < n) && (d[day - 1][rem_coupons + 1].min_money < d[day][rem_coupons].min_money)) {
				d[day][rem_coupons].min_money = d[day - 1][rem_coupons + 1].min_money;
				d[day][rem_coupons].used_coupons = d[day - 1][rem_coupons + 1].used_coupons;
				++d[day][rem_coupons].used_coupons;
			}
		}
	}
	State best_state;
	int best_rem_coupons = 0;
	for(int rem_coupons = 0; rem_coupons <= n; ++rem_coupons) {
		if(d[n][rem_coupons].min_money <= best_state.min_money) {
			best_state = d[n][rem_coupons];
			best_rem_coupons = rem_coupons;
		}
	}
	cout << best_state.min_money << endl;
	cout << best_rem_coupons << " " << best_state.used_coupons << endl;
	return 0;
}
