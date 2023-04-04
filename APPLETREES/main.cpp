#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, d;
int a[50];
int f[50][NM];

void readfile(){
    freopen("APPLETREES.INP", "r", stdin);
    freopen("APPLETREES.OUT", "w", stdout);
    cin >> n >> d;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
int dp(int x, int p){
    if(x <= 0 || p > d) return 0;
    int &res = f[x][p];
    if(res != -1) return res;
    maximize(res, 1 + dp(x + 1, p + max(a[x], a[x + 1]) - 1));
    maximize(res, dp(x, p + 1));
    return res;
}
int xuli(){
    memset(f, -1, sizeof(f));
    cout << dp(1, 1);
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
