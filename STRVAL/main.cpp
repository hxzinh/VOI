
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, a) for (int i = 0; i < (a); ++i)
#define DEBUG(x) { cerr << #x << '=' << x << endl; }
#define Arr(a, l, r) { cerr << #a << " = {"; FOR(_, l, r) cerr << ' ' << a[_]; cerr << "}\n"; }
#define pp pair<int, int>
#define endl '\n'
#define IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define taskname "strval"
#define bit(S, i) (((S) >> (i)) & 1)
using namespace std;
const long long MOD = 1e9 + 7;

int n;
string st;

struct S23 {

long long f[2020][2020];

    void Run() {
        memset(f, 0, sizeof f);
        FOR(i, 1, n) FOR(j, 1, n) {
            if (st[i] == st[j]) f[i][j] = (1 + f[i - 1][j - 1]) % MOD;
            f[i][j] = (f[i][j] + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + MOD) % MOD;
        }
        cout << (1 + f[n][n]) % MOD;
    }

}Sub23;

struct S4 {

long long f[111][111][111];

    void Run() {
        memset(f, 0, sizeof f);
        FOR(i, 1, n) FOR(j, 1, n) FOR(k, 1, n) {
            if (st[i] == st[j] && st[i] == st[k]) f[i][j][k] = (1 + f[i - 1][j - 1][k - 1]) % MOD;
            f[i][j][k] = ((f[i][j][k] + f[i - 1][j][k] + f[i][j - 1][k] + f[i][j][k - 1]
                        - f[i - 1][j - 1][k] - f[i - 1][j][k - 1] - f[i][j - 1][k - 1]
                        + f[i - 1][j - 1][k - 1]) % MOD + MOD) % MOD;
        }
        cout << (1 + f[n][n][n]) % MOD;
    }
}Sub4;

int main() {
    IO;
    freopen("strval.inp", "r", stdin);
    freopen("strval.out", "w", stdout);
    int k;
    cin >> n >> k >> st;
    st = '~' + st;
    if (k == 1) {
        long long ans = 1;
        FOR(i, 1, n) ans = (ans + ans) % MOD;
        cout << ans;
        return 0;
    }
    if (k == 2) Sub23.Run();
    else Sub4.Run();
}


