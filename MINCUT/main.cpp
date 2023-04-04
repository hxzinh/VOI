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

const int NM = 1e3 + 10;
int n, m, k;
int a[NM][NM], s[NM][NM];

int getSum(int x, int y, int u, int v){
    return s[u][v] - s[u][y - 1] - s[x - 1][v] + s[x - 1][y - 1];
}
void sub2(){
    while(k--){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        int res = INF;
        for(int i = x; i < u; i++){
            int sumL = getSum(x, y, i, v);
            int sumR = getSum(i + 1, y, u, v);
            minimize(res, abs(sumL - sumR));
        }
        for(int i = y; i < v; i++){
            int sumL = getSum(x, y, u, i);
            int sumR = getSum(x, i + 1, u, v);
            minimize(res, abs(sumL - sumR));
        }
        cout << res << '\n';
    }
}
int getMinX(int x, int y, int u, int v){
    int l = x, r = u - 1, pos = x;
    while(l <= r){
        int m = (l + r) >> 1;
        if(getSum(x, y, m, v) <= getSum(m + 1, y, u, v)){
            pos = m;
            l = m + 1;
        } else r = m - 1;
    }
    int res = abs(getSum(x, y, pos, v) - getSum(pos + 1, y, u, v));
    if(pos + 1 < u) minimize(res, abs(getSum(x, y, pos + 1, v) - getSum(pos + 2, y, u, v)));
    return res;
}
int getMinY(int x, int y, int u, int v){
    int l = y, r = v - 1, pos = y;
    while(l <= r){
        int m = (l + r) >> 1;
        if(getSum(x, y, u, m) <= getSum(x, m + 1, u, v)){
            pos = m;
            l = m + 1;
        } else r = m - 1;
    }
    int res = abs(getSum(x, y, u, pos) - getSum(x, pos + 1, u, v));
    if(pos + 1 < v) minimize(res, abs(getSum(x, y, u, pos + 1) - getSum(x, pos + 2, u, v)));
    return res;
}
void full(){
    while(k--){
        int u, v, x, y;
        cin >> x >> y >> u >> v;
        int res = min(getMinX(x, y, u, v), getMinY(x, y, u, v));
        cout << res << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("MINCUT.INP", "r", stdin);
    freopen("MINCUT.OUT", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];

    full();
    return 0;
}
