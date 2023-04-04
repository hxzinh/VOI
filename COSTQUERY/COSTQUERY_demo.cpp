#include<bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
typedef long long ll;

#define MAX 100100

struct DisjointSetUnion
{
    int n;
    vector <int> par, size;

    DisjointSetUnion(int _n)
    {
        n = _n;
        par.assign(n + 5, -1);
        size.assign(n + 5, 1);
    }

    int Find(int u)
    {
        return par[u] < 0 ? u : par[u] = Find(par[u]);
    }

    void Join(int x, int y)
    {
        if (size[x] > size[y]) swap(x, y);
        par[x] = y;
        size[y] += size[x];
    }
};

int numNode, numQuery;
long long F[MAX];

struct Edge
{
    int u, v, c;

    bool operator < (const Edge & p)
    {
        return c < p.c;
    }
} edge[MAX];

void Shiba_Read()
{
    cin >> numNode >> numQuery;
    for (int i = 1; i < numNode; ++i)
        cin >> edge[i].u >> edge[i].v >> edge[i].c;
}

int Shiba_Solve(int x)
{
    int l = 1, r = numNode - 1, res = 0;
    while (l <= r)
    {
        int m = (l + r) >> 1;
        if (edge[m].c <= x)
        {
            res = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    return res;
}

int Shiba_Answer(int l, int r)
{
    return F[Shiba_Solve(r)] - F[Shiba_Solve(l - 1)];
}

void Shiba_Process()
{
    sort(edge + 1, edge + numNode);

    DisjointSetUnion dsu(numNode);

    for (int i = 1, u, v; i < numNode; ++i)
    {
        u = dsu.Find(edge[i].u), v = dsu.Find(edge[i].v);
        F[i] = F[i - 1] + 1LL * dsu.size[u] * dsu.size[v];
        dsu.Join(u, v);
    }

    while (numQuery--)
    {
        int l, r; cin >> l >> r;
        cout << Shiba_Answer(l, r) << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("COSTQUERY.INP", "r", stdin);
    freopen("COSTQUERY.OUT", "w", stdout);

    Shiba_Read();
    Shiba_Process();

    return 0;
}
