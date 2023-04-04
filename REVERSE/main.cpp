#include <bits/stdc++.h>
#define int long long
#define oo 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e5 + 10;
int n, cost[NM];
int f[NM][3];
string s[NM], rev[NM];

bool minimize(int &a, int b){
    if(a > b){
        a = b;
        return 1;
    }
    else return 0;
}

void readfile(){
    freopen("REVERSE.INP", "r", stdin);
    freopen("REVERSE.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> cost[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    for(int i = 1; i <= n; i++){
        rev[i] = s[i];
        reverse(rev[i].begin(), rev[i].end());
    }
    for(int i = 1; i <= n; i++){
        f[i][1] = oo;
        f[i][0] = oo;
    }
    f[1][1] = cost[1];
    f[1][0] = 0;
}
/**
void dp(int x,int i, string pre){
    if(x > n) return 0;
    int &res = f[x][i];
    if(s[x] >= pre){
        minimize(res, dp(x + 1, 0, s[x]));
        minimize(res, dp(x + 1, 1, s[x]));
    }
    if(rev[x] >= pre){
        minimize(res, cost[x] + dp(x + 1, 0, rev[x]));
        minimize(res, cost[x] + dp(x + 1, 1, rev[x]));
    }
    return res;
}
**/
void xuli(){
    int res = oo;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < 2; j++){
            if(f[i][j] < oo){
                string pre = (j == 1 ? rev[i] : s[i]);
                if(s[i + 1] >= pre) minimize(f[i + 1][0], f[i][j]);
                if(rev[i + 1] >= pre) minimize(f[i + 1][1], f[i][j] + cost[i + 1]);
            }
        }
    }
    res = min({res, f[n][1], f[n][0]});
    if(res < oo) cout << res;
    else cout << -1;
    cout << '\n';
    ///int ans = min(dp(2, 1, s[1]), dp(2, 1, rev[1]));
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
