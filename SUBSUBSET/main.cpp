#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 3e3 + 10;
const int MOD = 998244353;
int n, k;
int ans = 0;
int a[NM], f[2500][6000][2];

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void readfile(){
    freopen("SUBSUBSET.INP", "r", stdin);
    freopen("SUBSUBSET.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}
void backtrack(int x, int sum, int cost){
    if(cost - sum > k) return;
    if(x > n){
        if(sum > 0 && cost > 0) add(ans, 1);
        return;
    }
    int newSum = sum + a[x];
    backtrack(x + 1, sum + a[x], cost + a[x]);
    backtrack(x + 1, sum, cost + a[x]);
    backtrack(x + 1, sum, cost);
    return;
}
void sub1(){
    backtrack(1, 0, 0);
    cout << ans;
}
void full(){
    f[0][0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            for(int p = 0; p < 2; p++) if(f[i][j][p] > 0) {
                add(f[i + 1][j][1], f[i][j][p]);
                add(f[i + 1][j][p], f[i][j][p]);
                if(j + a[i + 1] <= k) add(f[i + 1][j + a[i + 1]][p], f[i][j][p]);
            }
        }
    }

    for(int i = 0; i <= k; i++) add(ans, f[n][i][1]);
    cout << ans;
}
int32_t main()
{
    FastIO
    readfile();
    full();
    return 0;
}
