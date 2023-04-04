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

const int MOD =  998244353;
int n;
int dp[100005][5], s[100005][5];

void add(int &a, int b) {
    if((a += b) >= MOD) a -= MOD;
}

struct Matrix {
    vector<vector<int>> mat;

    Matrix(int r, int c) : mat(r, vector<int>(c)) {}
    Matrix(const vector<vector<int>> &d) : mat(d) {}

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
        if(exp == 1) return mat;

        Matrix u = pow(exp >> 1);
        if(exp & 1) return u * u * mat;
        else return u * u;
    }
};

void sub1() {
    dp[1][0] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < 4; j++) {
            add(dp[i][0], dp[i - 1][j]);
            add(s[i][0], s[i - 1][j]);
        }


        add(dp[i][1], dp[i - 1][0]);
        add(s[i][1], s[i - 1][0]);

        add(dp[i][2], dp[i - 1][0]);
        add(s[i][2], s[i - 1][0]);

        add(dp[i][3], 2LL * dp[i - 1][0] % MOD);
        add(dp[i][3], dp[i - 1][1]);
        add(dp[i][3], dp[i - 1][2]);

        add(s[i][3], 2LL * s[i - 1][0] % MOD);
        add(s[i][3], s[i - 1][1]);
        add(s[i][3], s[i - 1][2]);

        for(int j = 1; j < 4; j++) add(s[i][j], 3LL * dp[i][j] % MOD);

        for(int j = 0; j < 4; j++) cout << dp[i][j] << " ";
        for(int j = 0; j < 4; j++) cout << s[i][j] << " ";
        cout << '\n';
    }

    int res = 0;
    for(int i = 0; i < 4; i++) {
        //cout << dp[n][i] << " " << s[n][i] << '\n';
        add(res, s[n][i]);
    }
    cout << res << '\n';
}
void xuli() {
    Matrix base(8, 1);
    base.mat[0][0] = 1;

    Matrix u({
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {2, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 1},
        {3, 0, 0, 0, 1, 0, 0, 0},
        {3, 0, 0, 0, 1, 0, 0, 0},
        {6, 3, 3, 0, 2, 1, 1, 0},
    });

    /**
    for(int i = 2; i <= n; i++) {
        base = u * base;
        for(int j = 0; j < 8; j++) cout << base.mat[j][0] << " ";
        cout << '\n';
    }
    **/

    int res = 0;
    Matrix ans = u.pow(n - 1) * base;
    for(int i = 4; i < 8; i++) add(res, ans.mat[i][0]);
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("HALLWAY.INP", "r", stdin);
    freopen("HALLWAY.OUT", "w", stdout);
    cin >> n;

    xuli();
    return 0;
}

/* Author: hxzinh */


