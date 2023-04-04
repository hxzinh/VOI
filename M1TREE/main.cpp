#include <bits/stdc++.h>
#define ll long long
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
const int LOG = 20;
int n, Time = 0;
int a[NM], high[NM], P[NM][23], minWeight[NM][25];
ll f[NM];
vector<int> edges[NM];

void dfs(int u, int p) {
    P[u][0] = p;

    if(p != -1) {
        minWeight[u][0] = min(a[u], a[p]);
    }

    for(int i = 1; i <= LOG; i++) {
        if(P[u][i - 1] != -1) {
            P[u][i] = P[P[u][i - 1]][i - 1];
            minWeight[u][i] = min(minWeight[u][i - 1], minWeight[P[u][i - 1]][i - 1]);
        }
    }

    for(int v : edges[u]) if(v != p) {
        high[v] = high[u] + 1;
        dfs(v, u);
    }
}
void sub1() {
    memset(P, -1, sizeof P);
    dfs(1, -1);

    for(int i = 1; i <= n; i++) {
        ll sum = 0, u = i, curMin = INF;
        while(u != -1) {
            minimize(curMin, a[u]);
            sum += curMin;
            u = P[u][0];
        }
        cout << sum << " ";
    }
}
int getMin(int u, int v) {
    int minWei = INF;
    if(high[u] > high[v]) swap(u, v);

    for(int i = LOG - 1; i >= 0; i--) {
        if(P[v][i] != -1 && high[P[v][i]] >= high[u]) {
            minimize(minWei, minWeight[v][i]);
            v = P[v][i];
        }
    }

    if(u == v) return minWei;

    for(int i = LOG - 1; i >= 0; i--) {
        if(P[v][i] != P[u][i]) {
            minimize(minWei, min(minWeight[v][i], minWeight[u][i]));
            u = P[u][i];
            v = P[v][i];
        }
    }

    minimize(minWei, min(minWeight[u][0], minWeight[v][0]));
    return minWei;
}
void xuli() {
    for(int i = 1; i <= n; i++) {
        f[i] = -1;
        for(int j = 0; j <= LOG; j++) {
            minWeight[i][j] = -1;
            P[i][j] = -1;
        }
    }

    dfs(1, -1);

    for(int i = 1; i <= n; i++) {
        ll curMin = a[i], u = i, pre = u;
        ll ans = 0;
        while(u > 0) {
            for(int j = LOG - 1; j >= 0; j--) {
                if(curMin <= minWeight[u][j]) {
                    u = P[u][j];
                    break;
                }
            }
            ans += curMin * (high[pre] - high[u] + 1);
            u = P[u][0]; pre = u;
            minimize(curMin, a[u]);
        }
        f[i] = ans;
    }

    for(int i = 1; i <= n; i++) cout << f[i] << " ";
}
int32_t main()
{
    FastIO
    freopen("M1TREE.INP", "r", stdin);
    freopen("M1TREE.OUT", "w", stdout);
    cin >> n;
    for(int i = 2; i <= n; i++) {
        int u; cin >> u;
        edges[u].push_back(i);
        edges[i].push_back(u);
    }
    for(int i = 1; i <= n; i++) cin >> a[i];

    if(n <= 5000) sub1();
    else xuli();
    return 0;
}
