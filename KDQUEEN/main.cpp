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

const int NM = 1e5 + 10;
const int MOD = 1e9 + 7;
int n, maxPos = -1;
int a[NM], p[NM];
int mp[NM];

void add(int &a, int b) {
    a = (a + b) % MOD;
}
void sub2() {
    int res = 0, ans = 0;
    for(int i = 1; i <= 1000; i++) {
        int cur = 1;
        for(int j = 1; j <= n; j++) if(i <= a[j]) {
            int cnt = (p[j] - i > 0) + (p[j] + i <= a[j]);
            if(cnt) cur = cur * cnt % MOD;
            else {
                cur = 0;
                break;
            }
        } else cur = 0;
        add(res, cur);
    }

    for(int i = 1; i <= n; i++) add(res, a[i] - 1);

    cout << res;
}
bool cmp(const pii A, const pii B) {
    return A.fi > B.fi;
}
void xuli() {
    int res = 0;
    for(int i = 1; i <= n; i++) add(res, a[i] - 1);

    vector<pii> events;
    for(int i = 1; i <= n; i++) {
        int u = min(a[i] - p[i], p[i] - 1), v = max(a[i] - p[i], p[i] - 1);
        events.push_back({u, i});
        events.push_back({v, i});
    }
    events.push_back({0, INF});

    sort(ALL(events), cmp);

    int cnt = 0, ans = 1;
    for(int i = 0; i < events.size() - 1; i++) {
        pii u = events[i];
        if(u.fi == 0) break;
        if(!mp[u.se]) cnt++;
        else ans = ans * 2 % MOD;
        mp[u.se]++;

        if(cnt == n && u.fi != events[i + 1].fi)
            add(res, 1LL * ans * (events[i].fi - events[i + 1].fi) % MOD);
    }

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("KDQUEEN.INP", "r", stdin);
    freopen("KDQUEEN.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        maximize(maxPos, a[i]);
    }
    for(int i = 1; i <= n; i++) cin >> p[i];

    xuli();
    return 0;
}

/* Author: hxzinh */

