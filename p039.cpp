#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector <int> c(n);
	map <int, int, greater<int> > cnt;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &c[i]);
		++cnt[c[i]];
	}
	int curlength = 1;
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		if(c[i] == cnt.begin()->first) {
			ans += c[i] * curlength;
			curlength = 0;
		}
		++curlength;
		--cnt[c[i]];
		if(cnt[c[i]] == 0) {
			cnt.erase(c[i]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
