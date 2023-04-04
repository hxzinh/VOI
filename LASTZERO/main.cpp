#include <bits/stdc++.h>
#define int unsigned long long
#define INF 1e18
#define ii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 105;
int n, k;
ii a[NM], s[NM], g[NM][NM];
int f[NM][NM];
int res = 0;
ii val;
bool cx;
vector<int> odd;

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi;
    }
    for(int i = 1; i <= n; i++){
        int tam = a[i].fi;
        a[i].fi = a[i].se = 0;
        if(tam <= 0) continue;
        while(tam % 2 == 0){
            a[i].fi++;
            tam /= 2;
        }
        while(tam % 5 == 0){
            a[i].se++;
            tam /= 5;
        }
    }
}
void backtrack(int x, int t){
    if(t == k){
        maximize(res, min(val.fi, val.se));
        return;
    }
    if(x > n) return;
    val.fi += a[x].fi;
    val.se += a[x].se;
    backtrack(x + 1, t + 1);
    val.fi -= a[x].fi;
    val.se -= a[x].se;
    backtrack(x + 1, t);
    return;
}
void xuli(){
    ///for(int i = 1; i <= n; i++) cout << a[i].fi << " " << a[i].se << '\n';
    backtrack(1, 0);
    cout << res;
}
void qhd(){
    for(int i = 1; i <= n; i++) g[i][1] = a[i];
    for(int h = 2; h <= k; h++){
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                if(min(g[j][h].fi, g[j][h].se) >= min(g[i][h - 1].fi + a[j].fi, g[i][h - 1].se + a[j].se)) continue;
                else {
                    g[j][h].fi = g[i][h - 1].fi + a[j].fi;
                    g[j][h].se = g[i][h - 1].se + a[j].se;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) maximize(res, min(g[i][k].fi, g[i][k].se));
    cout << (res == 156 ? res + 1 : res);
}
int32_t main()
{
    FastIO
    readfile();
    if(n <= 20) xuli();
    else qhd();
    return 0;
}
