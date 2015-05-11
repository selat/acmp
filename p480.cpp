#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d", &n);
	vector <int> num(n + 1);
	vector <int> sum(n + 1);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &num[i]);
	}
	sum[n] = num[n];
	for(int i = n - 1; i >= 1; --i) {
		sum[i] = num[i] + sum[i + 1];
	}
	scanf("%d", &k);
	vector <vector <int> > d(n + 1, vector <int>(k + 1, 0));
	for(int i = 1; i <= k; ++i) {
		d[n][i] = num[n];
	}
	for(int first_roll = n - 1; first_roll >= 1; --first_roll) {
		for(int max_step = 1; max_step <= k; ++max_step) {
			if(first_roll + max_step > n) {
				d[first_roll][max_step] = sum[first_roll];
			} else {
				int max_sum = 0;
				for(int i = first_roll + 1; i <= max_step + first_roll; ++i) {
					if(sum[first_roll] - d[i][i - first_roll] > max_sum) {
						max_sum = sum[first_roll] - d[i][i - first_roll];
					}
				}
				d[first_roll][max_step] = max_sum;
			}
		}
	}
	printf("%d\n", d[1][k]);
	return 0;
}
