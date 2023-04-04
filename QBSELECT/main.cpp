#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int MAX = 1e4 + 10;
int n;
int a[MAX][5], s[MAX][MASK(4)], f[MAX][MASK(4)];

void xuli(){
    bool cx = false;
    int t = -INF;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= 4; j++){
            if(a[i][j] > 0) cx = true;
            maximize(t, a[i][j]);
        }

    if(!cx){
        cout << t;
        return;
    }

    for(int i = 1; i <= n; i++){
        for(int mask = 0; mask < MASK(4); mask++){
            int cost = 0;
            for(int j = 0; j < 4; j++)
                if(BIT(j, mask)) cost += a[i][j + 1];
            s[i][mask] = cost;
        }
    }

    memset(f, -INF, sizeof f);
    for(int mask = 0; mask < MASK(4); mask++) f[0][mask] = 0;

    for(int i = 1; i <= n; i++){
        for(int mask = 0; mask < MASK(4); mask++){
            for(int preMask = 0; preMask < MASK(4); preMask++){
                bool ok = true;
                for(int j = 0; j <= 3; j++) if(BIT(j, mask) && BIT(j + 1, mask)){
                    ok = false;
                    break;
                }
                if(!ok) continue;
                if(!(mask & preMask)) maximize(f[i][mask], f[i - 1][preMask] + s[i][mask]);
            }
        }
    }

    int res = -INF;
    for(int mask = 0; mask < MASK(4); mask++) maximize(res, f[n][mask]);
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("QBSELECT.INP", "r", stdin);
    freopen("QBSELECT.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= n; j++) cin >> a[j][i];

    xuli();
    return 0;
}
