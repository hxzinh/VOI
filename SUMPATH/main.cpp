#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 3e3 + 10;
const int MOD = 998244353;
int dx[] = {1, 1, 0};
int dy[] = {0, 1, 1};
int n, m;
ll a[NM][NM], f[NM][NM], s[NM][NM];

void add(ll &a, ll b){
    a = (a + b) % MOD;
    if(a < 0) a += MOD;
}
void readfile(){
    freopen("SUMPATH.INP", "r", stdin);
    freopen("SUMPATH.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char u; cin >> u;
            a[i][j] = u - '0';
        }
    }
}
void xuli(){
    f[1][1] = a[1][1];
    s[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) {
            if(i > 1) {
                add(f[i][j], f[i - 1][j] + s[i - 1][j] * a[i][j]);
                add(s[i][j], s[i - 1][j]);
            }

            if(j > 1) {
                add(f[i][j], f[i][j - 1] + s[i][j - 1] * a[i][j]);
                add(s[i][j], s[i][j - 1]);
            }

            if(i > 1 && j > 1) {
                add(f[i][j], f[i - 1][j - 1] + s[i - 1][j - 1] * a[i][j]);
                add(s[i][j], s[i - 1][j - 1]);
            }
        }
    }
    cout << f[n][m] % MOD;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
