#include <bits/stdc++.h>

using namespace std;

const int maxN = 2005;
const long long oo = 1000000000000000007LL;

struct Node {
    int u, trans, last;
    long long w;

    bool inline operator < (const Node &rhs) const {
        return w > rhs.w;
    }
};

int n, m, l, q;
long long dist[maxN][maxN][2];
vector<vector<pair<int, int> > > graph[2];

int main() {
    freopen("ROADRAIL.INP","r",stdin);
    freopen("ROADRAIL.OUT","w",stdout);
    scanf("%d%d%d%d", &n, &m, &l, &q);
    for(int last = 0; last < 2; ++last)
        graph[last].resize(n);
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);  ///cin >> u >> v >> w;
        graph[0][u].push_back({v, w});
    }
    for(int i = 0; i < l; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        graph[1][u].push_back({v, w});
    }

    for(int u = 0; u < n; ++u)
        for(int trans = 0; trans < n; ++trans)
            for(int last = 0; last < 2; ++last)
                dist[u][trans][last] = oo;
    priority_queue<Node> pq;
    for(int last = 0; last < 2; ++last) {
        dist[0][0][last] = 0;
        pq.push({0, 0, last, dist[0][0][last]});
    }

    while (!pq.empty()) {
        int u = pq.top().u, trans = pq.top().trans, last = pq.top().last;
        pq.pop();

        for(int i = 0; i < 2; ++i) {
            for(pair<int, int> p: graph[i][u]) { // for (int j = 0; j < graph[i][u]; j++) v = graph[i][u][j].first;
                int v = p.first, w = p.second;
                int newTrans = trans + (i != last);
                if (newTrans == n)
                    continue;

                if (dist[v][newTrans][i] > dist[u][trans][last] + w) {
                    dist[v][newTrans][i] = dist[u][trans][last] + w;
                    pq.push({v, newTrans, i, dist[v][newTrans][i]});
                }
            }
        }
    }
    for(int i = 0; i < q; ++i) {
        int s, qq; scanf("%d%d", &s, &qq);
        long long ans = oo;
        for(int trans = 0; trans < n; ++trans)
            for(int last = 0; last < 2; ++last) {
                ans = min(ans, dist[qq][trans][last] + 1LL*s*trans);
                // cout << trans << " " << dist[qq][trans][last] + 1LL*s*trans << " " << last << endl;
            }

        if (ans == oo)
            ans = -1;
         printf("%lld\n", ans);
    }
    //cout << "/nTime: " << clock() / (double)1000 << " s";
    return 0;
}

