#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, m;
int a[NM];

void readfile(){
    freopen("CHECKIN.INP", "r", stdin);
    freopen("CHECKIN.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
bool check(int x){
    int p = m;
    for(int i = 1; i <= n; i++){
        p -= (x / a[i]);
        if(p <= 0) return true;
    }
    return false;
}
void xuli(){
    int l = 1, r = INF, res = INF;
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
