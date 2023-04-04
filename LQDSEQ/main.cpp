#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, sum, q;
int a[NM], b[NM];

struct SegmentTree {
    vector<int> sum1, sum2, lazy1, lazy2;
    int n;

    void build(int c[], int d[], int i, int l, int r){
        if(l > r) return;
        if(l == r){
            sum1[i] = c[l];
            sum2[i] = d[l];
            return;
        }
        int m = (l + r) >> 1;
        build(c, d, 2 * i, l, m);
        build(c, d, 2 * i + 1, m + 1, r);
        sum1[i] = sum1[2 * i] + sum1[2 * i + 1];
        sum2[i] = sum2[2 * i] + sum2[2 * i + 1];
        return;
    }

    SegmentTree(int _n, int c[], int d[]){
        n = _n;
        sum1.assign(4 * n + 7, 0);
        sum2.assign(4 * n + 7, 0);
        lazy1.assign(4 * n + 7, 0);
        lazy2.assign(4 * n + 7, 0);
        build(c, d, 1, 1, n);
        return;
    }

    void pushDown1(int i){
        for(int j = 2 * i; j <= 2 * i + 1; j++){
            lazy1[j] += lazy1[i];
            sum1[j] += lazy1[i];
        }
        lazy1[i] = 0;
        return;
    }

    void pushDown2(int i){
        for(int j = 2 * i; j <= 2 * i + 1; j++){
            lazy2[j] += lazy2[i];
            sum2[j] += lazy2[i];
        }
        lazy2[i] = 0;
        return;
    }

    void update1(int i, int l, int r, int x, int d){
        if(l > x || r < x || l > r) return;
        if(l == r && l == x){
            lazy1[i] += d;
            sum1[i] += d;
            return;
        }
        pushDown1(i);
        int m = (l + r) >> 1;
        update1(2 * i, l, m, x, d);
        update1(2 * i + 1, m + 1, r, x, d);
        sum1[i] = sum1[2 * i] + sum1[2 * i + 1];
        return;
    }

    void update2(int i, int l, int r, int x, int d){
        if(l > x || r < x || l > r) return;
        if(l == r && l == x){
            lazy2[i] += d;
            sum2[i] += d;
            return;
        }
        pushDown2(i);
        int m = (l + r) >> 1;
        update2(2 * i, l, m, x, d);
        update2(2 * i + 1, m + 1, r, x, d);
        sum2[i] = sum2[2 * i] + sum2[2 * i + 1];
        return;
    }

    int getSum1(int i, int l, int r, int u, int v){
        if(l > v || r < u || l > r) return 0;
        if(l >= u && r <= v) return sum1[i];
        pushDown1(i);
        int m = (l + r) >> 1;
        int sumL = getSum1(2 * i, l, m, u, v);
        int sumR = getSum1(2 * i + 1, m + 1, r, u, v);
        return sumL + sumR;
    }

    int getSum2(int i, int l, int r, int u, int v){
        if(l > v || r < u || l > r) return 0;
        if(l >= u && r <= v) return sum2[i];
        pushDown2(i);
        int m = (l + r) >> 1;
        int sumL = getSum2(2 * i, l, m, u, v);
        int sumR = getSum2(2 * i + 1, m + 1, r, u, v);
        return sumL + sumR;
    }

    void update(int t, int x, int d){
        if(t == 1) update1(1, 1, n, x, d);
        else update2(1, 1, n, x, d);
        return;
    }

    int getSum(int t, int u, int v){
        if(t == 1) return getSum1(1, 1, n, u, v);
        else return getSum2(1, 1, n, u, v);
    }
};

void readfile(){
    freopen("LQDSEQ.INP", "r", stdin);
    freopen("LQDSEQ.OUT", "w", stdout);
    cin >> n >> sum;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    cin >> q;
}
void xuli(){
    SegmentTree tree(n, a, b);

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int x, u, v;
            cin >> x >> u >> v;
            tree.update(1, x, u - a[x]);
            tree.update(2, x, v - b[x]);
        } else {
            int x;
            cin >> x;
            int l = 1, r = x, res = INF;
            for(int i = 1; i <= x; i++){
                int sum1 = tree.getSum(1, i, x);
                int sum2 = tree.getSum(2, i, x);
                if(sum1 >= sum) minimize(res, sum2);
            }
            cout << (res < INF ? res : -1) << '\n';
        }
    }
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
