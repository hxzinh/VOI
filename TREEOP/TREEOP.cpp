#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int n, q;
vector <int> V[2002];
int f[2002][20], depth[2002];
long long D[2002][2002];

void Dfs(int u, int p)
{
    for(int v : V[u]) if(v != p)
    {
        depth[v] = depth[u] + 1;
        f[v][0] = u;
        Dfs(v, u);
    }
}

int lca(int x, int y)
{
    for(int k = 15; k >= 0; k--)
        if(depth[f[x][k]] >= depth[y])
            x = f[x][k];

    for(int k = 15; k >= 0; k--)
        if(depth[f[y][k]] >= depth[x])
            y = f[y][k];

    if(x == y) return x;

    for(int k = 15; k >= 0; k--)
        if(f[x][k] != f[y][k])
        {
            x = f[x][k];
            y = f[y][k];
        }

    return f[x][0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("TREEOP.INP", "r", stdin);
    freopen("TREEOP.OUT", "w", stdout);

    cin >> n >> q;
    for(int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }
    Dfs(1, -1);
    for(int k = 1; 1 << k <= n; k++)
    for(int i = 1; i <= n; i++)
    f[i][k] = f[f[i][k - 1]][k - 1];

    for(int i = 1; i <= n; i++) for(int j = i; j <= n; j++) D[i][j] = D[j][i] = 1LL*i * j *(depth[i] + depth[j] - 2 * depth[lca(i, j)]) % MOD;

    vector <int> T;
    while(q--)
    {
        T.clear();
        int k;
        long long ans = 0;
        cin >> k;
        for(int i = 1; i <= k; i++)
        {
            int x; cin >> x;
            T.push_back(x);
        }
        if(k <= 1)
        {
            cout << 0 << '\n';
            continue;
        }

        for(int i = 1; i < k; i++)
        for(int j = 0; j < i; j++)
        {
            ans += D[T[i]][T[j]];
            ans = ans%MOD;
        }
        cout << ans % MOD << '\n';
    }
    return 0;
}
