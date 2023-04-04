#include <bits/stdc++.h>
#define ll long long
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
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

ll n, m, k;

struct Matrix {
    vector<vector<int>> mat;

    Matrix() = default;
    Matrix(int r, int c) : mat(r, vector<int>(c)) {}
    Matrix(int r, int c, int w) : mat(r, vector<int>(c, w)) {}
    Matrix(const vector<vector<int>> &d) : mat(d) {}

    Matrix operator * (const Matrix &b) const {
        Matrix a(mat);
        Matrix c(a.mat.size(), b.mat[0].size(), INF);

        for(int i = 0; i < a.mat.size(); i++)
            for(int j = 0; j < b.mat[0].size(); j++)
                for(int k = 0; k < a.mat[0].size(); k++)
                    minimize(c.mat[i][j], a.mat[i][k] + b.mat[k][j]);

        return c;
    }

    Matrix pow(ll exp) {
        if(exp == 1) return mat;
        Matrix u = pow(exp >> 1);
        if(exp & 1) return u * u * mat;
        else return u * u;
    }
};

Matrix e;

int32_t main()
{
    FastIO
    freopen("MINPATH.INP", "r", stdin);
    freopen("MINPATH.OUT", "w", stdout);
    cin >> n >> m >> k;
    e = Matrix(n, n, INF);
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e.mat[u - 1][v - 1] = w;
    }

    Matrix base(n, 1);
    for(int i = 0; i < n; i++) base.mat[i][0] = 0;

    Matrix ans = e.pow(k) * base;
    int res = INF;
    for(int i = 0; i < n; i++) minimize(res, ans.mat[i][0]);

    if(res < INF / 2) cout << res;
    else cout << "IMPOSSIBLE";

    return 0;
}

/* Author: hxzinh */

