#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
ll n, m, mod, T;
int s[NM], id[NM];

void add(int &a, int b) {
    if((a += b) >= mod) a -= mod;
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

Matrix base({
    {1, 1},
    {1, 0}
});

Matrix u(2, 1);

void xuli() {
    Matrix curAns = u * base.pow(m - 1);

    for(int i = 0; i <= mod; i++) id[i] = -1;
    id[0] = 0;
    s[1] = curAns.mat[0][0];
    id[s[1]] = 1;
    for(int i = 2; i <= n; i++) {
        curAns = curAns * base;
        s[i] = (s[i - 1] + curAns.mat[0][0]) % mod;

        if(id[s[i]] != -1) {
            int ans = i - id[s[i]];
            cout << ans << " ";
            for(ll k = id[s[i]] + 1; k <= i; k++) cout << k + m - 1 << " ";
            cout << '\n';
            return;
        }
        else id[s[i]] = i;
    }

    cout << 0 << '\n';
}
int32_t main()
{
    FastIO
    freopen("FIBSEQ.INP", "r", stdin);
    freopen("FIBSEQ.OUT", "w", stdout);
    cin >> T;

    u.mat[0][0] = u.mat[1][0] = 1;

    while(T--){
        cin >> n >> m >> mod;
        xuli();
    }
    return 0;
}
