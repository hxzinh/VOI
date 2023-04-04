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
int a[NM], cnt[NM];

void xuli(){
    vector<int> val;
    for(int i = 1; i <= n; i++) val.push_back(a[i]);
    sort(ALL(val));
    val.resize(unique(ALL(val)) - val.begin());
    for(int i = 1; i <= n; i++) a[i] = lower_bound(ALL(val), a[i]) - val.begin() + 1;

    sort(a + 1, a + n + 1);
    int res = 0, tmp = 0;
    a[0] = -1;
    for(int i = 1; i <= n; i++){
        res += (a[i] == a[i - 1] ? tmp : ++tmp);
    }
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("LIS.INP", "r", stdin);
    freopen("LIS.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    xuli();
    return 0;
}
