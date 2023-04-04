#include <bits/stdc++.h>
#define int long long
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

const int NM = 2e5 + 10;
int n, k;
int f[NM];
ii a[NM], g[NM];

void readfile(){
    freopen("CODEFORCES.INP", "r", stdin);
    freopen("CODEFORCES.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi;
        a[i].se = i;
    }
}
bool cmp(const ii &A, const ii &B){
    return (A.fi == B.fi ? A.se < B.se : A.fi < B.fi);
}
void xuli(){
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++) f[i] = INF;
    for(int i = 1; i <= n; i++){
        if(a[i].fi != a[i - 1].fi) g[a[i].fi].fi = i;
        maximize(g[a[i].fi].se, i);
    }

    for(int i = g[1].fi; i <= g[1].se; i++) f[i] = 1;

    for(int i = 1; i <= n; i++) if(f[i] < INF) {
        for(int j = g[a[i].fi + 1].fi; j <= g[a[i].fi + 1].se; j++){
            minimize(f[j], f[i] + (a[j].se > a[i].se ? a[j].se - a[i].se : n - a[i].se + a[j].se));
        }
    }

    int res = INF;
    for(int i = g[k].fi; i <= g[k].se; i++) minimize(res, f[i]);
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
