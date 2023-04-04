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
int n;
int a[NM], f[NM][NM];

int dp(int x, int y){
    if(x > y) return 0;
    int &res = f[x][y];
    if(res > -1) return res;
    maximize(res, a[x] - dp(x + 1, y));
    maximize(res, a[y] - dp(x, y - 1));
    return res;
}
void xuli(){
    memset(f, -INF, sizeof f);
    for(int i = 1; i <= n; i++) f[i][i] = a[i];
    cout << dp(1, n);
}
int32_t main()
{
    FastIO
    freopen("DEQUE.INP", "r", stdin);
    freopen("DEQUE.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    xuli();
    return 0;
}
