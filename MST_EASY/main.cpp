#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define ii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 5e5 + 10;
int n, m, sub;
int t[NM];
vector<int> ans;
bool cx[NM];

struct Data {
    int u, v, w, pos;

    bool inline operator < (const Data &a) const {
        return w > a.w;
    }
};
Data edges[NM];
priority_queue<Data> pq;

void readfile(){
    freopen("MST.INP", "r", stdin);
    freopen("MST.OUT", "w", stdout);
    cin >> sub;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[i].u = u, edges[i].v = v, edges[i].w = w, edges[i].pos = i;
        pq.push({u, v, w, i});
    }
    memset(cx, false, sizeof cx);
    memset(t, -1, sizeof t);
}
bool cmp(const Data &a, const Data &b) {
    return a.w < b.w;
}
int root(int x){
    if(t[x] == -1) return x;
    else return t[x] = root(t[x]);
}
void xuli(){
    int cnt = 0, res = 0;
    /**
    while(!pq.empty()){
        int u = pq.top().u; u = root(u);
        int v = pq.top().v; v = root(v);
        int pos = pq.top().pos;
        int cost = pq.top().w;
        pq.pop();
        if(u != v){
            cnt++;
            t[max(u, v)] = min(u, v);
            ans.push_back(pos);
        }
        if(cnt == n - 1) break;
    }
    **/

    sort(edges + 1, edges + m + 1, cmp);
    for(int i = 1; i <= m; i++){
        int u = root(edges[i].u);
        int v = root(edges[i].v);
        if(u == v) continue;
        t[max(u, v)] = min(u, v);
        ans.push_back(edges[i].pos);
        if(++cnt == n - 1) break;
    }
    for(auto u : ans) cout << u << " ";
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
