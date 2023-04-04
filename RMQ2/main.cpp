#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 505;
int n, m, q;
int a[NM][NM], Min[NM][NM];


struct SegmentTree {
    int n;
    vector<int> val, mx;

    SegmentTree(int _n = 0){
        n = _n;
        val.assign(4 * n + 7, INF);
        mx.assign(4 * n + 7, 0);
    }

    void update(int i, int l, int r, int x, int d){
        if(l > r || l > x || r < x) return;
        if(l == r && l == x){
            val[i] = d;
            mx[i] = d;
            return;
        }
        minimize(val[i], d);
        int m = (l + r) >> 1;
        update(2 * i, l, m, x, d);
        update(2 * i + 1, m + 1, r, x, d);
        return;
    }

    int getMin(int i, int l, int r, int u, int v){
        if(l > r || l > v || r < u) return INF;
        if(l >= u && r <= v) return val[i];
        int m = (l + r) >> 1;
        int minL = getMin(2 * i, l, m, u, v);
        int minR = getMin(2 * i + 1, m + 1, r, u, v);
        return min(minL, minR);
    }

    int getMin(int u, int v){
        return getMin(1, 1, n, u, v);
    }

    void update(int x, int d){
        update(1, 1, n, x, d);
    }
};

SegmentTree tree[NM];

void readfile(){
    freopen("RMQ2.INP", "r", stdin);
    freopen("RMQ2.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            Min[i][j] = a[i][j];
        }
}
void progress(){
    for(int i = 1; i <= n; i++){
        tree[i] = SegmentTree(m);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) tree[i].update(j, a[i][j]);
    }
}
void xuli(){
    progress();
    cin >> q;
    while(q--){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        if(x > u) swap(x, u);
        if(y > v) swap(y, v);
        int res = INF;
        for(int i = x; i <= u; i++){
            int Min = tree[i].getMin(y, v);
            minimize(res, Min);
        }
        cout << res << '\n';\
    }
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
