#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 250000 + 10;
int n,T,m;
vector<int> adj[NM]; ///luu chi so theo canh
vector<int> lab, tree[NM], leaves;
int low[NM], num[NM], numChild[NM], cnt;
int compID[NM], compNode[NM], numComp;

struct Edge{
    int u,v;
    bool used, isBridge;

    Edge(int _u = 0, int _v = 0){
        u = _u; v = _v;
        used = false;
        isBridge = false;
    }
};
Edge a[NM];

int root(int x){
    if(lab[x] == -1) return x;
    else lab[x] = root(lab[x]);
    return lab[x];
}
bool join(int u,int v){
    int x = root(u), y = root(v);
    if(x == y) return false;
    if(lab[x] > lab[y]) swap(x, y);
    lab[y] = x;
    return true;
}
void dfs(int u){
    low[u] = n + 1;
    num[u] = ++cnt;
    for(int i : adj[u]){
        if(!a[i].used){
            a[i].used = true;
            int v = a[i].u ^ a[i].v ^ u;
            if(num[v] == 0){
                dfs(v);
                low[u] = min(low[u], low[v]);
                if(low[v] > num[u]) a[i].isBridge = true;
                else a[i].isBridge = false;
            } else low[u] = min(low[u], num[v]);
        }
    }
}
void dfsComp(int u,int far){
    bool ok = true;
    for(int v : tree[u]){
        if(v != far){
            dfsComp(v, u);
            ok = false;
        }
    }
    if(ok) leaves.push_back(u);
}
void xuli(){
    for(int i = 1; i <= n; i++) if(num[i] == 0) dfs(i);

    lab.assign(n + 7, -1);
    for(int i = 1; i <= m; i++)
        if(!a[i].isBridge)
            join(a[i].u, a[i].v);
    for(int i = 1; i <= n; i++){
        if(root(i) == i){
            compID[i] = ++numComp;
            compNode[numComp] = i;
        }
    }
    for(int i = 1; i <= n; i++)
        if(root(i) != i){
            compID[i] = compID[root(i)];
        }
    for(int i = 1; i <= m; i++) if(a[i].isBridge){
        int u = compID[a[i].u];
        int v = compID[a[i].v];
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    if(numComp == 1){
        cout << 0 << '\n';
        return;
    }

    if(numComp == 2){
        cout << 1 << '\n';
        cout << compNode[1] << " " << compNode[2] << '\n';
        return;
    }

    int far = 0;
    while(tree[far].size() < 2) far++;
    dfsComp(far, -1);

    cout << (leaves.size() + 1) / 2 << '\n';
    for(int i = 0; i < leaves.size() / 2; i++){
        int u = leaves[i];
        int v = leaves[i + leaves.size()/2];
        cout << compNode[u] << " " << compNode[v] << '\n';
    }
    if(leaves.size() % 2 != 0){
        int u = leaves.front();
        int v = leaves.back();
        cout << compNode[u] << " " << compNode[v] << '\n';
    }
}
void prepare(){
    memset(low, 0, (n + 7)*sizeof(int));
    memset(num, 0, (n + 7)*sizeof(int));
    cnt = 0;
    for(int i = 1; i <= n; i++) adj[i].clear();

    ///lab.assign(n + 7, -1);

    memset(compID, 0, (n + 7)*sizeof(int));
    memset(compNode, 0, (n + 7)*sizeof(int));
    numComp = 0;

    for(int i = 1; i <= n; i++) tree[i].clear();
    leaves.clear();
}
void readfile(){
    freopen("BICONNECTED.INP","r",stdin);
    freopen("BICONNECTED.OUT","w",stdout);
    cin >> T;
    for(int times = 1; times <= T; times++){
        cin >> n >> m;
        prepare();
        for(int i = 1; i <= m; i++){
            int u,v; cin >> u >> v;
            a[i] = Edge(u, v);
            adj[u].push_back(i); adj[v].push_back(i);
        }
        xuli();

    }
}
int main()
{
    FastIO
    readfile();
    return 0;
}
