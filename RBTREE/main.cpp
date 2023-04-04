#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define ii pair<int,int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=2e5+10;
ll sub,T,n,numComp;
int color[NM],high[NM];
ii edge[NM]; /// dinh fi lk voi se
int compID[NM];
vector <int> a[NM];

///--------------------DISJOINSET------------------------------///
struct Disjoinset{
    vector <int> lab;

    Disjoinset(int n = 0){
        lab.assign(n+7,-1);
    }

    int timkiem(int x){
        return lab[x] < 0 ? x : lab[x] = timkiem(lab[x]);
    }

    bool join(int a,int b){
        int x = timkiem(a);
        int y = timkiem(b);
        if(x == y) return false;
        if(lab[x] > lab[y]) swap(x,y);
        lab[x] += lab[y];
        lab[y] = x;
        return true;
    }
};
int bfs(int node){
    memset(high,-1,(n+1)*sizeof(int));
    queue <int> q;
    high[node] = 0;
    q.push(node);
    int last = node;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        last = u;
        for(int v : a[u]){
            if(high[v] < 0){
                high[v] = high[u]+1;
                q.push(v);
            }
        }
    }
    return last;
}
void xuli(){
    for(int l=1;l<=T;l++){
        cin >> n;
        for(int i=1;i<=n;i++) cin >> color[i];
        for(int i=0;i<n-1;i++){
            cin >> edge[i].first >> edge[i].second;
            ///cout << edge[i].fi << " " << edge[i].se << '\n';
        }
        numComp=0;
        memset(compID,0,(n+1)*sizeof(int));
        for(int i=1;i<=n;i++) a[i].clear();
        Disjoinset dis(n);
        for(int i=0;i<n-1;i++){
            if(color[edge[i].fi] == color[edge[i].se]){
                dis.join(edge[i].fi,edge[i].se);
            }
        }
        for(int i=1;i<=n;i++){
            if(dis.timkiem(i) == i) compID[i] = ++numComp;
        }
        for(int i=1;i<=n;i++){
            if(dis.timkiem(i) != i) compID[i] = compID[dis.timkiem(i)];
        }
        for(int i=0;i<n-1;i++){
            if(color[edge[i].fi] != color[edge[i].se]){
                int u = compID[edge[i].fi];
                int v = compID[edge[i].se];
                a[u].push_back(v); a[v].push_back(u);
            }
        }
        int deep = bfs(1);
        int res=bfs(deep);
        cout << (high[res] + 1)/2 << " ";
    }
}
void readfile(){
    freopen("RBTREE.INP","r",stdin);
    freopen("RBTREE.OUT","w",stdout);
    cin >> sub >> T;
    xuli();
}
int main()
{
    FastIO
    readfile();
    return 0;
}
