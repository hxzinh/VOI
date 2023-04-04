#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e5 + 10;
int n, m;

struct SegmentTree {
    int n;
    vector<int> sum, maxx;

    SegmentTree(int _n = 0){
        n = _n;
        sum.assign(4 * n + 7, 0);
        maxx.assign(4 * n + 7, -INFINITY);
    }

    void update(int i, int l, int r, int x, int d){
        if(x > r || x < l) return;
        if(l == r && l == x){
            maxx[i] = d;
            sum[i] = d;
            return;
        }
        int m = (l + r) / 2;
        update(2 * i, l, m, x, d);
        update(2 * i + 1, m + 1, r, x, d);
        int k = max(maxx[2 * i], maxx[2 * i + 1]);
        maxx[i] = max(maxx[2 * i], maxx[2 * i + 1]);
        ///sum[i] = max({maxx[i], sum[i] + maxx[i], sum[i]});
    }

    int getSum(int i, int l, int r, int u, int v){
        if(l > v || r < u || l > r || u > v) return 0;
        if(l >= u && r <= v) return sum[i];
        int m = (l + r) / 2;
        int sumL = getSum(2 * i, l, m, u, v);
        int sumR = getSum(2 * i + 1, m + 1, r, u, v);
        return max({sumL, sumR, sumL + sumR});
    }

    void update(int x, int d){
        update(1, 1, n, x, d);
    }

    int getSum(int u, int v){
        return getSum(1, 1, n, u, v);
    }
};

void readfile(){
    freopen("QMAXSUM.INP", "r", stdin);
    freopen("QMAXSUM.OUT", "w", stdout);
    cin >> n >> m;
    SegmentTree tree(n);
    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        tree.update(i, u);
    }

    while(m--){
        int x, y; cin >> x >> y;
        cout << tree.getSum(x, y) << '\n';
    }
}
int main()
{
    FastIO
    readfile();
    return 0;
}
