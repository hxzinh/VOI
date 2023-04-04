
#include <bits/stdc++.h>
#define int long long
#define oo 2e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 5e3 + 10;
int n,m;
int low[NM], num[NM];
bool cx[NM];
int numSCC = 0, cnt = 0;
vector<int> child[NM];
stack<int> st;

struct Data{
    int from, to, cost;

    Data(int _from = 0,int _to = 0,int _cost = 0){
        from = _from;
        to = _to;
        cost = _cost;
    }

    bool inline operator < (Data &A) const {
        return cost < A.cost;
    }
};
Data a[NM];

void readfile(){
    freopen("SCC.INP","r",stdin);
    freopen("SCC.OUT","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a[i].from >> a[i].to >> a[i].cost;
    }
    sort(a + 1, a + m + 1);
}
void dfs(int u){
    low[u] = num[u] = ++cnt;
    st.push(u);
    for(int v : child[u]) if(!cx[v]) {
        if(num[v] == -1) dfs(v);
        low[u] = min(low[u], low[v]);
    }

    if(num[u] == low[u]){ ///day la nut quan trong
        if(++numSCC > 1) return;
        while(true){
            int v = st.top(); st.pop();
            cx[v] = true;
            if(u == v) break;
        }
    }
}
bool ok(int l,int r){
    if(l > r) return false;
    memset(low, 0, (n + 1)*sizeof(int));
    memset(num, -1, (n + 1)*sizeof(int));
    memset(cx, false, (n + 1)*sizeof(bool));
    while(!st.empty()) st.pop();
    cnt = numSCC = 0;
    for(int i = 1; i <= n; i++) child[i].clear();
    for(int i = l; i <= r; i++)
        child[a[i].from].push_back(a[i].to);
    for(int i = 1; i <= n; i++){
        if(num[i] == -1){
            dfs(i);
        }
    }
    if(numSCC == 1) return true;
    else return false;
}
void xuli(){
    int res = oo;
    int r = 1;
    for(int l = 1; l <= m; l++){
        while(!ok(l, r) && r <= m) r++;
        if(r > m) break;
        res = min(res, a[r].cost - a[l].cost);
    }
    if(res < oo) cout << res;
    else cout << -1;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
