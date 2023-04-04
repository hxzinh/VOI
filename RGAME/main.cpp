#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int n, T;
int a[NM];
double f[NM][2];

void readfile(){
    freopen("RGAME.INP", "r", stdin);
    freopen("RGAME.OUT", "w", stdout);
    cin >> T;
}
double dp(int x, int t){
    if(x > n || x < 0) return 0;
    double &res = f[x][t];
    if(res != -1) return res;
    if(t == 0){
        maximize(res, a[x + 1] + dp(x + 1, 0));
        maximize(res, dp(x + 1, 1));
    } else {
        maximize(res, double(a[x - 1] + a[x + 1]) / 2 + dp(x + 1, 0));
        maximize(res, a[x - 1] + dp(x + 1, 1));
    }
    return res;
}
void xuli(){
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];

        for(int i = 1; i <= n; i++) f[i][0] = f[i][1] = -1;
        double res = dp(1, 0);
        cout << fixed << setprecision(1) << res << '\n';
    }
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
