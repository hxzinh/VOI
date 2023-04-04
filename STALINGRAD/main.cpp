#include <bits/stdc++.h>
#define ll long long
#define int long long
#define oo 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=4e5+100;
const int LOG=19;
int sub,n,q,fa[NM][LOG+2],cnt=0,road=0,blocked=0,freeNode=0;
int root[NM],high[NM],pos[NM],numChild[NM],top[NM],curLCA[NM];
vector <int> a[NM];
set <int> active[NM];

void readfile(){
    freopen("STALINGRAD.INP","r",stdin);
    freopen("STALINGRAD.OUT","w",stdout);
    cin >> sub;
    cin >> n >> q;
    for(int i=2;i<=n;i++){
        int u; cin >> u;
        fa[i][0]=u;
        a[u].push_back(i);
    }
}
void dfs(int u,int par){
    root[u] = par;
    pos[u] = ++cnt;
    numChild[u] = 1;
    top[cnt] = u;
    for(int v : a[u]){
        high[v] = high[u]+1;
        dfs(v,par);
        numChild[u] += numChild[v];
    }
}
void prepare(){
    for(int u : a[1]){
        high[u]=1;
        dfs(u,u);
    }
    high[0]=-1;
    for(int i=1;i<=LOG;i++){
        for(int j=1;j<=n;j++){
            fa[j][i]=fa[fa[j][i-1]][i-1];
        }
    }
}
int lca(int u,int v){
    if(high[v] > high[u]) return lca(v,u);
    for(int i=LOG;i>=0;i--) if(high[fa[u][i]] >= high[v]) u=fa[u][i];
    if(u==v) return u;
    for(int i=LOG;i>=0;i--){
        if(fa[u][i] != fa[v][i]){
            u=fa[u][i];
            v=fa[v][i];
        }
    }
    return fa[u][0];
}
int newlca(const set<int> &s){
    if(s.empty()) return 0;
    __typeof(s.begin()) it = s.begin();
    int left=top[*it];
    it = s.end(); it--;
    int right=top[*it];
    return lca(left,right);
}
void pushNode(int node){
    int cur = root[node];
    if(active[cur].empty()) road++;
    active[cur].insert(pos[node]);
    int parNode = newlca(active[cur]);
    blocked++;
    freeNode += numChild[parNode] - numChild[curLCA[cur]];
    curLCA[cur]=parNode;
}
void popNode(int node){
    int cur=root[node];
    active[cur].erase(pos[node]);
    if(active[cur].empty()) road--;
    int parNode = newlca(active[cur]);
    blocked--;
    freeNode += numChild[parNode] - numChild[curLCA[cur]];
    curLCA[cur] = parNode;
}
void xuli(){
    for(int i=1;i<=q;i++){
        char u[5]; int node;
        cin >> u >> node;
        if(u[0] == '+') pushNode(node);
        if(u[0] == '-') popNode(node);
        cout << road << " " << freeNode - blocked << '\n';
    }
}
int32_t main()
{
    FastIO
    readfile();
    prepare();
    xuli();
    return 0;
}
