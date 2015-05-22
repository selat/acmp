#include <vector>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	vector <char> s(n + 1);
	scanf("%100000s", &s[0]);
	vector <int> occurences('Z' - 'A' + 1);
	vector <int> last_pos('Z' - 'A' + 1, -1);
	for(int i = 0; i < k; ++i) {
		last_pos[s[i] - 'A'] = i;
	}
	map <int, int> best_ways;
	vector <int> d(n);
	d[0] = 0;
	++best_ways[d[0]];
	for(int i = 1; i < k; ++i) {
		d[i] = (s[i] == s[0])?0:1;
		++best_ways[d[i]];
	}

	for(int i = k; i < n; ++i) {
		if(last_pos[s[i] - 'A'] + k >= i) {
			d[i] = d[last_pos[s[i] - 'A']];
		} else {
			d[i] = best_ways.begin()->first + 1;
		}
		++best_ways[d[i]];
		last_pos[s[i] - 'A'] = i;
		if(--best_ways[d[i - k]] == 0) {
			best_ways.erase(best_ways.find(d[i - k]));
		}
	}
	printf("%d\n", d[n - 1]);
	return 0;
}
