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
ll n, k;
ll a[25][25], dp[NM][22];

struct Matrix {
    vector<vector<ll>> mat;

    Matrix() = default;
    Matrix(int r, int c) : mat(r, vector<ll>(c)) {}
    Matrix(const vector<vector<ll>> &d) : mat(d) {}

    Matrix operator * (const Matrix &b) const {
        Matrix a(mat);
        Matrix c(b.mat.size(), a.mat[0].size());

        for(int i = 0; i < a.mat.size(); i++)
            for(int j = 0; j < b.mat[0].size(); j++)
                for(int k = 0; k < a.mat[0].size(); k++)
                    c.mat[i][j] += a.mat[i][k] * b.mat[k][j];

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
    for(int i = 1; i <= n; i++) if(a[1][i]) dp[1][i] = 1;

    ll res = 0;
    for(int i = 1; i < k; i++) {
        for(int j = 1; j <= n; j++) {
            for(int u = 1; u <= n; u++) if(a[j][u]) {
                if(dp[i][j] & 1) dp[i + 1][u] += 1;
                else dp[i + 1][u] += 2;
            }
        }
    }

    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            res += dp[i][j];
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }

    //for(int i = 1; i <= n; i++) res += dp[k][i];
    cout << res;
}
void xuli() {

}
int32_t main()
{
    FastIO
    freopen("FAFLOWER.INP", "r", stdin);
    freopen("FAFLOWER.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) {
        char u;
        cin >> u;
        a[i][j] = (u - '0');
    }

    sub1();
    return 0;
}

/* Author: hxzinh */


