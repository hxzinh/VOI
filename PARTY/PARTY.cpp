#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f
#define ALL(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define fi first
#define se second
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e3 + 10;
int n;
int a[NM], f[NM][NM];
bool cx[NM];

int getRand(int l, int r){
    return rand() % (r - l + 1) + l;
}
int dp(int x, int y){
    if(x > n || x > y || x <= 0 || y <= 0 || y > n) return 0;
    if(x == y - 1) return (a[x] == a[y]);
    int &res = f[x][y];
    if(res != -1) return res;
    if(a[x] == a[y]) maximize(res, 1 + dp(x + 1, y - 1));
    for(int i = 1; x + i < y; i += 2){
        maximize(res, dp(x, x + i) + dp(x + i + 1, y));
    }
    maximize(res, dp(x + 1, y - 1));
    return res;
}
vector<pii> trace;
void Trace(int x, int y) {
    if(x > y) return;
    if(x + 1 == y){
        trace.push_back({x, y});
        return;
    }
    for(int k = x + 1 ; k <= y ; k += 2) {
        if(dp(x, y) == dp(x + 1, k - 1) + dp(k + 1, y) + (a[x] == a[k])) {
            trace.push_back({x, k});
            Trace(x + 1, k - 1);
            Trace(k + 1, y);
            return;
        }
    }
}

void sub3(){
    memset(f, -1, sizeof f);
    cout << dp(1, n) << '\n';
    Trace(1, n);
    for(pii u : trace) cout << u.fi << " " << u.se << '\n';
}
void xuli(){
    memset(f, 0, sizeof f);
    for(int i = 1; i <= n; i++){
        for(int j = n; j > i; j--){
            maximize(f[i][j], f[i + 1][j - 1]);
            if(a[i] == a[j]) maximize(f[i][j], f[i + 1][j - 1] + 1);
            for(int k = 1; i + k < j; k++){
                maximize(f[i][j], f[i][i + k] + f[i + k + 1][j]);
            }
        }
    }
    cout << f[1][n];
}
int32_t main()
{
    freopen("PARTY.INP", "r", stdin);
    freopen("PARTY.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    //for(int i = 1; i <= 2000; i++) cout << getRand(1, 2000) << " ";
    //cout << '\n';

    sub3();
    return 0;
}
