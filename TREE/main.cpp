#include <bits/stdc++.h>
#define int long long
#define oo 99999999999
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 5e5 + 10;
int n, m, k, sub, numTest;
int pre[NM], nxt[NM], cnt = 0, visitedNode[NM];
bool cx[NM];
vector<int> a[NM];

void markVisited(int x){
    cx[x] = true;
    pre[nxt[x]] = pre[x];
    nxt[pre[x]] = nxt[x];
}

void bfs(int x){
    queue<int> q;
    q.push(x);
    markVisited(x);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        cnt = 0;
        int i = 0;
        for(int v = nxt[0]; v <= n; v = nxt[v]){
            while(i < (int)a[u].size() && a[u][i] < v) i++;
            if(i < (int)a[u].size() && a[u][i] == v) continue;
            visitedNode[cnt++] = v;
        }
        for(int j = 0; j < cnt; j++){
            int v = visitedNode[j];
            q.push(v);
            markVisited(v);
        }
    }
}
void xuli(){
    for(int i = 0; i <= n; i++){
        pre[i + 1] = i;
        nxt[i] = i + 1;
    }
    memset(cx, false, (n + 1) * sizeof(bool));

    int numComp = 0;
    for(int i = 1; i <= n; i++) if(!cx[i]) {
        if(++numComp > 1) {cout << "No" << " "; return;}
        bfs(i);
    }

    for(int i = 1; i <= n; i++){
        pre[i + 1] = i;
        nxt[i] = i + 1;
    }
    memset(cx, false, (n + 1)*sizeof(bool));
    markVisited(1);

    numComp = 0;
    for(int i = 2; i <= n; i++) if(!cx[i]) {
        if(++numComp > k){cout << "No" << " "; return;}
        bfs(i);
    }
    cout << "Yes" << " ";
    return;
}
void readfile(){
    freopen("TREE.INP", "r", stdin);
    freopen("TREE.OUT", "w", stdout);
    cin >> sub >> numTest;
    while(numTest--){
        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++) a[i].clear();
        for(int i = 0; i < m; i++){
            int u, v; cin >> u >> v;
            if(u == v) continue;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for(int i = 1; i <= n; i++) if(!a[i].empty()) {
            sort(ALL(a[i]));
            a[i].resize(unique(ALL(a[i])) - a[i].begin());
        }
        if(n == 1) {cout << (k == 0 ? "Yes" : "No") << " "; continue;}
        if(k == 0) {cout << "No" << " "; continue;}
        int tam = a[1].size();
        if(n - 1 - a[1].size() < k) {cout << "No" << " "; continue;}
        xuli();
    }
}
int32_t main()
{
    FastIO
    readfile();
    return 0;
}
