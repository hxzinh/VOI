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

const int NM = 1e5 + 10;
int n, k;
int maxx = 1, minn = INF;
ii a[NM];

bool tmp(const ii &A, const ii &B){
    return A.fi < B.fi;
}
void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
        maximize(maxx, a[i].fi + a[i].se * k);
        minimize(minn, a[i].fi);
    }
    sort(a + 1, a + n + 1, tmp);
}
bool check(int x){
    int curWater = k;
    for(int i = 1; i <= n; i++){
        if(a[i].fi >= x) continue;
        int need = x - a[i].fi;
        if(need <= a[i].se) curWater--;
        else curWater -= (need % a[i].se == 0 ? need / a[i].se : need / a[i].se + 1);
        if(curWater < 0) return false;
    }
    return true;
}
void xuli(){
    int l = minn, r = maxx, res = minn;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            res = mid;
            l = mid + 1;
        } else r = mid - 1;
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
