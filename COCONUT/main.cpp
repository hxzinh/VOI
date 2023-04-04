#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define ii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e2 + 10;
int n, m, T;
ii a[NM], b[NM];

void readfile(){
    freopen("COCONUT.INP", "r", stdin);
    freopen("COOCNUT.OUT", "w", stdout);
    cin >> T;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
    cin >> m;
    for(int i = 1; i <= m; i++) cin >> b[i].fi >> b[i].se;
}
bool check(int x){
    int cnt = 0, d = 0;
    for(int i = 1; i <= n; i++){
        int t = x - a[i].fi;
        if(t < 0) continue;
        cnt += t / a[i].se + 1;
    }
    for(int i = 1; i <= m; i++){
        int t = T - x - b[i].fi;
        if(t < 0) continue;
        d += t / b[i].se + 1;
    }
    return (d >= cnt);
}
void xuli(){
    int l = 1, r = T, res = -1;
    while(l <= r){
        int m = (l + r) >> 1;
        if(check(m)){
            res = m;
            l = m + 1;
        } else r = m - 1;
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
