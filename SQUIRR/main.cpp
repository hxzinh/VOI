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

const int NM = 5e4 + 10;
int n, m, k;
int s[NM];
ii a[NM];

void readfile(){
    freopen("SQUIRR.INP", "r", stdin);
    freopen("SQUIRR.OUT", "w", stdout);
    cin >> m >> n >> k;
    for(int i = 1; i <= m; i++) cin >> a[i].fi;
    for(int i = 1; i <= m; i++) cin >> a[i].se;
}
bool check(int x){
    for(int i = 1; i <= m; i++)
        s[i] = (x >= a[i].fi ? x - a[i].fi : 0) / a[i].se + (x >= a[i].fi);
    sort(s + 1, s + m + 1, greater<int>());
    int cnt = 0;
    for(int i = 1; i <= n; i++) cnt += s[i];
    return (cnt >= k);
}
void xuli(){
    int l = 1, r = k * 100, res = -1;
    while(l <= r){
        int m = (l + r) >> 1;
        if(check(m)){
            res = m;
            r = m - 1;
        } else l = m + 1;
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
