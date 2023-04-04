#include <bits/stdc++.h>
#define ll long long
#define int long long
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

const int NM = 2e5 + 10;
ll T, n, m;
ll s[NM], Max[NM];
pair<ll, ll> a[NM];
vector<pii> vec;

bool cmp(const pair<ll, ll> A, const pair<ll, ll> B) {
    return A.fi > B.fi;
}
void xuli() {
    sort(a + 1, a + m + 1, cmp);
    ll res = 0;

    for(int i = 1; i <= m; i++) s[i] = s[i - 1] + a[i].fi;
    Max[0] = -INF;
    for(int i = 1; i <= m; i++) Max[i] = max(Max[i - 1], a[i].se);

    for(int i = 1; i <= m; i++) {
        int l = 1, r = m, p = 0;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(a[mid].fi >= a[i].se) {
                p = mid;
                l = mid + 1;
            } else r = mid - 1;
        }

        maximize(res, a[i].fi + (n - 1) * a[i].se);
        if(p >= n) maximize(res, s[n]);
        else if(p >= i) maximize(res, s[p] + 1LL * a[i].se * (n - p));
        else maximize(res, s[p] + a[i].fi + 1LL * a[i].se * (n - p - 1));
    }

    cout << res << '\n';
}
int32_t main()
{
    FastIO
    freopen("CHOOSE.INP", "r", stdin);
    freopen("CHOOSE.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n >> m;
        vec.clear();
        for(int i = 1; i <= m; i++) {
            cin >> a[i].fi >> a[i].se;
            vec.push_back(a[i]);
        }

        xuli();
    }
    return 0;
}

/* Author: hxzinh */

/*
-----code ko bug-----code ko bug-----code ko bug--------------

          _.-/`)
         // / / )
      .=// / / / )
     //`/ / / / /
    // /     ` /
   ||         /
    \\       /
     ))    .'
    //    /
         /
*/
