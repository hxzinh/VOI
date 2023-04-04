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

const int NM = 1e5 + 10;
ll n, maxLevel, maxCost, minCost, money;
int Min[NM];
pii a[NM];
ll sMax[NM], sMin[NM], sum[NM];

void xuli() {
    sort(a + 1, a + n + 1, greater<pii>());
    for(int i = 1; i <= n; i++) sMax[i] = sMax[i - 1] + a[i].fi;
    for(int i = n; i >= 1; i--) sMin[i] = sMin[i + 1] + a[i].fi;

    ll res = (*min_element(a + 1, a + n + 1)).fi * minCost, id = 0;
    pair<ll, ll> tMin = {INF, INF};
    for(int i = 0; i <= n; i++) {
        if(maxLevel * i - sMax[i] > money) break;
        ll ans = 1LL * i * maxCost, curMoney = money - (maxLevel * i - sMax[i]);

        if(i == n) {
            ans = 1LL * i * maxCost + maxLevel * minCost;
            if(maximize(res, ans)) {
                id = i;
                tMin = {maxLevel, i};
            }
            continue;
        }

        int l = 1, r = maxLevel;
        pair<ll, ll> g = {0, 0};
        while(l <= r) {
            ll m = (l + r) >> 1;

            ll LL = i + 1, RR = n, p = 0;
            while(LL <= RR) {
                ll mm = (LL + RR) >> 1;
                if(a[mm].fi <= m) {
                    p = mm;
                    RR = mm - 1;
                } else LL = mm + 1;
            }

            ll cost = m * (n - p + 1) - sMin[p];
            if(cost <= curMoney) {
                g = {m ,p};
                l = m + 1;
            } else r = m - 1;
        }

        ans += g.fi * minCost;
        if(maximize(res, ans)) {
            id = i;
            tMin = g;
        }
    }

    cout << res << '\n';

    if(id) for(int i = 1; i <= id; i++) a[i].fi = maxLevel;
    for(int i = n; i >= tMin.se; i--) a[i].fi = tMin.fi;
    sort(a + 1, a + n + 1, [](const pii A, const pii B){
        return A.se < B.se;
    });

    for(int i = 1; i <= n; i++) cout << a[i].fi << " ";
}
int32_t main()
{
    FastIO
    freopen("SKILLS.INP", "r", stdin);
    freopen("SKILLS.OUT", "w", stdout);
    cin >> n >> maxLevel >> maxCost >> minCost >> money;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }


    xuli();
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
