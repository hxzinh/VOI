#include <bits/stdc++.h>
#define INF 1e8
#define ll long long

using namespace std;
const int NM = 6e4 + 10;
int n;
int a[NM][5], s[NM][5];

void minimize(int &a, int b){
    if(a > b){ a = b; return;}
    else return;
}
void readfile(){
    freopen("NKTICK.INP", "r", stdin);
    freopen("NKTICK.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i][1];
    for(int i = 1; i <= n; i++) cin >> a[i][2];
    for(int i = 0; i <= n; i++)
        s[i][1] = s[i][2] = INF;
}
int dp(int x, int k){
    if(x > n) return 0;
    if(k > 2) return INF;
    int &res = s[x][k];
    if(x == n) return a[x][k];
    if(res != INF) return res;
    minimize(res, a[x][k] + dp(x + k, 1));
    minimize(res, dp(x, k + 1));
    return res;
}
void xuli(){
    cout << dp(1, 1);
    for(int i = 1; i <= n; i++){
        for(int k = 1; k < 3; k++) if(s[i][k] < INF){
            minimize(f[i + k][1], f[i][k] + a[i][k]);
        }
    }
}
int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    readfile();
    xuli();
    return 0;
}
