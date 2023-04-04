#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define ALL(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define fi first
#define se second
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int MOD = 998244353;
const int NM = 2e5 + 10;
int Sub, n, k;
int Max, result = 0;
int h[NM], frac[NM], finv[NM], cnt[NM], g[MASK(20)][21];
vector<int> val;

int add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
int pw(int x, int k){
    if(k == 1) return x;
    if(k == 0) return 1;
    int t = pw(x, k >> 1);
    if(k % 2 == 0) return t * t % MOD;
    else return (t * t % MOD) * x % MOD;
}
int comb(int k, int n) {
	return k > n ? 0 : ((1LL * frac[n] * finv[k]) % MOD * finv[n - k]) % MOD;
}
void prepare(){
    frac[0] = 1;
    for(int i = 1; i <= n; i++) frac[i] = (frac[i - 1] * i) % MOD;
    finv[n] = pw(frac[n], MOD - 2);
    for (int i = n; i >= 1; i--) finv[i - 1] = finv[i] * i % MOD;

    for(int i = 1; i <= n; i++) val.push_back(h[i]);
    sort(ALL(val));
    val.resize(unique(ALL(val)) - val.begin());
    for(int i = 1; i <= n; i++) h[i] = lower_bound(ALL(val), h[i]) - val.begin() + 1;
    Max = val.size();
}
void sub1(){
    int res = 1;
    for(int i = 1; i <= n; i++) cnt[h[i]]++;
    for(int i = 1; i <= Max; i++) res = res * frac[cnt[i]] % MOD;
    cout << res;
}
int dp(int mask, int cnt){
    if(mask == MASK(n) - 1) return 1;
    if(cnt > k) return -INF;
    int &res = g[mask][cnt];
    if(res > 0) return res;

    int maxH = 0;
    for(int i = 1; i <= n; i++) if(BIT(i - 1, mask)) maximize(maxH, h[i]);
    for(int i = 1; i <= n; i++) if(!BIT(i - 1, mask)){
        int newMask = mask | MASK(i - 1);
        int newCnt = cnt + (h[i] < maxH);
        if(newCnt <= k) add(res, dp(newMask, newCnt));
    }
    return res;
}
void sub2(){
    minimize(k, 20);
    g[0][0] = 1;
    for(int mask = 0; mask < MASK(n); mask++){
        for(int cnt = 0; cnt <= k; cnt++) if(g[mask][cnt]){
            int maxH = 0;
            for(int i = 1; i <= n; i++) if(BIT(i - 1, mask)) maximize(maxH, h[i]);
            for(int i = 1; i <= n; i++) if(!BIT(i - 1, mask)){
                int newMask = mask | MASK(i - 1);
                int newCnt = cnt + (h[i] < maxH);
                if(newCnt <= k) add(g[newMask][newCnt], g[mask][cnt]);
            }
        }
    }

    int res = 0;
    for(int i = 0; i <= k; i++) add(res, g[MASK(n) - 1][i]);
    cout << res;
}
void sub4(){
    int numOne = 0, numTwo = 0;
    for(int i = 1; i <= n; i++){
        if(h[i] == 1) numOne++;
        else numTwo++;
    }

    int t = frac[numOne] * frac[numTwo] % MOD;
    int res = 1;
    for(int i = 1; i <= min(k, numOne); i++){
        add(res, comb(numTwo - 1, numTwo + i - 1));
    }
    res = (res * t) % MOD;
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("LINE.INP", "r", stdin);
    freopen("LINE.OUT", "w", stdout);
    cin >> Sub;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> h[i];

    prepare();

    if(Sub == 1) sub1();
    else if(n <= 20) sub2();
    else if(Sub == 4) sub4();

    cout << '\n' << ((1LL * frac[5] * finv[2]) % MOD * finv[3]) % MOD;
    return 0;
}
