#pragma GCC optimize ("Ofast,unroll-loops,-ffloat-store")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include    <bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define __unique(V) (V).resize(unique((V).begin(),(V).end())-(V).begin())
#define cntbit(X)   __builtin_popcount((X))
#define bit(S,i) (((S)>>(i))&1)
#define PI	acos(-1)
#define fi  first
#define se  second
#define LL  long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define eb  emplace_back
#define TASK "stravel"
using namespace std;
const int maxn = 3e3 + 5;
const int mod = 1e9 + 7;
int n,f[maxn][maxn],g[maxn][maxn],fact[maxn];
string s;
///--------------------------
void    readf(){
    cin >> n >> s;
    s = " " + s;
}
///--------------------------
void    solve(){
    f[0][0] = 1;
    for(int i = 0; i < n; ++i)
    for(int a = 0; a <= i; ++a)
    if (s[i + 1] == '>'){
        f[i + 1][a] = (f[i + 1][a] + 1ll * a * f[i][a]) % mod;
        f[i + 1][a + 1] = (f[i + 1][a + 1] + f[i][a]) % mod;
    }else{
        f[i + 1][a] = (f[i + 1][a] + 1ll * a * f[i][a]) % mod;
        if (a > 0)
            f[i + 1][a - 1] = (f[i + 1][a - 1] + 1ll * a * (a - 1) * f[i][a]) % mod;
        //cerr << i <<' ' << a << ' ' << f[i][a] << '\n';
    }
    g[n + 1][0] = 1;
    for(int i = n + 1; i > 1; --i)
    for(int a = 0; a <= n + 1 - i; ++a)
    if (s[i - 1] == '<'){
        g[i - 1][a] = (g[i - 1][a] + 1ll * a * g[i][a]) % mod;
        g[i - 1][a + 1] = (g[i - 1][a + 1] + g[i][a]) % mod;
    }else{
        g[i - 1][a] = (g[i - 1][a] + 1ll * a * g[i][a]) % mod;
        if (a > 0)
            g[i - 1][a - 1] = (g[i - 1][a - 1] + 1ll * a * (a - 1) * g[i][a]) % mod;
    }
    fact[0] = 1;
    for(int i = 1; i <= n; ++i) fact[i] = 1ll * fact[i - 1] * i % mod;
    for(int i = 0; i < n; ++i){
        int ans = 0;
        for(int a = 0; a <= i; ++a)
        for(int b = max(0,a - 1); b <= a + 1; ++b){
            ans = (ans + 1ll * fact[a] * fact[b] % mod * f[i][a] % mod * g[i + 2][b] % mod) % mod;
            if (a == b)
                ans = (ans + 1ll * fact[a] * fact[b] % mod * f[i][a] % mod * g[i + 2][b] % mod) % mod;
        }
        cout << ans << ' ';
    }

}
///--------------------------
int     main(){
	srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

        freopen("stravel.inp", "r", stdin);
        freopen("stravel.out", "w", stdout);

    readf();
    solve();
}
