#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 505;
const int MAX = 1e5 + 10;
int n, m;
int ans[MAX];
int s[NM][NM], numRoad[NM][NM];
vector<int> edges[NM];

struct Data {
    int u, cost;

    bool inline operator < (const Data &A) const {
        return cost > A.cost;
    }
};

struct Road {
    int u, v, cost;
} a[MAX], par[NM][NM];

void dijtra(int start, int s[], int numRoad[], Road par[]){
    priority_queue<Data> pq;
    pq.push({start, 0});
    s[start] = 0;
    numRoad[start] = 1;

    while(pq.size()){
        int u = pq.top().u, cost = pq.top().cost;
        pq.pop();
        if(cost != s[u]) continue;
        for(int i : edges[u]){
            int v = a[i].u ^ a[i].v ^ u, cost = a[i].cost;
            if(minimize(s[v], s[u] + cost)){
                numRoad[v] = numRoad[u];
                par[v] = {u, i, cost};
                pq.push({v, s[v]});
            } else if(s[u] + cost == s[v]) numRoad[v] += numRoad[u];
        }
    }
}
bool check(int u, int v, int cost, int start, int fin){
    if(s[start][u] + cost + s[v][fin] == s[start][fin] && numRoad[start][u] * numRoad[v][fin] == numRoad[start][fin]) return 1;
    if(s[start][v] + cost + s[u][fin] == s[start][fin] && numRoad[start][v] * numRoad[u][fin] == numRoad[start][fin]) return 1;
    return 0;
}
void xuli(){
    memset(s, INF, sizeof s);
    for(int i = 1; i <= n; i++) dijtra(i, s[i], numRoad[i], par[i]);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < i; j++){
            int v = j;
            while(v != i){
                int u = par[i][v].u, id = par[i][v].v, cost = par[i][v].cost;
                if(check(u, v, cost, i, j)) ans[id]++;
                v = u;
            }
        }
    }
    for(int i = 1; i <= m; i++) cout << ans[i] << '\n';
}
int32_t main()
{
    FastIO
    freopen("CANDY.INP", "r", stdin);
    freopen("CANDY.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back(i);
        edges[v].push_back(i);
        a[i] = {u, v, w};
    }
    xuli();
    return 0;
}
