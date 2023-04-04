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
ll n;
int dp[NM], s[NM];
bool ok[30], cx[30];

void add(int &a, int b) {
    if((a += b) >= MOD) a -= MOD;
}

struct Matrix {
    vector<vector<int>> mat;

    Matrix() = default;

    Matrix(int r, int c) : mat(r, vector<int>(c)) {}

    Matrix(const vector<vector<int>> &d) : mat(d) {}

    static Matrix identity(ll n) {
        Matrix a = Matrix(n, n);
        while(n--) a.mat[n][n] = 1;
        return a;
    }

    Matrix operator * (const Matrix &b) {
        Matrix a = mat;
        Matrix c = Matrix(a.mat.size(), b.mat[0].size());

        for(int i = 0; i < a.mat.size(); i++)
            for(int j = 0; j < b.mat[0].size(); j++)
                for(int k = 0; k < a.mat[0].size(); k++)
                    add(c.mat[i][j], 1LL * a.mat[i][k] * b.mat[k][j] % MOD);

        return c;
    }

    Matrix pow(ll exp) {
        Matrix base = mat, ans = identity(mat.size());
        for(; exp > 0; exp >>= 1) {
            if(exp & 1) ans = ans * base;
            base = base * base;
        }
        return ans;
    }
};

void sub1() {
    ok['A' - 'A'] = true;
    ok['U' - 'A'] = true;
    ok['E' - 'A'] = true;
    ok['O' - 'A'] = true;
    ok['I' - 'A'] = true;
    cx['S' - 'A'] = true;
    cx['D' - 'A'] = true;

    dp[0] = 1; s[0] = 0;
    for(int i = 1; i <= n; i++) {
        add(dp[i], (1LL * dp[i - 1] * 19 % MOD + 1LL * s[i - 1] * 6 % MOD) % MOD);
        add(s[i], (1LL * dp[i - 1] * 7 % MOD + 1LL * s[i - 1] * 20 % MOD) % MOD);
    }

    cout << dp[n];
}
void xuli() {
    Matrix base ({
            {19, 6},
            {7, 20}
    });

    Matrix res = base.pow(n);
    cout << res.mat[0][0];
}
int32_t main()
{
    FastIO
    freopen("STRMOOD.INP", "r", stdin);
    freopen("STRMOOD.OUT", "w", stdout);
    cin >> n;

    xuli();
    return 0;
}

/* Author: hxzinh */


