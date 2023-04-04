#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 205;
int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};
int n, m, p, q, s, t;
bool cx[NM][NM], ok[5];

struct Data {
    int u, v, cost;
    bool inline operator < (const Data &A) const {
        return cost > A.cost;
    }
};

void bfs(int x, int y){
    priority_queue<Data> pq;
    pq.push({x, y, 0});

    int cnt = 0;
    while(!pq.empty()){
        int x = pq.top().u, y = pq.top().v, cost = pq.top().cost;
        pq.pop();
        if(cnt == 1000000){
            cout << -1;
            return;
        }
        if(x == s && y == t){
            cout << cost;
            return;
        }
        ok[0] = ok[1] = ok[2] = ok[3] = true;
        for(int i = 1; i <= n; i++){
            for(int k = 0; k < 4; k++) if(ok[k]) {
                int u = x + dx[k] * i;
                int v = y + dy[k] * i;
                if(u <= 0 || u > n || v <= 0 || v > n) continue;
                if(cx[u][v]){
                    ok[k] = false;
                    continue;
                }
                pq.push({u, v, cost + 1});
            }
        }
    }
}
int main()
{
    FastIO
    freopen("QBBISHOP.INP", "r", stdin);
    freopen("QBBISHOP.OUT", "w", stdout);
    cin >> n >> m >> p >> q >> s >> t;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        cx[u][v] = true;
    }

    bfs(p, q);
    return 0;
}
