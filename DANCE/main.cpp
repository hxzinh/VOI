#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
#define ii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e5 + 10;
int n, m;
int t[NM];
vector<int> a[NM], par[NM], canUse[NM];
pair<int, int> p[NM];
bool ok[NM];
map<int, int> cx[NM];

void readfile(){
    freopen("DANCE.INP", "r", stdin);
    freopen("DANCE.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        par[v].push_back(v);
        cx[u][v] = 1;
        p[i] = make_pair(u, v);
    }
}
bool tmp(const ii &a, const ii &b){
    return a.fi < b.fi;
}
int getRes(int u, int v){
    int res = 0;
    for(int k : a[u]) if(cx[u][k] == 1 && cx[v][k] == 1) res++;
    return res * (res - 1) / 2;
}
void prepare(){
    memset(ok, true, sizeof(ok));
    sort(p + 1, p + m + 1, tmp);
    for(int i = 1; i <= m; i++)
        if(p[i].fi != p[i + 1].fi) t[p[i].fi] = i;

    for(int i = 1; i <= n; i++){
        for(auto u : a[i]) canUse[i].insert(canUse[i].end(), ALL(par[u]));
        sort(ALL(canUse[i]));
        canUse[i].resize(unique(ALL(canUse[i])) - canUse[i].begin());
    }

    int res = 0;
    for(int i = 1; i <= n; i++){
        ok[i] = false;
        for(auto u : canUse[i]) if(ok[u]) {
            res += getRes(i, u);
        }
    }
    cout << res;
}

int32_t main()
{
    FastIO
    readfile();
    prepare();
    return 0;
}
