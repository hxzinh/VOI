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

const int NM = 1e5 + 10;
int n, q;
int a[NM];

struct SegmentTree {
    int n;
    vector<int> Max;

    SegmentTree(int _n = 0){
        n = _n;
        Max.assign(4 * n + 7, -INF);
    }

    void update(int i, int l, int r, int u, int x){
        if(u < l || u > r || l > r) return;
        if(l == r && l == u){
            Max[i] = x;
            return;
        }

        int m = (l + r) >> 1;
        update(2 * i, l, m, u, x);
        update(2 * i + 1, m + 1, r, u, x);
        Max[i] = max(Max[2 * i], Max[2 * i + 1]);
    }

    int getMax(int i, int l, int r, int u, int v){
        if(u > r || v < l || l > r) return -INF;
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

void xuli(){
    SegmentTree tree(n);
    for(int i = 1; i <= n; i++) tree.update(i, a[i]);

    //for(int i = 1; i <= n; i++) cout << tree.getMax(1, i) << " ";
    //cout << '\n';

    while(q--){
        int type, u, v;
        cin >> type >> u >> v;
        if(type == 1) tree.update(u, v);
        else cout << tree.getMax(u, v) << '\n';
    }
}
int main()
{
    FastIO
    freopen("ITEZ1.INP", "r", stdin);
    freopen("ITEZ1.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;

    xuli();
    return 0;
}

/* Author: hxzinh */
