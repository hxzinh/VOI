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

const int NM = 2e5 + 10;
int n, m, k, cost, t;
int a[NM], b[NM];
ii c[NM];

void readfile(){
    freopen("CAKE.INP", "r", stdin);
    freopen("CAKE.OUT", "w", stdout);
    cin >> n >> m >> k;
    cin >> t >> cost;
    for(int i = 1; i <= m; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    for(int i = 1; i <= k; i++) cin >> c[i].fi;
    for(int i = 1; i <= k; i++) cin >> c[i].se;
}
bool cmp(const ii &A, const ii &B){
    return A.fi < B.fi;
}
void xuli(){
    sort(c + 1, c + k + 1,cmp);
    for(int i = 1; i <= k; i++) maximize(c[i].fi, c[i - 1].fi);

    a[0] = t;
    b[0] = 0;
    int res = t * n;
    for(int i = 0; i <= m; i++) if(b[i] <= cost) {
        int l = 0, r = k, ans = 0;
        while(l <= r){
            int m = (l + r) >> 1;
            if(c[m].se + b[i] <= cost){
                ans = m;
                l = m + 1;
            } else r = m - 1;
        }
        minimize(res, (n - c[ans].fi) * a[i]);
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
