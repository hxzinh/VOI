#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int MOD = 998244353;
const int MAX_TURN = 111;
const int MAX_EAT = 1111;
const int NM = 1e3 + 10;
int n, numSquid, k, h;
int a[NM];
///---------------------sub2------------------------
int ans = 0;
///---------------------full------------------------
int f[MAX_TURN][MAX_TURN * MAX_EAT], sum[MAX_TURN][MAX_TURN * MAX_EAT];

int pw(int x, int u){
    return (x % MOD) * (u % MOD) % MOD;
}
void add(int &x, int y){
    x += y;
    if(x >= MOD) x -= MOD;
}
void sub(int &a, int b){
    a -= b;
    if(a < 0) a += MOD;
}
void readfile(){
    freopen("SQUIDGAME.INP", "r", stdin);
    freopen("SQUIDGAME.OUT", "w", stdout);
    cin >> n >> numSquid >> k >> h;
    for(int i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = INF;
}
void sub1(){
    int res = 1;
    for(int i = 1; i <= k; i++){
        res = pw(numSquid + 1, res);
    }
    cout << res;
}
void backtrack(int x, int t){
    if(t == k){
        add(ans, 1);
        return;
    }
    for(int i = 0; i <= numSquid; i++){
        if(a[x] + i <= min({a[1], a[2], a[3]}) + h){
            add(a[x], i);
            if(x == n) backtrack(1, t + 1);
            else backtrack(x + 1, t);
            sub(a[x], i);
        }
    }
    return;
}
void sub2(){
    backtrack(1, 0);
    cout << ans;
}
int getCnt(int minAll, int maxAll){
    int ans = 1LL;
    for(int i = 1; i <= n; i++){
        int low = minAll - a[i];
        int high = maxAll - a[i];
        maximize(low, 0);
        minimize(high, k * numSquid);
        if(low > high) return 0;
        int tmp = sum[k][high];
        if(low > 0) sub(tmp, sum[k][low - 1]);
        ans = ans * tmp % MOD;
    }
    return ans;
}
void full(){
    f[0][0] = 1;

    for(int i = 0; i <= k * numSquid; i++) sum[0][i] = 1;
    for(int i = 1; i <= k; i++){
        for(int j = 0; j <= k * numSquid; j++){
            f[i][j] = sum[i - 1][j];
            if(j > numSquid) sub(f[i][j], sum[i - 1][j - numSquid - 1]);
            sum[i][j] = sum[i][j - 1];
            add(sum[i][j], f[i][j]);
        }
    }

    int maxSquid = -INF, minSquid = INF;
    for(int i = 1; i <= n; i++){
        maximize(maxSquid, a[i]);
        minimize(minSquid, a[i]);
    }

    int res = 0;
    for(int i = minSquid; i <= minSquid + k * numSquid; i++){
        add(res, getCnt(i, i + h));
        sub(res, getCnt(i + 1, i + h));
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    full();
    return 0;
}
