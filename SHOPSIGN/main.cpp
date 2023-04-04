#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n;
int a[NM];

struct SegmentTree {
    int n;
    vector<int> val;

    SegmentTree(int _n = 0){
        n = _n;
        val.assign(4 * n + 7, INF);
    }

    void update(int i, int l, int r, int x, int d){
        if(l > r || l > x || r < x) return;
        if(l == r && l == x){
            val[i] = d;
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

    void update(int x, int d){
        update(1, 1, n, x, d);
    }

    int getMin(int u, int v){
        return getMin(1, 1, n, u, v);
    }
};
SegmentTree tree;

void readfile(){
    freopen("SHOPSIGN.INP", "r", stdin);
    freopen("SHOPSIGN.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
bool check(int x){
    bool ok = false;
    for(int i = 1; i <= n - x + 1; i++){
        int high = tree.getMin(i, i + x - 1);
        if(high == x) ok = true;
        if(high == x && ok) return true;
    }
    return false;
}
void xuli(){
    tree = SegmentTree(n);
    for(int i = 1; i <= n; i++) tree.update(i, a[i]);

    int l = 1, r = n, res = 1;
    while(l <= r){
        int m = (l + r) >> 1;
        if(check(m)){
            res = m;
            l = m + 1;
        } else r = m - 1;
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
