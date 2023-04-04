#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e5 + 10;
int n;
int result = 0;
int a[NM];

void backtrack(int x, int cnt, int Gcd){
    if(x > n) return;
    int newGcd = (!Gcd ? a[x] : __gcd(a[x], Gcd));
    backtrack(x + 1, cnt + 1, newGcd);
    result += newGcd;
    backtrack(x + 1, cnt, Gcd);
    return;
}
void sub1(){
    backtrack(1, 0, 0);
    cout << result;
}
int32_t main()
{
    FastIO
    freopen("GCDSUM.INP", "r", stdin);
    freopen("GCDSUM.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    sub1();
    return 0;
}
