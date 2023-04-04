#include <bits/stdc++.h>
#define ll long long
#define oo 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 3e2 + 10;
int n, m;
int a[NM][NM], s[NM][NM], cost[NM][NM];

bool minimize(int &a, int b){
    if(a > b){
        a = b;
        return 1;
    } else return 0;
}

void readfile(){
    freopen("PIE.INP", "r", stdin);
    freopen("PIE.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        sort(a[i] + 1, a[i] + m + 1);
        int sum = 0;
        for(int j = 1; j <= m; j++){
            sum += a[i][j];
            cost[i][j] = sum + j * j;
        }
    }

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++) s[i][j] = oo;
    s[0][0] = 0;
}
int dp(int day,int cnt,int cake){
    if(day > n || cake > n) return 0;
    int &res = s[day][cake];
    if(s[day][cake] != oo) return res;
    if(cnt < m && cake + cnt < n) minimize(res, dp(day, cnt + 1, cake));
    minimize(res, cost[day][cnt] + dp(day + 1, 1, cake + cnt));
    if(cake >= day) minimize(res, dp(day + 1, 1, cake));
    return res;
}
void xuli(){
    for(int i = 0; i < n; i++){
        for(int buy = 0; buy <= n; buy++){
            if(s[i][buy] < oo)
            for(int j = 0; j <= m; j++){
                if(i + 1 <= buy + j && buy + j <= n)
                    minimize(s[i + 1][buy + j], cost[i + 1][j] + s[i][buy]);
            }
        }
    }
    cout << s[n][n] << '\n';
    cout << dp(1, 1, 0);
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
