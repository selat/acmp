#include <map>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	char c;
	scanf("%d", &n);
	const int mid = n;
	vector <bool> is_boy(n);
	for(int i = 0; i < n; ++i) {
		scanf(" %c", &c);
		is_boy[i] = (c == 'b');
	}
	unsigned long long ans = 0;
	vector <int> diff_cnt(mid * 2 + 10, 0);
	int cur_diff = 0;
	for(int i = 0; i < n; ++i) {
		if(is_boy[i]) {
			++cur_diff;
		} else {
			--cur_diff;
		}
		ans += diff_cnt[mid + cur_diff];
		if(cur_diff == 0) {
			++ans;
		}
		++diff_cnt[mid + cur_diff];
	}
	printf("%llu\n", ans);
	return 0;
}
