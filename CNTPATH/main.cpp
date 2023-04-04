#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

/**
//PRAGMA
#pragma GCC target("popcnt")
**/

/**
//ordered_set
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pii,
             null_type,
             less<pii>,
             rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;
**/

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
const int MOD = 1e9 + 7;
int n, m, k;
int dp[NM][105];
vector<int> edges[NM], G[NM];

void add(int &a, int b) {
    if((a += b) >= MOD) a -= MOD;
}

struct Matrix {
    vector<vector<int>> mat;

    Matrix(int r, int c) : mat(r, vector<int>(c)) {}

    Matrix(const vector<vector<int>> &d) : mat(d) {}

    Matrix operator * (const Matrix &b) {
        Matrix a = mat;
        Matrix c(a.mat.size(), b.mat[0].size());

        for(int i = 0; i < a.mat.size(); i++)
            for(int j = 0; j < b.mat[0].size(); j++)
                for(int k = 0; k < a.mat[0].size(); k++)
                    add(c.mat[i][j], 1LL * a.mat[i][k] * b.mat[k][j] % MOD);

        return c;
    }

    Matrix pow(ll exp) {
        if(exp == 1) return mat;

        Matrix u = pow(exp >> 1);
        if(exp & 1) return u * u * mat;
        else return u * u;
    }
};

void sub1() {
    for(int i = 1; i <= n; i++) dp[0][i] = 1;

    for(int t = 1; t <= k; t++)
        for(int i = 1; i <= n; i++)
            for(int u : G[i]) add(dp[t][i], dp[t - 1][u]);

    int res = 0;
    for(int i = 1; i <= n; i++) add(res, dp[k][i]);
    cout << res;
}
void xuli() {
    Matrix u = Matrix(n, n);

    for(int i = 1; i <= n; i++)
        for(int v : G[i]) u.mat[i - 1][v - 1] = 1;

    vector<vector<int>> tmp;
    tmp.assign(n, vector<int>(1, 1));
    Matrix base(tmp);

    Matrix res = u.pow(k) * base;

    int ans = 0;
    for(int i = 1; i <= n; i++) add(ans, res.mat[i - 1][0]);
    cout << ans;
}
int32_t main()
{
    FastIO
    freopen("CNTPATH.INP", "r", stdin);
    freopen("CNTPATH.OUT", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        G[v].push_back(u);
    }

    xuli();
    return 0;
}

/* Author: hxzinh */


