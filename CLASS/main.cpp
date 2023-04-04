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

const int NM = 4e5 + 10;
int n, q, T, maxR;
ll X[NM], Y[NM], Z[NM], s[NM], ans[NM], L[NM], R[NM];
pll qr[NM];

struct Data {
    ll x1, x2, a, b, c, modl;
} a[NM];

struct Event {
    ll x, type;
};

void trau() {
    for(int i = 1; i <= n; i++) s[i] = 0;

    for(int i = 1; i <= n; i++) {
        s[L[i]]++;
        s[R[i] + 1]--;
        maximize(maxR, R[i]);
    }

    for(int i = 1; i <= maxR; i++) s[i] += s[i - 1];

    for(int i = 1; i <= n; i++) cout << L[i] << " " << R[i] << '\n';
    for(int i = 1; i <= q; i++) cout << qr[i].fi << '\n';

    sort(qr + 1, qr + q + 1, [](const pll A, const pll B){
        return A.fi < B.fi;
    });

    ll res = 0;
    ll curSum = 0, curId = 1;
    for(int i = maxR; i > 0; i--) {
        curSum += s[i];
        while(qr[curId].fi <= curSum && curId <= q) {
            res += i * qr[curId].se;
            curId++;
        }
    }

    cout << res << '\n';
}
void xuli() {
    vector<Event> events, tmp;

    for(int i = 1; i <= n; i++) {
        events.push_back({L[i] - 1, -1});
        events.push_back({R[i], 1});
    }

    sort(ALL(events), [](const Event A, const Event B){
        return A.x > B.x;
    });

    sort(qr + 1, qr + q + 1, [](const pii A, const pii B){
        return A.fi < B.fi;
    });

    ll res = 0, curSum = 0, curPerson = 0, curPos = maxR;
    int curId = 1;
    for(int i = 0; i < events.size(); i++) {
        Event u = events[i];
        if(i > 0 && u.x == events[i - 1].x) {
            curPerson += u.type;
            continue;
        }
        curSum += (curPos - (u.x + 1) + 1) * curPerson;

        while(curSum >= qr[curId].fi && curId <= q) {
            int tam = curSum - qr[curId].fi;
            int p = u.x + (tam / curPerson) + 1;
            res += p * qr[curId].se;
            curId++;
        }

        curPerson += u.type;
        curPos = u.x;
    }

    cout << res << '\n';
}
int32_t main()
{
    FastIO
    freopen("CLASS.INP", "r", stdin);
    freopen("CLASS.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n >> q;

        maxR = -INF;
        for(int i = 1; i <= 3; i++) {
            int x, y, u, v, k, m;
            cin >> x >> y >> u >> v >> k >> m;
            a[i] = {x, y, u, v, k, m};
        }

        X[1] = a[1].x1; X[2] = a[1].x2;
        Y[1] = a[2].x1; Y[2] = a[2].x2;
        Z[1] = a[3].x1; Z[2] = a[3].x2;

        for(int i = 3; i <= n; i++) {
            X[i] = (a[1].a * X[i - 1] + a[1].b * X[i - 2] + a[1].c) % a[1].modl;
            Y[i] = (a[2].a * Y[i - 1] + a[2].b * Y[i - 2] + a[2].c) % a[2].modl;
        }

        for(int i = 3; i <= q; i++) {
            Z[i] = (a[3].a * Z[i - 1] + a[3].b * Z[i - 2] + a[3].c) % a[3].modl;
        }

        for(int i = 1; i <= n; i++) {
            L[i] = min(X[i], Y[i]) + 1;
            R[i] = max(X[i], Y[i]) + 1;
        }

        for(int i = 1; i <= q; i++) {
            qr[i].fi = Z[i] + 1;
            qr[i].se = i;
        }

        xuli();
    }
    return 0;
}

/* Author: hxzinh */


