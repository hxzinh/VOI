#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef long long ll;

const int N = 1003;
bitset<N> adj[N];
int m, n;

void process() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        adj[u][v] = 1;
    }

    ll res(0);
    for (int u = 1; u <= n; ++u) {
        for (int v = u + 1; v <= n; ++v) {
            int z = (adj[u] & adj[v]).count();
            res += z * (z - 1) / 2;
        }
    }

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("FESTIVAL.inp", "r", stdin);
    freopen("FESTIVAL.out", "w", stdout);

    process();
    return 0;
}