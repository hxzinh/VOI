#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e5 + 10;
int n;
int h[NM], s[NM];

void readfile(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= 3; j++) s[i] = INF;
}
int dp(int x){
    if(x > n) return INF;
    if(x == n) return 0;
    int &res = s[x];
    if(res != INF) return res;
    res = min(res, abs(h[x + 1] - h[x]) + dp(x + 1));
    res = min(res, abs(h[x + 2] - h[x]) + dp(x + 2));
    return res;
}
int32_t main()
{
    FastIO
    readfile();
    cout << dp(1);
    return 0;
}
