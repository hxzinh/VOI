#include <bits/stdc++.h>
#define ll long long
#define INF 1e8
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 5e4 + 10;
int n, q;

struct SegmentTree{
    int n;
    vector<int> minn, maxx;

    SegmentTree(int _n){
        n = _n;
        minn.assign(4 * n + 7, INF);
        maxx.assign(4 * n + 7, 0);
    }

    void update(int i, int l, int r, int x, int d){
        if(l > d || r < d) return;
        if(l == r && l == d){
            maxx[i] = x;
            minn[i] = x;
            return;
        }
        int m = (l + r) / 2;
        update(2 * i, l, m, x, d);
        update(2 * i + 1, m + 1, r, x, d);
        minn[i] = min(minn[2 * i], minn[2 * i + 1]);
        maxx[i] = max(maxx[2 * i], maxx[2 * i + 1]);
        return;
    }

    int getMin(int i, int l, int r, int u, int v){
        if(l > v || r < u || l > r || u > v) return INF;
        if(l >= u && r <= v) return minn[i];
        int m = (l + r) / 2;
        int minL = getMin(2 * i, l, m, u, v);
        int minR = getMin(2 * i + 1, m + 1, r, u, v);
        return min(minL, minR);
    }

    int getMax(int i, int l, int r, int u, int v){
        if(l > v || r < u || l > r || u > v) return 0;
        if(l >= u && r <= v) return maxx[i];
        int m = (l + r) / 2;
        int maxL = getMax(2 * i, l, m, u, v);
        int maxR = getMax(2 * i + 1, m + 1, r, u, v);
        return max(maxL, maxR);
    }

    int getDist(int u, int v){
        return getMax(1, 1, n, u, v) - getMin(1, 1, n, u, v);
    }

    void update(int x, int d){
        update(1, 1, n, x, d);
    }
};

void readfile(){
    freopen("COWLINE.INP", "r", stdin);
    cin >> n >> q;
    SegmentTree tree(n);
    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        tree.update(u, i);
    }
    while(q--){
        int u, v; cin >> u >> v;
        cout << tree.getDist(u, v) << '\n';
    }
}
int main()
{
    FastIO
    readfile();
    return 0;
}
