#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 5e5 + 10;
int n, m, b, r;
int tent[NM], store[NM], t[NM];
vector<int> edges[NM];
///--------------------------------sub1-----------------------------------
bool cx[2005], ok[NM];

struct Data {
    int u, cost;
    bool inline operator < (const Data &A) const {
        return cost > A.cost;
    }
};

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n >> m >> b >> r;
    for(int i = 1; i <= b; i++) cin >> store[i];
    for(int i = 1; i <= r; i++) cin >> tent[i];
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
}
void full(){
    queue<Data> q;
    for(int i = 1; i <= n; i++) t[i] = INF;
    for(int i = 1; i <= b; i++){
        t[store[i]] = 0;
        q.push({store[i], 0});
    }
    while(!q.empty()){
        int u = q.front().u, cost = q.front().cost;
        q.pop();
        if(t[u] != cost) continue;
        for(int v : edges[u]) if(t[v] > cost + 1) {
            t[v] = cost + 1;
            q.push({v, cost + 1});
        }
    }
    for(int i = 1; i <= r; i++) cout << t[tent[i]] << " ";
}
int main()
{
    FastIO
    readfile();
    full();
    return 0;
}
