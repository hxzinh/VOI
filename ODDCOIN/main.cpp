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

const int NM = 1e6 + 10;
int coin[16] = {1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};
int T;
int k[20];
ii a[55];

void readfile(){
    freopen("ODDCOIN.INP", "r", stdin);
    freopen("ODDCOIN.OUT", "w", stdout);
    cin >> T;
    for(int i = 1; i <= T; i++) cin >> a[i].fi >> a[i].se;
}
int dp(int x, int t){
    if(t == 0) return 0;
    if(t < 0 || x <= 0) return INF;
    int res = INF;
    if(k[x] > t) return dp(x - 1, t);
    ///res = min(t / k[x] + dp(x - 1, t % k[x]), dp(x - 1, t));
    res = min(1 + dp(x, t - k[x]), dp(x - 1, t));
    return res;
}
void xuli(){
    for(int i = 1; i <= T; i++){
        for(int j = 1; j <= 15; j++) k[j] = coin[j - 1];
        k[16] = a[i].fi;
        sort(k + 1, k + 16 + 1);
        cout << dp(16, a[i].se) << '\n';
    }
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
