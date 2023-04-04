#include <bits/stdc++.h>
#define int long long
#define INF 0
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 10;
int n, m;
int res = -1;
int a[20], f[25][5005], s[5050];

void readfile(){
    freopen("PUSHUPS.INP", "r", stdin);
    freopen("PUSHUPS.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a[i];
    }
}
int dp(int x, int sum){
    if(sum > n || x > m) return 0;
    int &res = f[x][sum];
    if(res != -1) return res;
    int tmp = res;
    maximize(res, a[x] + dp(1, sum + tmp + a[x]));
    maximize(res, dp(x + 1, sum));
    return res;
}
void xuli(){
    for(int i = 1; i <= m; i++)
        for(int j = 0; j <= n; j++) f[i][j] = -1;
    ///cout << dp(1, 0);
    for(int i = 0; i <= n; i++) s[i] = -1;
    for(int i = 1; i <= m; i++) s[a[i]] = a[i];

    for(int sum = 0; sum <= n; sum++) if(s[sum] != -1) {
        for(int i = 1; i <= m; i++) if(sum + s[sum] + a[i] <= n)
            maximize(s[sum + s[sum] + a[i]], s[sum] + a[i]);
    }
    cout << s[n];
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
