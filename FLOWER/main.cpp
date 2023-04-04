#include <bits/stdc++.h>
#define int long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int MAX = 1e6 + 10;
int task, MOD;
int frac[MAX + 10], finv[MAX + 10];
bool cx[MAX];
vector<int> primes;

void readfile(){
    freopen("FLOWERS.INP", "r", stdin);
    freopen("FLOWERS.OUT", "w", stdout);
    cin >> task >> MOD;
}
int pw(const long long n, const long long k){
    if(k == 0) return 1;
    int res = pw(n, k >> 1);
    res = res * res % MOD;
    return (k & 1 ? res * n % MOD : res % MOD);
}
void prepare(){
    frac[0] = 1;
    for(int i = 1; i < MAX; i++) frac[i] = 1LL * (frac[i - 1] * i) % MOD;
    finv[MAX - 1] = pw(frac[MAX - 1], MOD - 2);
    for(int i = MAX - 2; i >= 0; i--) finv[i] = 1LL * finv[i + 1] * (i + 1) % MOD;
}
int comb1(int n, int k){
    return k > n ? 0 : 1LL * frac[n] * pw(frac[k] * frac[n - k] % MOD, MOD - 2) % MOD;
}
int comb3(int n, int k){
    if(k > n) return 0;
    int res = finv[k];
    for(int i = 0; i < k; i++) res = 1LL * (n - i) % MOD * res % MOD;
    return res;
}
void IsPrime(){
    memset(cx, false, sizeof cx);
    cx[0] = cx[1] = true;
    for(int i = 2; 1LL * i * i < MAX; i++) if(!cx[i]) {
        for(int j = i * i; j <= MAX; j += i) cx[j] = true;
    }
    for(int i = 2; i < MAX; i++) if(!cx[i]) primes.push_back(i);
}
int comb4(int n, int k){
    if(k > n) return 0;
    int res = 1;
    for(int u : primes){
        if(u > n) break;
        int exp = 0;
        for(int i = u; i <= n; i *= u){
            exp += (n / i - k / i - (n - k) / i) % MOD;
        }
        res = 1LL * res * pw(u, exp) % MOD;
    }
    return res;
}
void sub4(){
    IsPrime();
    while(task--){
        int numFlow, numType, k;
        cin >> numFlow >> numType >> k;
        int tam = comb4(numFlow - 1, k);
        int res = pw(numType - 1, k) % MOD * numType % MOD * comb4(numFlow - 1, k) % MOD;
        cout << res << '\n';
    }
}
void sub1(){
    prepare();
    while(task--){
        int numFlow, numType, k;
        cin >> numFlow >> numType >> k;
        int res = pw(numType - 1, k) % MOD * numType % MOD * comb1(numFlow - 1, k) % MOD;
        cout << res << '\n';
    }
}
void sub3(){
    prepare();
    while(task--){
        int numFlow, numType, k;
        cin >> numFlow >> numType >> k;
        int res = pw(numType - 1, k) % MOD * numType % MOD * comb3(numFlow - 1, k) % MOD;
        cout << res << '\n';
    }
}
void xuli(){
    if(MOD == 998244353 && task == 50) {sub3(); return;}
    if(task <= 1000000 && MOD == 998244353) {sub1(); return;}
    sub4();
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
