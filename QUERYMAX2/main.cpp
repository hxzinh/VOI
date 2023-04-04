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

const int NM = 2e5 + 10;
int n, q;
int a[NM], ans[NM];
vector<int> tmp;

struct Query {
    int type, u, v;
} query[NM];

struct SegmentTree {
    int n;
    vector<int> Max;

    SegmentTree(int _n = 0){
        n = _n;
        Max.assign(4 * n + 7, -INF);
    }

    void build(int i, int l, int r){
        if(l > r) return;
        if(l == r){
            Max[i] = a[l];
            return;
        }

        int m = (l + r) >> 1;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);
        Max[i] = max(Max[2 * i], Max[2 * i + 1]);
    }

    void update(int i, int l, int r, int u, int x){
        if(u < l || u > r || l > r) return;
        if(l == r && l == u){
            Max[i] = x;
            return;
        }

        int m = (l + r) >> 1;
        if(u <= m) update(2 * i, l, m, u, x);
        else update(2 * i + 1, m + 1, r, u, x);
        Max[i] = max(Max[2 * i], Max[2 * i + 1]);
    }

    int getMax(int i, int l, int r, int u, int v){
        if(v < l || u > r || l > r) return -INF;
        if(u <= l && v >= r) return Max[i];

        int m = (l + r) >> 1;
        int maxL = getMax(2 * i, l, m, u, v);
        int maxR = getMax(2 * i + 1, m + 1, r, u, v);
        return max(maxL, maxR);
    }

    void update(int u, int x){
        update(1, 1, n, u, x);
    }

    int getMax(int u, int v){
        return getMax(1, 1, n, u, v);
    }
};


struct FenwickTree {
    int n;
    vector<int> sum;

    FenwickTree(int _n = 0){
        n = _n;
        sum.assign(n + 7, 0);
    }

    void update(int u, int x){
        for(; u <= n; u += u & -u) sum[u] += x;
    }

    int getCnt(int u){
        int res = 0;
        for(; u > 0; u -= u & -u) res += sum[u];
        return res;
    }
};

void xuli(){
    int numNode = 0;
    for(int i = 0; i < tmp.size(); i++) a[++numNode] = tmp[i];

    SegmentTree tree(numNode);
    tree.build(1, 1, numNode);

    FenwickTree bit(numNode);

    for(int i = q; i > 0; i--){
        int type = query[i].type, u = query[i].u, v = query[i].v;

        if(type == 1){
            int delL = bit.getCnt(u - 1);
            tree.update(u + delL, -INF);
            bit.update(u + delL, 1);
        } else {
            int delL = bit.getCnt(u - 1), delR = bit.getCnt(v - 1);
            int res = tree.getMax(u + delL, v + delR);
            ans[i] = res;
        }
    }

    for(int i = 1; i <= q; i++){
        if(query[i].type == 2) cout << ans[i] << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("QUERYMAX2.INP", "r", stdin);
    freopen("QUERYMAX2.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        int u; cin >> u;
        tmp.push_back(u);
    }
    for(int i = 1; i <= q; i++){
        int type, u, v;
        cin >> type >> u >> v;
        query[i] = {type, u, v};
        if(type == 1) {
            if(u == tmp.size() + 1) tmp.push_back(v);
            else tmp.insert(tmp.begin() + u - 1, v);
        }
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
