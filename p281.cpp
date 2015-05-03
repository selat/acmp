#include <vector>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	int ans = (1 << n);
	int curc = 1;
	for(int i = 0; i < m; ++i) {
		ans -= curc;
		curc = curc * (n - i) / (i + 1);
	}
	printf("%d\n", ans);
	return 0;
}
