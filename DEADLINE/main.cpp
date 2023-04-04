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

const int NM = 1e6 + 10;
int n, dl = 0;
int ans[NM], cur[NM];

struct Data {
    int t, cost, id;
} a[NM];

struct SegmentTree {
    int n;
    vector<pii> Max;

    SegmentTree(int _n = 0){
        n = _n;
        Max.assign(4 * n + 7, {INF, -1});
    }

    void build(int i, int l, int r){
        if(l > r) return;
        if(l == r){
            Max[i] = {-INF, l};
            return;
        }

        int m = (l + r) >> 1;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);
        if(Max[2 * i].fi == Max[2 * i + 1].fi) Max[i] = {Max[2 * i].fi, max(Max[2 * i].se, Max[2 * i + 1].se)};
        else if(Max[2 * i].fi < Max[2 * i + 1].fi) Max[i] = Max[2 * i];
        else Max[i] = Max[2 * i + 1];
    }

    void update(int i, int l, int r, int u, pii x){
        if(u < l || u > r || l > r) return;
        if(l == r && l == u){
            Max[i] = x;
            return;
        }

        int m = (l + r) >> 1;
        update(2 * i, l, m, u, x);
        update(2 * i + 1, m + 1, r, u, x);
        if(Max[2 * i].fi == Max[2 * i + 1].fi) Max[i] = {Max[2 * i].fi, max(Max[2 * i].se, Max[2 * i + 1].se)};
        else if(Max[2 * i].fi < Max[2 * i + 1].fi && Max[2 * i].fi > -INF) Max[i] = Max[2 * i];
        else Max[i] = Max[2 * i + 1];
    }

    pii getMin(int i, int l, int r, int u, int v){
        if(u > r || v < l || l > r) return {INF, -1};
        if(u <= l && v >= r) return Max[i];

        int m = (l + r) >> 1;
        pii minL = getMin(2 * i, l, m, u, v);
        pii minR = getMin(2 * i + 1, m + 1, r, u, v);
        if(minL.fi == minR.fi) return {minL.fi, max(minL.se, minR.se)};
        else if(minL.fi < minR.fi) return minL;
        else return minR;
    }

    void update(int u, pii x){
        update(1, 1, n, u, x);
    }

    pii getMin(int u, int v){
        return getMin(1, 1, n, u, v);
    }
};

struct cmp {
    bool operator() (const Data &A, const Data &B){
        return A.cost < B.cost;
    }
};
void xuli(){
    for(int i = 1; i <= dl; i++) cur[i] = -INF;
    SegmentTree tree(dl);
    tree.build(1, 1, dl);
    priority_queue<Data, vector<Data>, cmp> pq;

    int res = 0;
    for(int i = 1; i <= n; i++){
        pq.push(a[i]);
        Data u = pq.top();
        pii tmp = tree.getMin(1, u.t);

        if(u.cost > (tmp.fi < INF ? tmp.fi : -INF)){
            res += u.cost - (cur[tmp.se] > -INF ? cur[tmp.se] : 0);
            cur[tmp.se] = u.cost;
            tree.update(tmp.se, {u.cost, u.t});
            pq.pop();
        }
        cout << res << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("DEADLINE.INP", "r", stdin);
    freopen("DEADLINR.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].t >> a[i].cost;
        a[i].id = i;
        maximize(dl, a[i].t);
    }

    xuli();
    return 0;
}
