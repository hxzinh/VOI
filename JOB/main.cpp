#include <bits/stdc++.h>
#define ll long long
#define oo 1e18
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=3e5+10;
ll n,m;
ll s[NM],t[NM],F[NM],l[NM];
vector <int> b[NM];

priority_queue <pair<int,int>> leaf;
bool operator < (const pair<int,int> &A,const pair<int,int> &B){
    if(A.first==B.first) return A.second > B.second;
    else return A.first > B.first;
}

void readfile(){
    freopen("job.inp","r",stdin);
    freopen("job.out","w",stdout);
    cin >> n >> m;
    memset(s,0,sizeof s);
    for(int i=1;i<=n-1;i++){
        ll u,v;
        cin >> u >> v;
        t[u]=v;
        F[v]++; b[v].push_back(u);
    }
}
ll trace(ll x){
    if(t[x]!=0) return trace(t[x]);
    else return x;
}
void dfs(ll x){
    for(int i=0;i<b[x].size();i++){
        ll v=b[x][i];
        F[v]=F[x]+1;
        dfs(v);
    }
}
void xuli(){
    ll res=0;
    ll fa=trace(1);
    F[fa]=0;
    dfs(fa);
    for(int i=1;i<=n;i++){
        l[i]=b[i].size();
        if(b[i].empty()){
            leaf.push({F[i],i});
        }
    }
    while(leaf.size()!=0){
        res++;
        vector <int> next;
        for(int i=0;i<leaf.size() && i<m;i++){
            ll u=leaf.top().second;
            cout << u << '\n';
            next.push_back(t[u]);
            leaf.pop();
        }
        for(int i=0;i<next.size();i++){
            ll v=next[i];
            if(--l[v]==0)
                leaf.push({F[v],v});
            ///else l[v]--;
        }
    }
    cout << res;
}
int main(){
    FastIO
    readfile();
    xuli();
    return 0;
}
