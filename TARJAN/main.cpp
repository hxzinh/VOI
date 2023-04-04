#include <bits/stdc++.h>
#define ll long long
#define oo INFINITY
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e5 + 10;
int n,m;
vector<int> a[NM], st;
pair<int, int> edges[NM];
int low[NM], num[NM]; /// the hien so ID va stt cua nut i
bool cx[NM];
int numScc = 0, cnt = 0;

void readfile(){
    freopen("TARJAN.INP","r",stdin);
    freopen("TARJAN.OUT","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> edges[i].first >> edges[i].second;
        a[edges[i].first].push_back(edges[i].second);
    }
    memset(num, -1, sizeof(num));
    memset(low, 0, sizeof(low));
    memset(cx, false, sizeof(cx));
}
void dfs(int u){
    low[u] = num[u] = ++cnt;
    st.push_back(u);
    cx[u] = true;
    for(int v : a[u]){
        if(num[v] == -1) dfs(v);
        if(cx[v]) low[u] = min(low[v], low[u]);
    }
    if(num[u] == low[u]){
        numScc++;
        while(true){
            int v = st.back(); st.pop_back();
            cx[v] = false;
            if(u == v) break;
        }
    }
}
void xuli(){
    for(int i = 1; i <= n; i++){
        if(num[i] == -1) dfs(i);
    }
    cout << numScc;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
