#include <cstdio>
#include <algorithm>

using namespace std;

bool suits(unsigned int mask1, unsigned int mask2, int len)
{
	for(int i = 0; i + 2 <= len; ++i) {
		if(((mask1 & (3 << i)) == (mask2 & (3 << i)))
		   && ((mask1 & (1 << i)) == ((mask1 & (2 << i)) >> 1))) {
			return false;
		}
	}
	return true;
}

int solve(int n, int m)
{
	int pans[64];
	int ans[64];
	int max_mask = (1 << n);
	for(int i = 0; i < max_mask; ++i) {
		pans[i] = 1;
		ans[i] = 0;
	}
	for(int i = 2; i <= m; ++i) {
		for(unsigned int mask1 = 0; mask1 < max_mask; ++mask1) {
			for(unsigned int mask2 = 0; mask2 < max_mask; ++mask2) {
				if(suits(mask2, mask1, n)) {
					ans[mask1] += pans[mask2];
				}
			}
		}
		for(unsigned int mask1 = 0; mask1 < max_mask; ++mask1) {
			pans[mask1] = ans[mask1];
			ans[mask1] = 0;
		}
	}
	int res = 0;
	for(unsigned int mask1 = 0; mask1 < max_mask; ++mask1) {
		res += pans[mask1];
	}
	return res;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d\n", solve(min(n, m), max(n, m)));
	return 0;
}
