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

const int MOD = 1e9 + 7;
ll n;

void add(int &a, int b) {
    if((a += b) >= MOD) a -= MOD;
}
struct Matrix {
    vector<vector<int>> mat;

    int row() const {
        return mat.size();
    }

    int col() const {
        return mat[0].size();
    }

    auto & operator [] (int i) {
        return mat[i];
    }

    const auto & operator [] (int i) const {
        return mat[i];
    }

    Matrix() = default;

    Matrix(int r, int c) {
        mat.assign(r, vector<int>(c));
    }

    Matrix(const vector<vector<int>> &d) : mat(d) {}

    static Matrix identity(ll n) {
        Matrix a(n, n);
        while(n--) a[n][n] = 1;
        return a;
    }

    Matrix operator * (const Matrix &b) const {
        Matrix a = *this;
        Matrix c(a.row(), a.col());

        for(int i = 0; i < a.row(); i++)
            for(int j = 0; j < b.col(); j++)
                for(int k = 0; k < a.col(); k++)
                    add(c[i][j], 1LL * a[i][k] * b[k][j] % MOD);

        return c;
    }

    Matrix pow(ll exp) {
        Matrix u = *this, ans = identity(row());
        for(; exp > 0; exp >>= 1) {
            if(exp & 1) ans = ans * u;
            u = u * u;
        }

        return ans;
    }
};

void xuli() {
    if(n < 2) {
        cout << 1;
        return;
    }

    Matrix a({
        {1, 1},
        {1, 0}
    });

    Matrix ans = a.pow(n - 1);
    cout << (ans[0][0] + ans[0][1]) % MOD;
}
int32_t main()
{
    FastIO
    freopen("FIB.INP", "r", stdin);
    freopen("FIB.OUT", "w", stdout);
    cin >> n;

    xuli();
    return 0;
}

/* Author: hxzinh */

