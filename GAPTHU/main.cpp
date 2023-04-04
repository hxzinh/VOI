#include <bits/stdc++.h>
#define ll long long
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

/**
//PRAGMA
#pragma GCC target("popcnt")
**/

/**
//ordered_set
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pii,
             null_type,
             less<pii>,
             rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;
**/

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

typedef unsigned long long ull;

const int NM = 1e5 + 10;
int n, m, q;
int ans[NM], cnt[10000005];
ll a[NM], p[NM], s[NM], ex[NM], valBear[NM];
pii b[NM];
pair<ll, int> qr[NM];

void add(ll &a, ll b) {
    if(a >= 4e18 - b) a = 4e18;
    else a += b;
}
void sub12() {
    sort(qr + 1, qr + q + 1);
    memset(ans, -1, sizeof ans);

    ll cost = 0, valBear = 0, curId = 0, Idqr = 1, res = 0;
    for(int i = b[1].fi; i <= b[1].se; i++) {
        while(curId < n && a[curId + 1] <= cost) curId++;
        add(valBear, i);
        add(cost, p[curId]);
        res++;

        while(Idqr <= q && valBear - cost >= qr[Idqr].fi) {
            ans[qr[Idqr].se] = res;
            Idqr++;
        }
    }

    for(int i = 1; i <= q; i++) cout << ans[i] << " ";
}
void xuli() {
    vector<int> vec;
    int curBear = INF, lastBear = 0;
    for(int i = 1; i <= m; i++) {
        cnt[b[i].fi]++;
        cnt[b[i].se + 1]--;
        minimize(curBear, b[i].fi);
        maximize(lastBear, b[i].se);
    }
    for(int i = curBear; i <= lastBear; i++) {
        cnt[i] += cnt[i - 1];
        if(cnt[i] > 0) vec.push_back(i);
    }

    cout << vec.size() << '\n';
    sort(ALL(vec));
    for(int u : vec) cout << u << '\n';

    /**
    int curId = 0;
    for(int i = curBear; i <= lastBear; i++) {
        if(!cnt[i]) {
            s[i] = s[i - 1];
            ex[i] = ex[i - 1];
            continue;
        }

        if(curId == n) {
            s[i] = s[i - 1];
            ex[i] += 1LL * cnt[i] * (p[curId] - i);
            continue;
        }

        int numBear = cnt[i];
        ll cost = s[i - 1];
        while(numBear) {
            while(curId < n && cost >= a[curId + 1]) curId++;

            int numNeed = (cost + a[curId + 1] + p[curId] - 1) / p[curId];
            if(curId < n) minimize(numNeed, numBear);
            else numNeed = numBear;

            add(s[i], numNeed * p[curId]);
            ex[i] += 1LL * numNeed * (p[curId] - i);

            numBear -= numNeed;
        }
    }
    **/
}
int32_t main()
{
    FastIO
    freopen("GAPTHU.INP", "r", stdin);
    freopen("GAPTHU.OUT", "w", stdout);
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= m; i++) {
        cin >> b[i].fi >> b[i].se;
    }
    for(int i = 1; i <= q; i++) {
        cin >> qr[i].fi;
        qr[i].se = i;
    }

    xuli();
    return 0;
}

/* Author: hxzinh */

