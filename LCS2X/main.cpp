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
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1505;
int T, n, m;
int cnt = 0;
int a[NM], b[NM], Lis[NM], s[NM], p[NM], X[NM], Y[NM];
int f[NM][NM], g[NM];
vector<int> val;

struct FenwickTree{
    vector<int> v;
    int n;

    FenwickTree(int _n = 0){
        n = _n;
        v.assign(n + 7, -INF);
    }

    void update(int x, int c){
        maximize(v[x], c);
        for(; x <= n; x += x & (-x)) maximize(v[x], c);
    }

    int getMax(int x) const {
        int res = 0;
        for(; x >= 1; x &= x - 1) maximize(res, v[x]);
        return res;
    }
};

void renew(){
    memset(a, 0, (n + 1) * sizeof(int));
    memset(b, 0, (m + 1) * sizeof(int));
    memset(Lis, 0, (cnt + 1) * sizeof(int));
    memset(g, 0, sizeof(g));
    cnt = 0;
    memset(f, -1, sizeof f);
    val.clear();

    memset(X, 0, (n + 1) * sizeof(int));
    memset(Y, 0, (m + 1) * sizeof(int));
}
int dp(int x, int y){
    if(x > n || y > m) return 0;
    int &res = f[x][y];
    if(res > -1) return res;
    if(a[x] == b[y]) maximize(res, 1 + dp(x + 1, y + 1));
    maximize(res, dp(x + 1, y));
    maximize(res, dp(x, y + 1));
    return res;
}
void trace(int x, int y){
    if(x > n || y > m) return;
    if(a[x] == b[y]){
        Lis[++cnt] = a[x];
        trace(x + 1, y + 1);
        return;
    }
    if(f[x + 1][y] >= f[x][y + 1]) trace(x + 1, y);
    else trace(x, y + 1);
}
bool cmp(const pii &A, const pii &B){
    return A.fi < A.se;
}
void sub1(){
    int numLis = dp(1, 1);
    if(numLis == 0){
        cout << 0 << '\n';
        return;
    }
    trace(1, 1);

    int dem = 0;
    for(int i = 1; i <= numLis; i++){
        val.push_back(Lis[i]);
        p[i] = Lis[i];
    }
    val.resize(unique(ALL(val)) - val.begin());
    for(int i = 1; i <= numLis; i++) Lis[i] = lower_bound(ALL(val), Lis[i]) - val.begin() + 1;

    s[0] = INF;
    for(int u : val) s[++dem] = u;

    FenwickTree tree(NM);
    for(int i = 1; i <= numLis; i++) tree.update(i, 0);
    for(int i = 1; i <= numLis; i++){
        int l = 1, r = dem, pos = 0;
        while(l <= r){
            int m = (l + r) >> 1;
            if(s[m] <= p[i] / 2){
                pos = m;
                l = m + 1;
            } else r = m - 1;
        }
        if(s[pos] > p[i] / 2) maximize(g[i], 1);
        else maximize(g[i], tree.getMax(pos) + 1);
        int u = tree.getMax(Lis[i]);
        tree.update(Lis[i], g[i]);
    }

    int res = 0;
    for(int i = 1; i <= numLis; i++) maximize(res, g[i]);
    cout << res << '\n';
}
void xuli(){
    int res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int tmp = X[i];
            if(2 * b[j] <= a[i]) maximize(X[i], Y[j]);
            if(a[i] == b[j]){
                Y[j] = tmp + 1;
                maximize(res, Y[j]);
            }
        }
    }
    cout << res << '\n';
}
int main()
{
    FastIO
    freopen("LCS2X.INP", "r", stdin);
    freopen("LCS2X.OUT", "w", stdout);
    cin >> T;
    while(T--){
        cin >> n >> m;
        renew();
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= m; i++) cin >> b[i];

        xuli();
    }
    return 0;
}
