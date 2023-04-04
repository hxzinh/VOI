#include <bits/stdc++.h>
#define int long long
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

const int NM = 3e5 + 10;
int n, m, q, Sub;
int b[NM];
pii a[NM], t[NM];
vector<int> vec;

struct Data {
    int x, y;

    bool inline operator < (const Data &A) const {
        return y < A.y;
    }
};

struct MilkTea {
    int x, u, v;
} query[NM];

struct FenwickTree {
    int n;
    vector<int> val;

    FenwickTree(int _n = 0){
        n = _n;
        val.assign(n + 7, 0);
    }

    void update(int u, int x){
        for(; u <= n; u += u & -u) val[u] += x;
    }

    int getSum(int u){
        int res = 0;
        for(; u > 0; u -= u & -u) res += val[u];
        return res;
    }
};

int prepare(){
    for(int i = 1; i <= n; i++) b[i] = i;

    int res = -INF;
    do {
        //for(int i = 1; i <= n; i++) cout << b[i] << " ";
        int ans = 0, curTime = 0;
        for(int i = 1; i <= n; i++){
            int id = b[i];
            curTime += a[id].se;
            ans += a[i].fi - curTime;
        }
        maximize(res, ans);
    } while(next_permutation(b + 1, b + n + 1));
    return res;
}
void sub1(){
    cout << prepare() << " ";
    while(q--){
        int x, u, v;
        cin >> x >> u >> v;
        a[x] = {u, v};
        for(int i = 1; i <= n; i++) b[i] = i;

        ll res = -INF;
        do {
            ll ans = 0, curTime = 0;
            for(int i = 1; i <= n; i++){
                int id = b[i];
                curTime += a[id].se;
                ans += a[i].fi - curTime;
            }
            maximize(res, ans);
        } while(next_permutation(b + 1, b + n + 1));
        cout << res << " ";
    }
}
bool cmp(const pii &A, const pii &B){
    return A.se < B.se;
}
void sub123(){
    ll res = 0, curTime = 0;
    for(int i = 1; i <= n; i++) t[i] = a[i];
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++){
        curTime += a[i].se;
        res += a[i].fi - curTime;
    }
    cout << res << " ";

    while(q--){
        int x, u, v;
        cin >> x >> u >> v;

        if(Sub == 2){
            res += u - t[x].fi;
            cout << res << " ";
            t[x] = {u, v};
            continue;
        }

        t[x] = {u, v};
        for(int i = 1; i <= n; i++) a[i] = t[i];

        ll ans = 0, Time = 0;
        sort(a + 1, a + n + 1, cmp);
        for(int i = 1; i <= n; i++){
            Time += a[i].se;
            ans += a[i].fi - Time;
        }
        cout << ans << " ";
    }
}
void full(){
    int s = 0, Time = 0;
    for(int i = 1; i <= n; i++) {
        vec.push_back(a[i].se);
        s += a[i].fi;
    }
    sort(ALL(vec));

    int tmp = 0;
    for(int u : vec){
        tmp += u;
        Time += tmp;
    }

    cout << s - Time << " ";

    for(int i = 1; i <= q; i++){
        int x, u, v;
        cin >> x >> u >> v;
        query[i] = {x, u, v};
        vec.push_back(v);
    }
    sort(ALL(vec));
    vec.erase(unique(ALL(vec)), vec.end());

    int sz = vec.size();
    FenwickTree tree(sz);
    FenwickTree Id(sz);

    for(int i = 1; i <= n; i++){
        int curId = lower_bound(ALL(vec), a[i].se) - vec.begin() + 1;
        Id.update(curId, 1);
        tree.update(curId, a[i].se);
    }
    for(int i = 1; i <= q; i++){
        s += query[i].u - a[query[i].x].fi;

        int curId = lower_bound(ALL(vec), a[query[i].x].se) - vec.begin() + 1;
        int l = Id.getSum(sz) - Id.getSum(curId);
        Time -= l * a[query[i].x].se + tree.getSum(curId);

        Id.update(curId, -1);
        tree.update(curId, -a[query[i].x].se);
        a[query[i].x].fi = query[i].u;
        a[query[i].x].se = query[i].v;

        curId = lower_bound(ALL(vec), a[query[i].x].se) - vec.begin() + 1;
        l = Id.getSum(sz) - Id.getSum(curId);

        Time += (l + 1) * a[query[i].x].se + tree.getSum(curId);

        Id.update(curId, 1);
        tree.update(curId, a[query[i].x].se);

        cout << s - Time << " ";
    }
}
int32_t main()
{
    FastIO
    freopen("RASPORED.INP", "r", stdin);
    freopen("RASPORED.OUT", "w", stdout);
    cin >> Sub >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;

    full();
    return 0;
}

/* Author: hxzinh */
