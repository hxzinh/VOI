#include <bits/stdc++.h>
#define ll long long
#define int long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define pll pair<long long, long long>
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
const int MOD = 1e9 + 7;
int A, B, C;
int a[NM], t[NM];

void add(int &a, int b) {
    a = (a + b) % MOD;
    if(a < 0) a += MOD;
}
int32_t main()
{
    FastIO
    freopen("TRICNT.INP", "r", stdin);
    freopen("TRICNT.OUT", "w", stdout);
    cin >> A >> B >> C;

    A--; C--;
    if(A < C) swap(A, C);

    int res = 0;
    for(int j = 1; j <= B; j++) {
        int cur = j * j, ans = 0;
        int last = min(cur, A);
        for(int i = 1; i <= last; i++) {
            int u = cur % i, v = cur / i;
            int sz = min(last - i + 1, u / v + 1);
            add(ans, sz*min(cur/i, C));
            i = i + sz - 1;
        }

        add(res, (A * C % MOD - ans % MOD + MOD) % MOD);
    }

    cout << res;
    return 0;
}
