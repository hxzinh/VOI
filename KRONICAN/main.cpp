#include <bits/stdc++.h>
#define ll long long
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

int n, k;
int a[21][21], f[MASK(20)];

void xuli(){
    memset(f, INF, sizeof f);
    f[0] = 0;
    for(int mask = 0; mask < MASK(n); mask++){
        int num = 1;
        for(int i = 0; i < n; i++) if(BIT(i, mask)) num = i + 1;
        for(int i = 1; i <= n; i++) if(!BIT(i - 1, mask) && a[num + 1][i]){
            if(i == num) continue;
            int newMask = mask | MASK(i - 1);
            minimize(f[newMask], f[mask] + a[num + 1][i]);
        }
    }

    int res = INF;
    for(int mask = 0; mask < MASK(n); mask++){
        if(__builtin_popcount(mask) == n - k) minimize(res, f[mask]);
    }
    cout << res;
}
void full(){
    memset(f, INF, sizeof f);
    f[0] = 0;
    for(int mask = 0; mask < MASK(n); mask++){
        for(int i = 1; i <= n; i++) if(!BIT(i - 1, mask)){
            for(int j = 1; j <= n; j++) if(i != j && !BIT(j - 1, mask)){
                int newMask = mask | MASK(i - 1);
                minimize(f[newMask], f[mask] + a[i][j]);
            }
        }
    }

    int res = INF;
    for(int mask = 0; mask < MASK(n); mask++){
        if(__builtin_popcount(mask) == n - k) minimize(res, f[mask]);
    }
    cout << res;
}
int main()
{
    FastIO
    freopen("KRONICAN.INP", "r", stdin);
    freopen("KRONICAN.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cin >> a[i][j];

    //k = n - k;
    full();
    return 0;
}
