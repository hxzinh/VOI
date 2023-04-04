#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define MASK(x) (1LL << (x))
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e3 + 10;
const int MOD = 1e9 + 7;
int n, h;
int res = 0, ans = 1;
int a[NM], num[NM], f[NM][NM];
bool cx[NM];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n >> h;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    memset(cx, true, sizeof(cx));
}
bool check(){
    for(int i = 1; i <= n; i++) if(a[i] != h) return false;
    return true;
}
void backtrack(int x){
    if(x > n){
        cout << '\n';
        if(check()) res = (res + 1) % MOD;
    }
    if(a[x] >= h) backtrack(x + 1);
    for(int i = x; i <= n; i++) if(cx[i]) {
        for(int j = x; j <= i; j++) a[j]++;
        cx[i] = false;
        cout << i << " ";
        backtrack(i);
        cx[i] = true;
        for(int j = x; j <= i; j++) a[j]--;
    }
}
void sub1(){
    backtrack(1);
    cout << res;
}
int dp(int x, int open){
    if(x > n) return (open == 0);
    int &res = f[x][open];
    if(res != -1) return res;
    res = 0;
    if(a[x] + open == h - 1){
        res = (res + dp(x + 1, open)) % MOD;
        res = (res + dp(x + 1, open + 1)) % MOD;
        res = (res + open * dp(x + 1, open)) % MOD;
    } else if(a[x] + open == h) {
        res = (res + dp(x + 1, open)) % MOD;
        if(open > 0) res = (res + open * dp(x + 1, open - 1)) % MOD;
    }
    return res;
}
void full(){
    memset(f, -1, sizeof(f));
    cout << dp(1, 0);
}
int main()
{
    FastIO
    readfile();
    full();
    return 0;
}
