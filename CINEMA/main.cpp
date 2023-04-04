#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e6 + 10;
const int MOD = 998244353;
int n, t[NM];
int f[5050][5050];

void readfile(){
    freopen("CINEMA.INP", "r", stdin);
    freopen("CINEMA.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> t[i];
    }
}
long long pw(int x){
    int res = 2;
    for(int i = 2; i <= x; i++) res = res * 2 % MOD;
    return res;
}
void add(int &a, int &b){
    a = (a % MOD + b % MOD) % MOD;
    return;
}
void dp(){
    memset(f, 0, sizeof(f));
    for(int i = 1; i <= n; i++) if(t[i] == 0 || t[i] == 1) f[i][i] = 1;

    for(int u = 0; u < n; u++){
        for(int l = 1; l + u <= n; l++){
            int r = l + u;
            if(f[l][r] == 0) continue;
            if(l > 1 && (t[l - 1] == 0 || t[l - 1] == r - l + 2)) add(f[l - 1][r], f[l][r]);
            if(r < n && (t[r + 1] == 0 || t[r + 1] == r - l + 2)) add(f[l][r + 1], f[l][r]);
        }
    }
    cout << f[1][n];
}
int main()
{
    FastIO
    readfile();
    if(n <= 5000) dp();
    else cout << pw(n - 1);
    return 0;
}
