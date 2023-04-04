#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n;
int a[NM];
pii g[MASK(20)], b[NM], g[2005][2005];

void sub1(){
    int res = 0;

    sort(a + 1, a + n + 1);
    do {
        int ans = a[1], tmp = a[1];
        for(int i = 2; i <= n; i++){
            tmp = __gcd(tmp, a[i]);
            ans += tmp;
        }
        maximize(res, ans);
    } while(next_permutation(a + 1, a + n + 1));

    cout << res;
}
void sub2(){
    for(int i = 1; i <= n; i++) g[MASK(i - 1)] = {a[i], a[i]};
    for(int mask = 0; mask < MASK(n); mask++){
        for(int i = 1; i <= n; i++) if(!BIT(mask, i - 1)){
            int newMask = mask | MASK(i - 1);
            int newGcd = __gcd(g[mask].se, a[i]);

            if(maximize(g[newMask].fi, g[mask].fi + newGcd)) g[newMask].se = newGcd;
        }
    }
    cout << g[MASK(n) - 1].fi;
}
void sub3(){
    sort(a + 1, a + n + 1);

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] != a[i - 1]){
            cnt++;
            b[cnt] = {a[i], 1};
        } else b[cnt].se++;
    }

    for(int i = 1; i <= cnt; i++) g[i][1] = {b[i].fi * b[i].se, b[i].fi};
}
int main()
{
    FastIO
    freopen("TOY.INP", "r", stdin);
    freopen("TOY.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    if(n <= 10) sub1();
    else sub2();
    return 0;
}
