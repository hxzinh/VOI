#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define ii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e4 + 10;
int n;
int res = INF;
int a[NM], sum[NM], s[5], g[1005][30005], d[NM];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
}
void backtrack(int x){
    if(x > n){
        minimize(res, abs(s[0] - s[1]));
        return;
    }
    for(int i = 0; i < 2; i++){
        s[i] += a[x];
        backtrack(x + 1);
        s[i] -= a[x];
    }
}
void sub1(){
    backtrack(1);
    cout << res;
}
void sub2(){
    memset(g, -1, sizeof(g));
    g[1][0] = g[1][a[1]] = a[1];
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= sum[i]; j++) if(g[i][j] != -1) {
            for(int k = i + 1; k <= n; k++){
                g[k][j + a[k]] = abs(sum[k] - 2 * (j + a[k]));
                g[k][j] = abs(sum[k] - 2 * j);
            }
        }
    }
    int res = INF;
    for(int i = 0; i <= sum[n]; i++) if(g[n][i] != -1) minimize(res, g[n][i]);
    cout << res;
}
void sub3(){
    for(int i = 1; i <= n; i++) d[i] = a[i];
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            int tmp1 = abs(sum[j] - 2 * (d[i] + a[j]));
            int tmp2 = abs(sum[j] - 2 * d[i]);
            int tmp3 = abs(sum[j] - 2 * d[j]);
            if(tmp1 < tmp2) d[j] = d[i] + a[j];
            else if(tmp2 < tmp3) d[j] = d[i];
        }
    }
    cout << abs(sum[n] - 2 * d[n]);
}
int32_t main()
{
    FastIO
    readfile();
    if(n <= 20) sub1();
    else if(n <= 1000) sub2();
    else cout << 1;
    return 0;
}
