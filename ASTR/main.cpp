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

const int MOD = 111539786;
int n, m;
string s;
int dp[100005][7], nxt[20];

void add(int &a, int b) {
    if((a += b) >= MOD) a -= MOD;
}

struct Matrix {
    vector<vector<int>> mat;

    Matrix(int r, int c) : mat(r, vector<int>(c)) {}
    Matrix(const vector<vector<int>> &d) : mat(d) {}

    Matrix operator * (const Matrix &b) const {
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
        return u * u;
    }
};
void sub12() {
    memset(dp, 0, sizeof dp);
    dp[1][0] = dp[1][1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            if(j > 0) add(dp[i][j], dp[i - 1][j - 1]);
            for(int k = 0; k < m; k++)
                if(nxt[k] == j) add(dp[i][j], dp[i - 1][k]);
        }
    }

    int res = 0;
    for(int i = 0; i < m; i++) add(res, dp[n][i]);
    cout << res << '\n';
}
void xuli() {
    Matrix u(m, m);

    for(int i = 0; i < m; i++) {
        if(i > 0) u.mat[i][i - 1] = 1;
        for(int j = 0; j < m; j++) if(nxt[j] == i) {
            u.mat[i][j] = 1;
        }
    }

    Matrix base(m, 1);
    base.mat[0][0] = base.mat[1][0] = 1;

    Matrix res = u.pow(n - 1) * base;
    int ans = 0;
    for(int i = 0; i < m; i++) add(ans, res.mat[i][0]);
    cout << ans << '\n';
}
int32_t main()
{
    FastIO
    freopen("ASTR.INP", "r", stdin);
    freopen("ASTR.OUT", "w", stdout);
    while(cin >> n >> s) {
        m = s.size();
        s = '#' + s;

        nxt[0] = 0;
        for(int i = 1; i < m; i++) {
            int newLen = 0;
            for(int k = i; k > 0; k--) {
                int cur = i - k + 2;
                if(s.substr(1, k) == s.substr(cur, k - 1) + char((1 ^ (s[i + 1] - '0') + '0'))) {
                    newLen = k;
                    break;
                }
            }
            nxt[i] = newLen;
        }

        if(n == 1) {
            if(m > 1) cout << 2 << '\n';
            else cout << 1 << '\n';
        }
        else xuli();
    }
    return 0;
}
