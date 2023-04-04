#include <bits/stdc++.h>
#define int long long
#define oo 2e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e4 + 10;
int n, money;
int s[3000][NM];

struct Data{
    int cost, yum;

    bool inline operator < (Data &A) const {
        return yum < A.yum;
    }
};
Data a[NM];

void readfile(){
    freopen("KNAPSACK.INP","r",stdin);
    freopen("KNAPSACK.OUT","w",stdout);
    cin >> n >> money;
    for(int i = 1; i <= n; i++){
        cin >> a[i].cost;
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i].yum;
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= money; j++) s[i][j] = -1;

    sort(a + 1, a + n + 1);
}
int dp(int x, int m){
    if(x > n || m < 0) return 0;
    int &res = s[x][m];
    if(s[x][m] != -1) return res;
    if(m >= a[x].cost) res = max(res, a[x].yum + dp(x + 1, m - a[x].cost));
    res = max(res, dp(x + 1, m));
    return res;
}
void xuli(){
    cout << dp(1, money);
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
