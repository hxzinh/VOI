#include <bits/stdc++.h>
#define ll long long
#define oo 1e9 + 4477
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e6 + 10;
int n,Q;

struct SegmentTree{
    vector<int> maxValue;
    int n;

    SegmentTree(int _n = 0){
        n = _n;
        maxValue.assign(4 * n + 7, -1e9 + 4477);
    }

    void update(int i, int l, int r, int x, int d){
        if(l == r){
            maxValue[i] = d;
            return;
        }
        int m = (l + r) >> 1;
        if(x > m) update(2 * i + 1, m + 1, r, x, d);
        else update(2 * i, l, m, x, d);
        maxValue[i] = max(maxValue[2 * i], maxValue[2 * i + 1]);
    }

    int getMax(int i, int l, int r, int u, int v){
        if(l > v || r < u || l > r || u > v) return -oo;
        if(l >= u && r <= v) return maxValue[i];
        int m = (l + r) >> 1;
        int maxL = getMax(2 * i, l, m, u, v);
        int maxR = getMax(2 * i + 1, m + 1, r, u, v);
        return max(maxL, maxR);
    }
    int Maxof(int u, int v){
        return getMax(1, 1, n, u, v);
    }
};
SegmentTree tree(NM);

void readfile(){
    freopen("ITQMAX.INP","r",stdin);
    freopen("ITQMAX.OUT","w",stdout);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        tree.update(1, 1, NM, i, u);
    }
}
void xuli(){
    for(int i = 1; i <= Q; i++){
        int type; cin >> type;
        int u,v; cin >> u >> v;
        if(type == 1) tree.update(1, 1, NM, u, v);
        else cout << tree.Maxof(u, v) << " ";
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
