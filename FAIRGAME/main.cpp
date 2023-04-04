#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define mp make_pair
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

const int NM = 5e6 + 10;
int n, k, m, p, q;
int f[4005][2];


void solve() {
    int res = INF;
    int u = n % k, v = n / k;
    if(u % 2 == 0) res = 0;
    else res = m;

    if(k % 2 == 0) res += max(p - q, q - p);
    else res += max(p - q, q - p - m);

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("FAIRGAME.INP", "r", stdin);
    freopen("FAIRGAME.OUT", "w", stdout);
    cin >> n >> k >> m >> p >> q;

    solve();
    return 0;
}

