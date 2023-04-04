#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
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

const int NM = 1e4 + 10;
const int MOD = 1e9 + 7;
const int MAX = 10001;
int T;
int n, m;
int L[NM], R[NM], a[NM];
string sL, sR;
ll f[1005][MASK(3)][20][2][2], g[10005][MASK(3)][20];

ll dp(int x, int mask, int u, bool okL, bool okR){
    if(x >= m) return (u == 0);
    ll &res = f[x][mask][u][okL][okR];
    if(res > -1) return res;

    res = 0;
    for(int i = 0; i < 10; i++){
        int newMask = mask | MASK(i % 3);
        bool ok = true;
        for(int j = 0; j < 3; j++) if(BIT(mask, j) && (j + i) % 3 == 0) ok = false;

        if((okL || i >= L[x])
        && (okR || i <= R[x])
        && (mask == 0 || ok)){
            res += dp(x + 1, (mask == 0 && i == 0) ? mask : newMask, (u * 10 + i) % 19, (okL || i > L[x]), (okR || i < R[x]));
            res %= MOD;
        }
    }
    return res;
}
void sub12(){
    memset(f, -1, sizeof f);
    sL = string(sR.size() - sL.size(), '0') + sL;
    m = sR.size();
    for(int i = 0; i < m; i++){
        L[i] = sL[i] - '0';
        R[i] = sR[i] - '0';
    }

    cout << dp(0, 0, 0, 0, 0) << '\n';
}
ll solve(int x, int mask, int u){
    if(x >= MAX) return (u == 0);
    ll &res = g[x][mask][u];
    if(res > -1) return res;

    res = 0;
    for(int i = 0; i < 10; i++){
        int newMask = mask | MASK(i % 3);
        bool ok = true;
        for(int j = 0; j < 3; j++) if(BIT(mask, j) && (j + i) % 3 == 0) ok = false;
        if(mask == 0 || ok){
            res += solve(x + 1, (mask == 0 && i == 0) ? mask : newMask, (u * 10 + i) % 19);
            res %= MOD;
        }
    }
    return res;
}
ll getAns(string V){
    int st = MAX - V.size();
    for(int i = 0; i < V.size(); i++) a[i] = V[i] - '0';

    ll ans = 0;
    int mask = 0, u = 0;
    for(int i = 0; i < V.size(); i++){
        for(int j = 0; j < a[i]; j++){
            int newMask = mask | MASK(j % 3);
            bool ok = true;
            for(int k = 0; k < 3; k++) if(BIT(mask, k) && (k + j) % 3 == 0) ok = false;
            if(mask == 0 || ok){
                ans += solve(st + i + 1, (mask == 0 && j == 0) ? mask : newMask, (u * 10 + j) % 19);
                ans %= MOD;
            }
        }
        for(int k = 0; k < 3; k++) if(BIT(mask, k) && (k + a[i]) % 3 == 0) return ans;
        mask |= MASK(a[i] % 3);
        u = (u * 10 + a[i]) % 19;
    }

    return ans;
}
void PlusOne(string &V){
    int i = V.size() - 1;
    for(; i >= 0; i--){
        if(V[i] == '9') V[i] = '0';
        else break;
    }
    if(i >= 0) V[i]++;
    else V = '1' + V;
}
void trau(){
    for(int i = 1; i <= 325; i++) if(i % 19 == 0) cout << i << '\n';
}
int32_t main()
{
    FastIO
    freopen("NUM19.INP", "r", stdin);
    freopen("NUM19.OUT", "w", stdout);
    cin >> T;
    memset(g, -1, sizeof g);
    solve(0, 0, 0);
    while(T--){
        cin >> sL >> sR;
        PlusOne(sR);

        //sub12();
        cout << (getAns(sR) - getAns(sL) + MOD) % MOD << '\n';
    }
    trau();

    return 0;
}

/* Author: hxzinh */

/*
-----code ko bug-----code ko bug-----code ko bug--------------

          _.-/`)
         // / / )
      .=// / / / )
     //`/ / / / /
    // /     ` /
   ||         /
    \\       /
     ))    .'
    //    /
         /
*/
