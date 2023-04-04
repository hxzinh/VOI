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

const int MOD = 1e9 + 7;
int n;
int a[25][25], f[22][MASK(21)], g[MASK(21)];

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void xuli(){
    f[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int mask = 0; mask < MASK(n); mask++){
            for(int j = 1; j <= n; j++) if(!BIT(j - 1, mask) && a[i + 1][j]){
                int newMask = mask | MASK(j - 1);
                add(f[i + 1][newMask], f[i][mask]);
            }
        }
    }
    cout << f[n][MASK(n) - 1];
}
void full(){
    g[0] = 1;
    for(int mask = 0; mask < MASK(n); mask++){
        int num = __builtin_popcount(mask);
        for(int i = 1; i <= n; i++) if(!BIT(i - 1, mask) && a[num + 1][i]){
            int newMask = mask | MASK(i - 1);
            add(g[newMask], g[mask]);
        }
    }
    cout << g[MASK(n) - 1];
}
int main()
{
    FastIO
    freopen("MATCHING.INP", "r", stdin);
    freopen("MATCHING.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cin >> a[i][j];

    full();
    return 0;
}
