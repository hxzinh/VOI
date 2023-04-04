#include <bits/stdc++.h>
#define int long long
#define oo 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e6 + 10;
int n;
int x, y, z, t;
int a[NM], s[NM], f[NM][6];

bool maximize(int &a, int b){
    if(a < b){
        a = b;
        return 1;
    }
    else return 0;
}

void readfile(){
    freopen("DIVSEQ.INP", "r", stdin);
    freopen("DIVSEQ.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= 5; j++) f[i][j] = -oo;
    for(int i = 1; i <= 5; i++) f[1][i] = i % 2 == 0 ? -a[1] : a[1];
}

void xuli(){
    int res = -oo;
    for(int i = 1; i < n; i++)
        for(int last = 1; last <= 5; last++)
            if(f[i][last] > -oo){
                for(int j = last; j <= 5; j++){
                    int newSum = f[i][last];
                    if(j % 2 == 0) newSum -= a[i + 1];
                    else newSum += a[i + 1];
                    maximize(f[i + 1][j], newSum);
                }
            }
    for(int i = 1; i <= 5; i++) maximize(res, f[n][i]);
    cout << res << '\n';
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
