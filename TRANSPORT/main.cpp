#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define ii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, start;
int f[NM], high[NM], child[NM];
vector<ii> edges[NM];

struct Data {
    int u, cost;
    bool inline operator < (const Data &A) const {
        return cost > A.cost;
    }
};

void readfile(){
    freopen("TRANSPORT.INP", "r", stdin);
    freopen("TRANSPORT.OUT", "w", stdout);
    cin >> n >> start;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        edges[u].push_back({v, 0});
        edges[v].push_back({u, 0});
    }
}
int dfs(int x, int par){
    int maxx = -INF, minn = INF, cntChild = 0;
    for(ii &v : edges[x]) if(v.fi != par){
        v.se = dfs(v.fi, x);
        maximize(maxx, v.se);
        minimize(minn, v.se);
        cntChild++;
    }
    if(!cntChild) return 0;
    int cnt = 0;
    for(ii v : edges[x]) if(v.fi != par) {
        if(v.se == maxx) cnt++;
    }
    return max(minn + cntChild, maxx + cnt);
}
void xuli(){
    cout << dfs(start, 0);
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
