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
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 3e3 + 10;
const int MOD = 1e9 + 7;
int n;
char a[NM];
int f[NM][NM];

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void xuli(){
    f[1][1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if(a[i - 1] == '<') f[i][j] = f[i - 1][j - 1];
            else f[i][j] = (f[i - 1][i - 1] - f[i - 1][j - 1] + MOD) % MOD;
        }
        for(int j = 1; j <= i; j++) add(f[i][j], f[i][j - 1]);
    }
    cout << f[n][n];
}
int32_t main()
{
    FastIO
    freopen("PERMUTATION.INP", "r", stdin);
    freopen("PERMUTATION.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i < n; i++) cin >> a[i];

    xuli();
    return 0;
}
