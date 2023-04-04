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
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 3e2 + 10;
int n, k;
int a[NM], f[NM][NM][NM];

int dp(int x, int y, int cnt){
    if(x > y || cnt >= k) return 0;
    int &res = f[x][y][cnt];
    if(res > -1) return res;
    if(x + 1 <= y) maximize(res, abs(a[x] - a[x + 1]) + dp(x + 2, y, cnt + 1));
    if(y - 1 >= x) maximize(res, abs(a[y] - a[y - 1]) + dp(x, y - 2, cnt + 1));
    if(x < y) maximize(res, abs(a[x] - a[y]) + dp(x + 1, y - 1, cnt + 1));
    maximize(res, dp(x + 1, y, cnt));
    maximize(res, dp(x, y - 1, cnt));
    return res;
}
void xuli(){
    memset(f, -1, sizeof f);
    cout << dp(1, n, 0);
}
int32_t main()
{
    FastIO
    freopen("BONUS.INP", "r", stdin);
    freopen("BONUS.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    xuli();
    return 0;
}
