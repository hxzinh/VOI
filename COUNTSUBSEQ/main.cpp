#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 6e3 + 10;
const int MOD = 998244353;
int n, k;
int ans = 0;
int a[3000], f[3000][6000];

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void readfile(){
    freopen("COUNTSUBSEQ.INP", "r", stdin);
    freopen("COUNTSUBSEQ.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void backtrack(int x, int sum){
    if(x > n) return;
    backtrack(x + 1, sum);
    if(a[x] + sum <= k){
        add(ans, 1);
        backtrack(x + 1, sum + a[x]);
    }
    return;
}
void sub1(){
    backtrack(1, 0);
    cout << ans;
}
void sub2(){
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) f[i][a[i]] = 1;

    for(int i = 0; i < n; i++){
        for(int sum = 0; sum <= k; sum++) if(f[i][sum] > 0) {
            add(f[i + 1][sum], f[i][sum]);
            if(sum + a[i + 1] <= k) add(f[i + 1][sum + a[i + 1]], f[i][sum]);
        }
    }

    int res = 0;
    for(int i = 1; i <= k; i++) add(res, f[n][i]);
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    sub2();
    return 0;
}
