#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int n, numL = 0;
int f[NM], t[NM];
vector<int> edges[NM];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> t[i];
    for(int i = 2; i <= n; i++){
        int u; cin >> u;
        edges[u].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        if(edges[i].empty()){
            numL++;
            f[i] = 1;
        }
    }
}
void dfs(int x){
    if(edges[x].empty()){
        f[x] = 1;
        return;
    }
    if(t[x]) f[x] = INF;
    else f[x] = 0;
    for(int v : edges[x]){
        dfs(v);
        if(t[x]) f[x] = min(f[x], f[v]);
        else f[x] += f[v];
    }
}
void xuli(){
    dfs(1);
    cout << numL - f[1] + 1;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
