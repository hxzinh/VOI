#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e5 + 10;
const int MOD = 998244353;
int T, n, k;
int ans = 0, numGroup = 0;
int a[NM], cnt[NM], sum[NM];
int frac[NM], finv[NM], f[NM][305];

int pw(int x, int t){
    if(t == 0) return 1;
    if(t == 1) return x;
    int w = pw(x, t / 2);
    if(t % 2 == 0) return (1LL * w * w) % MOD;
    else return (1LL * w * w % MOD) * 1LL * x % MOD;
}
void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void readfile(){
    freopen("LINE.INP", "r", stdin);
    freopen("LINE.OUT", "w", stdout);
    cin >> T;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
bool cmp(int a, int b){
    return a > b;
}
/**
void sub1(){
    sort(a + 1, a + n + 1);
    int res = 1, i = 1;
    while(i <= n){
        int cnt = 0;
        while(i + cnt <= n && a[i + cnt] == a[i])
            res = res * (++cnt) % MOD;
        i += cnt;
    }
    cout << res;
}
void backtrack(int mask, int cnt, int h){
    if(cnt > k) return;
    if(mask == MASK(n) - 1){
        add(ans, 1);
        return;
    }
    for(int i = 1; i <= n; i++) if(!BIT(mask, i - 1)){
        int newMask = mask | MASK(i - 1);
        if(a[i] >= h) backtrack(newMask, cnt, a[i]);
        else backtrack(newMask, cnt + 1, h);
    }
    return;
}
void sub2(){
    backtrack(0, 0, 0);
    cout << ans;
}
**/
int comb(int t, int n) {
	return t > n ? 0 : (1LL * frac[n] * finv[t] % MOD) * finv[n - t] % MOD;
}
void full(){
    sort(a + 1, a + n + 1, greater<int>());
    numGroup = 1;
    cnt[1] = 1;
    for(int i = 2; i <= n; i++){
        if(a[i] < a[i - 1]) cnt[++numGroup] = 1;
        else cnt[numGroup]++;
    }
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + cnt[i];

    frac[0] = 1;
    for(int i = 1; i <= n; i++) frac[i] = (1LL * frac[i - 1] * i) % MOD;
    finv[n] = pw(frac[n], MOD - 2) % MOD;
    for (int i = n; i >= 1; i--) finv[i - 1] = (1LL * finv[i] * i) % MOD;

    f[1][0] = frac[cnt[1]];
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= k; j++) if(f[i][j]) {
            for(int t = 0; t <= cnt[i + 1] && j + t <= k; t++){
                f[i + 1][j + t] = (f[i + 1][j + t] + ((f[i][j] * 1LL * comb(t, sum[i] - 1 + t) % MOD) * 1LL * frac[cnt[i + 1]]) % MOD) % MOD;
            }
        }
    }

    int res = 0;
    for(int i = 0; i <= k; i++) add(res, f[numGroup][i]);
    cout << res << '\n';
}
int32_t main()
{
    FastIO
    readfile();
    full();
    return 0;
}