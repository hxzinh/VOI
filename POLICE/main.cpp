#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e5 + 10;
int n, m, k , p;
vector<int> adj[NM], par[NM];

void readfile(){
    freopen("POLICE.INP", "r", stdin);
    freopen("POLICE.OUT", "w", stdout);
    cin >> n >> m >> k >> p;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        par[v].push_back(u);
    }
}
void xuli(){
    int numGate = par[n].size();
    cout << numGate;
    if(numGate > k){
        for(int i = 1; i < k; i++)

    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
