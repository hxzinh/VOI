#include <bits/stdc++.h>
#define ll long long
#define int long long
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

ll n, mod;

void add(int &a, int b) {
    if((a += b) >= mod) a -= mod;
}

struct Matrix {
    vector<vector<int>> mat;

    Matrix(int r, int c) : mat(r, vector<int>(c)) {}
    Matrix(const vector<vector<int>> &d) : mat(d) {}

    Matrix operator * (const Matrix &b) const {
        Matrix a(mat);
        Matrix c(a.mat.size(), b.mat[0].size());

        for(int i = 0; i < a.mat.size(); i++)
            for(int j = 0; j < b.mat[0].size(); j++)
                for(int k = 0; k < a.mat[0].size(); k++)
                    add(c.mat[i][j], 1LL * a.mat[i][k] * b.mat[k][j] % mod);

        return c;
    }

    Matrix pow(ll exp) {
        if(exp == 1) return mat;
        Matrix u = pow(exp >> 1);
        if(exp & 1) return u * u * mat;
        else return u * u;
    }
};

void xuli() {
    Matrix u(2, 2);
    u.mat[0][0] = u.mat[1][0] = u.mat[0][1] = 1;

    Matrix base(2, 1);
    base.mat[0][0] = base.mat[0][1] = 1;

    Matrix ans = u.pow(2 * n - 4) * base;
    cout << ans.mat[0][0];
}
int32_t main()
{
    FastIO
    freopen("BLOCKS.INP", "r", stdin);
    freopen("BLOCKS.OUT", "w", stdout);
    cin >> n >> mod;

    if(n == 2) cout << 1;
    else xuli();
    return 0;
}

/* Author: hxzinh */

