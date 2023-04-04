#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 3e5 + 10;
int sub, n, q;
vector<int> child[NM];
int sta[NM][2], fin[NM][2], high[NM], cnt[2];
int label[NM];
int dem = 0;

struct SegmentTree{
    int n;
    vector<int> lazy, maxValue;

    SegmentTree(int _n = 0){
        n = _n;
        lazy.assign(4 * n + 7, 0);
        maxValue.assign(4 * n + 7, 0);
    }

    void pushDown(int i){
        for(int j = 2 * i; j <= 2 * i + 1; j++){
            lazy[j] += lazy[i];
            maxValue[j] += lazy[i];
        }
        lazy[i] = 0;
    }

    void update(int i,int l,int r,int u,int v,int c){
        if(l > v || r < u || l > r || u > v) return;
        if(l >= u && r <= v){
            maxValue[i] += c;
            lazy[i] += c;
            return;
        }
        pushDown(i);
        int m = (l + r) >> 1;
        update(2 * i, l, m, u, v, c);
        update(2 * i + 1, m + 1, r, u, v, c);
        maxValue[i] = max(maxValue[2 * i], maxValue[2 * i + 1]);
    }

    int getMax(int i,int l,int r,int u,int v){
        if(l > v || r < u || l > r || u > v) return 0;
        if(l >= u && r <= v) return maxValue[i];
        pushDown(i);
        int m = (l + r) >> 1;
        int maxL = getMax(2 * i, l, m, u, v);
        int maxR = getMax(2 * i + 1, m + 1, r, u, v);
        return max(maxL, maxR);
    }

    void update(int u,int v,int c){
        update(1, 1, n, u, v, c);
    }

    int getMax(int u,int v){
        return getMax(1, 1, n, u, v);
    }
};
SegmentTree tree[2];

void readfile(){
    freopen("QUERY.INP","r",stdin);
    freopen("QUERY.OUT","w",stdout);
    cin >> sub;
    cin >> n;
    for(int i = 2; i <= n; i++){
        int u; cin >> u;
        child[u].push_back(i);
    }
    memset(high, 1, sizeof(high));
}
void dfs(int u){
    for(int i = 0; i <= 1; i++) sta[u][i] = cnt[i] + 1;
    label[u] = ++cnt[high[u] & 1];
    for(int v : child[u]){
        high[v] = high[u] + 1;
        dfs(v);
    }
    for(int i = 0; i <= 1; i++) fin[u][i] = cnt[i];
}
void xuli(){
    dfs(1);
    tree[0] = SegmentTree(cnt[0]);
    tree[1] = SegmentTree(cnt[1]);
    string type;
    int u,k;
    cin >> q;
    for(int i = 1; i <= q; i++){
        cin >> type;
        if(type == "add"){
            cin >> u >> k;
            for(int i = 0; i < 2; i++)
                tree[i].update(sta[u][i], fin[u][i], (high[u] & 1) ? k : -k);
        }
        if(type == "get") {
            cin >> u;
            cout << tree[high[u] & 1].getMax(label[u], label[u]) << " ";
        }
        if(type == "pos"){
            cin >> u >> k;
            int res[2];
            for(int i = 0; i < 2; i++){
                res[i] = tree[i].getMax(sta[u][i], fin[u][i]);
            }
            cout << max(res[1], res[0]) << " ";
        }
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
