#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, m;
int a[NM], f[NM][5], par[NM][5];
bool cx[NM];
vector<int> edges[NM], trace[NM], T;

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    memset(par, -1, sizeof(par));
    memset(cx, true, sizeof(cx));
}
int getDist(int x, int t){
    if(t < 1) return 0;
    if(edges[x].empty()) return a[x];
    int newDist = 0;
    cx[x] = false;
    for(int v : edges[x]) if(cx[v] && v != x) {
        if(maximize(newDist, getDist(v, t - 1))){
            trace[x].clear();
            trace[x].push_back(v);
            trace[x].insert(trace[x].end(), ALL(trace[v]));
        }
    }
    cx[x] = true;
    return newDist + a[x];
}
void xuli(){
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(maximize(res, getDist(i, 4))){
            T.push_back(i);
            T.insert(T.end(), ALL(trace[i]));
        }
    }
    cout << res << '\n';
    for(int u : T) cout << u << " ";
}
void sub1(){
    int res = 0, ans = 0;
    for(int i = 1; i <= n; i++){
        cx[i] = false;
        int newRes = a[i];
        for(int u : edges[i]) if(cx[u]) {
            cx[u] = false;
            newRes += a[u];
            for(int v : edges[u]) if(cx[v]) {
                cx[v] = false;
                newRes += a[v];
                for(int k : edges[v]) if(cx[k]) {
                    newRes += a[k];
                    if(maximize(res, newRes)){
                        T.clear();
                        T.push_back(i);
                        T.push_back(u);
                        T.push_back(v);
                        T.push_back(k);
                    }
                    newRes -= a[k];
                }
                newRes -= a[v];
                cx[v] = true;
            }
            newRes -= a[u];
            cx[u] = true;
        }
        cx[i] = true;
    }
    cout << res << '\n';
    for(int i : T) cout << i << " ";
}
int32_t main()
{
    FastIO
    readfile();
    sub1();
    return 0;
}
