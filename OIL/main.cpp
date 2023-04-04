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

const int NM = 1e6 + 10;
int n, k;
ll a[NM], cost[NM];

void xuli() {
    priority_queue<ll> pq;

    ll res = 0;
    for(int i = n; i > 0; i--) {
        if(pq.size() && pq.top() > cost[i]) {
            res += pq.top() - cost[i];
            pq.pop();
            pq.push(cost[i]);
        } else pq.push(cost[i]);
    }
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("OIL.INP", "r", stdin);
    freopen("OIL.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cost[i] = a[i] + (n - i) * k;
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
