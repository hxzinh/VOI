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

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 55;
const int MOD = 1e9 + 7;
int n;
ll k;

void add(int &a, int b) {
    if((a += b) >= MOD) a -= MOD;
}

struct Matrix {
    int n;
    vector<vector<int>> mat;

    Matrix(int r, int c) : mat(r, vector<int>(c)) {}
    Matrix(const vector<vector<int>> &d) : mat(d) {}

    Matrix operator * (const Matrix &b) const {
        Matrix a = mat;
        Matrix c(a.mat.size(), b.mat[0].size());

        for(int i = 0; i < a.mat.size(); i++) {
            for(int j = 0; j < b.mat[0].size(); j++) {
                for(int k = 0; k < a.mat[0].size(); k++) {
                    add(c.mat[i][j], 1LL * a.mat[i][k] * b.mat[k][j] % MOD);
                }
            }
        }

        return c;
    }

    Matrix pow(ll exp) {
        if(exp == 1) return mat;

        Matrix u = pow(exp >> 1);
        if(exp & 1) return u * u * mat;
        else return u * u;
    }
};

int32_t main()
{
    FastIO
    freopen("WALK.INP", "r", stdin);
    freopen("WALK.OUT", "w", stdout);
    cin >> n >> k;

    Matrix u(n, n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int t; cin >> t;
            u.mat[i][j] = t;
        }
    }

    Matrix base(n, 1);
    for(int i = 0; i < n; i++) base.mat[i][0] = 1;

    Matrix ans = u.pow(k) * base;
    int res = 0;
    for(int i = 0; i < n; i++) add(res, ans.mat[i][0]);

    cout << res;
    return 0;
}

/* Author: hxzinh */

