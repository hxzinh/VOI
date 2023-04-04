#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define ALL(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define fi first
#define se second
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 9e3 + 10;
int n;
int result = INF;
int h[9001];
ll s[9001];
int c[9001][9001];

void xuli(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) c[i][j] = INF;
    for(int i = 1; i <= n; i++) c[1][i] = 1;

    for(int i = 2; i <= n; i++){
        int k = i - 1, best = -1;
        for(int j = i; j <= n; j++){
            while(k > 0 && s[j] - s[i - 1] > s[i - 1] - s[k - 1]){
                maximize(best, c[k][i - 1]);
                k--;
            }
            if(best > 0) c[i][j] = best + 1;
            else c[i][j] = -1;
        }
    }
    int res = -1;
    for(int i = 1; i <= n; i++) maximize(res, c[i][n]);
    cout << n - res;
}
int32_t main()
{
    FastIO
    freopen("TOWERS.INP", "r", stdin);
    freopen("TOWERS.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];

    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + h[i];

    xuli();
    return 0;
}
