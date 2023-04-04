#include <bits/stdc++.h>
#define ll long long
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
int n, m;
pii a[NM], b[NM];

int main()
{
    FastIO
    freopen("EDU3F.INP", "r", stdin);
    freopen("EDU3F.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
    for(int i = 1; i <= m; i++) cin >> b[i].fi >> b[i].se;

    xuli();
    return 0;
}
