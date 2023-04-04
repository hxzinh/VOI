#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
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

int n, k;
int a[21][21], f[MASK(21)], g[MASK(21)];

void full(){
    memset(f, INF, sizeof f);
    f[0] = 0; g[0] = 1;

    for(int mask = 0; mask < MASK(n); mask++){
        int num = __builtin_popcount(mask) + 1;
        for(int i = 1; i <= n; i++) if(!BIT(i - 1, mask)){
            int newMask = mask | MASK(i - 1);
            if(minimize(f[newMask], f[mask] + a[i][num])) g[newMask] = g[mask];
            else if(f[newMask] == f[mask] + a[i][num]) g[newMask] += g[mask];
        }
    }

    cout << f[MASK(n) - 1] << " " << g[MASK(n) - 1];
}
int32_t main()
{
    FastIO
    freopen("MAUGIAO.INP", "r", stdin);
    freopen("MAUGIAO.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cin >> a[i][j];

    //k = n - k;
    full();
    return 0;
}
