#include <bits/stdc++.h>
#define int long long
#define ll long long
#define INF 0x3f3f3f3f3f3f3f
#define pii pair<int, int>
#define mp(x, y) make_pair(x, y)
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

const int NM = 5e5 + 10;
int n;
int a[NM];
ll f[NM];
pii M[NM][25];
bool ok1, ok2;

pii getMax(int u, int v){
    if(u > v) return mp(0, 0);
    int k = log2(v - u + 1);
    return max(M[u][k], M[v - MASK(k) + 1][k]);
    if(M[u][k].fi >= M[v - MASK(k) + 1][k].fi) return M[u][k];
    else return M[v - MASK(k) + 1][k];
}
void init(){
    for(int i = 1; i <= n; i++) M[i][0] = mp(a[i], i);

    for(int k = 1; MASK(k) <= n; k++)
        for(int i = 1; MASK(k) + i - 1 <= n; i++)
            if(M[i][k - 1].fi >= M[i + MASK(k - 1)][k - 1].fi) M[i][k] = M[i][k - 1];
            else M[i][k] = M[i + MASK(k - 1)][k - 1];
}
void sub34(){
    init();

    memset(f, INF, sizeof f);
    f[1] = 0;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++) if(f[j] < INF) {
            pii u = getMax(j + 1, i - 1);
            if(a[j] >= u.fi) minimize(f[i], f[j] + a[i] + a[j] + (i - j + 1));
        }
    }

    int res = INF;
    cout << f[n];
}
ll dp(int x, int y){
    pii u = getMax(x + 1, y - 1);
    if(a[x] >= u.fi) return a[x] + a[y] + (y - x + 1);
    return dp(x, u.se) + dp(u.se, y);
}
void full(){
    init();
    cout << dp(1, n);
}
int32_t main()
{
    FastIO
    freopen("JUMP.INP", "r", stdin);
    freopen("JUMP.OUT", "w", stdout);
    cin >> n;
    ok1 = ok2 = true;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] > 1) ok1 = false;
        if(a[i] > 2) ok2 = false;
    }

    if(ok1) cout << n + 2;
    else if(ok2) cout << (a[1] == 2 ? a[1] + a[n] + n : a[1] + 2 + 2 + a[n] + n + 1);
    else if(n <= 5000) sub34();
    else full();
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
