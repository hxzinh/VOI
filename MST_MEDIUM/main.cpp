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
vector<ii> check;
bool cx[NM];

struct Data {
    int u, v, w, pos;

    bool inline operator < (const Data &a) const {
        return w > a.w;
    }
};
Data edges[NM];
priority_queue<Data> pq;

struct DijoinsetUnion {
    int n;
    vector<int> par;

    DijoinsetUnion(int _n = 0){
        n = _n;
        par.assign(n + 7, -1);
    }

    int root(int x){
        if(par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool join(int u, int v){
        int x = root(u), y = root(v);
        if(x == y) return 0;
        if(par[x] > par[x]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    bool check(int x, int y){
        return root(x) != root(y);
    }
};

void readfile(){
    freopen("MST.INP", "r", stdin);
    freopen("MST.OUT", "w", stdout);
    cin >> sub;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[i].u = u, edges[i].v = v, edges[i].w = w, edges[i].pos = i;
    }
    memset(cx, false, sizeof cx);
    memset(t, -1, sizeof t);
}
bool cmp(const Data &a, const Data &b){
    return a.w < b.w;
}
void xuli(){
    DijoinsetUnion dsu(m);
    sort(edges + 1, edges + m + 1, cmp);
    int tam = -1;
    for(int i = 1; i <= m; i++){
        while(i < tam) i++;
        int j = i;
        while(edges[j].w == edges[j + 1].w && j <= m) j++;
        check.push_back(make_pair(i, j));
        tam = j;
    }
    for(auto x : check){
        int l = x.fi, r = x.se;
        for(int i = l; i <= r; i++){
            if(dsu.check(edges[i].u, edges[i].v)) cx[edges[i].pos] = true;
        }
        for(int i = l; i <= r; i++) dsu.join(edges[i].u, edges[i].v);
    }
    for(int i = 1; i <= m; i++)
        if(cx[i]) cout << "YES" << " ";
        else cout << "NO" << " ";
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
