#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e5 + 10;
int n, m;
int numKid = 0;
int visited[NM];
vector<int> edges[NM], caveMom, A, B;
bool cx[NM];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
}
void dfs(int x){
    if(visited[x] == 2) return;
    if(++visited[x] == 2){
        caveMom.pop_back();
        numKid++;
        B.push_back(x);
        if(n - caveMom.size() == 2 * numKid) return;
    } else {
        caveMom.push_back(x);
        if(n - caveMom.size() == 2 * numKid) return;
        for(int v : edges[x]) if(!visited[v]) dfs(v);
        dfs(x);
    }
}
void xuli(){
    stack<int> s;
    s.push(1);
    while(!s.empty()){
        int u = s.top();
        s.pop();
        if(visited[u] == 2) continue;
        if(++visited[u] == 2){
            caveMom.pop_back();
            numKid++;
            B.push_back(u);
            if(n - caveMom.size() == 2 * numKid) break;
            continue;
        } else {
            s.push(u);
            caveMom.push_back(u);
            if(n - caveMom.size() == 2 * numKid) break;
            for(int v : edges[u]) if(!visited[v]) s.push(v);
        }
    }

    cout << caveMom.size() << " " << numKid <<  '\n';
    for(int u : caveMom){
        cout << u << " ";
        cx[u] = true;
    }
    cout << '\n';
    for(int u : B){
        cout << u << " ";
        cx[u] = true;
    }
    cout << '\n';
    for(int i = 1; i <= n; i++) if(!cx[i]) cout << i << " ";
}
void full(){
    dfs(1);
    cout << caveMom.size() << " " << numKid <<  '\n';
    for(int u : caveMom){
        cout << u << " ";
        cx[u] = true;
    }
    cout << '\n';
    for(int u : B){
        cout << u << " ";
        cx[u] = true;
    }
    cout << '\n';
    for(int i = 1; i <= n; i++) if(!cx[i]) cout << i << " ";
}
int main()
{
    FastIO
    readfile();
    full();
    return 0;
}
