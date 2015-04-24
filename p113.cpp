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
    vector <vector <bool> > a(n, vector <bool> (n));
    vector <vector <int> > d(n, vector <int> (n));
    int res = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf(" %c ", &c);
            a[i][j] = (c == '1');
        }
    }
    for(int i = 0; i < n; ++i) {
        d[i][0] = (a[i][0])?1:0;
        d[0][i] = (a[0][i])?1:0;
        res = max(res, d[i][0]);
        res = max(res, d[0][i]);
    }
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < n; ++j) {
            if(a[i][j]) {
                d[i][j] = min(min(d[i - 1][j], d[i][j - 1]), d[i - 1][j - 1]) + 1;
            } else {
                d[i][j] = 0;
            }
            res = max(res, d[i][j]);
        }
    }
    printf("%d\n", res * res);
    return 0;
}
