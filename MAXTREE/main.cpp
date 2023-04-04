#include <bits/stdc++.h>
#define int long long
#define oo 1e18
#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;
const int NM = 1e6 + 10;
int n, q, a[NM];

struct SegmentTree {
    int numb;
    vector<int> minn;

    SegmentTree(int _numb = 0) {
        numb = _numb;
        minn.assign(4 * numb + 10, -oo);
    }

    void update(int x, int d) {
        int l = 1, r = numb, i = 1;
        while (true) {
            int u = minn[i];
            minn[i] = max(minn[i], d);
            u = minn[i];
            if (l == r)
                return;
            int m = (l + r) >> 1;
            if (x <= m) {
                i = 2 * i;
                r = m;
            } else {
                i = 2 * i + 1;
                l = m + 1;
            }
        }
    }

    int getMin(int i, int l, int r, int u, int v) {
        if (l > v || u > r || l > r || u > v)
            return -oo;
        if (u <= l && v >= r)
            return minn[i];
        int m = (l + r) >> 1;
        int minL = getMin(2 * i, l, m, u, v);
        int minR = getMin(2 * i + 1, m + 1, r, u, v);
        return max(minL, minR);
    }

    int Minof(int u, int v) { return getMin(1, 1, numb, u, v); }
};
SegmentTree tree(NM);

void readfile() {
    freopen("MAXTREE.INP","r",stdin);
    freopen("MAXTREE.OUT","w",stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tree.update(i, a[i]);
    }
}
void xulI() {
    for (int i = 1; i <= q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            tree.update(u, v);
        } else {
            int u, v;
            cin >> u >> v;
            cout << tree.Minof(u, v) << " ";
        }
    }
}
int32_t main() {
    FastIO readfile();
    xulI();
    return 0;
}
