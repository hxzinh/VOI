#include <bits/stdc++.h>

#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

struct Disjoinset{
    int n;
    vector <int> F;

    Disjoinset(int _n = 0)
    {
        n = _n;
        F.assign(n+1,-1);
    }

    int root(int u)
    {
        if(F[u] < 0) return u;
        return F[u] = root(F[u]);
    }

    void join(int u,int v)
    {
        u = root(u);
        v = root(v);
        if(u == v) return;
        if(F[u] > F[v]) swap(u,v);
        F[u] += F[v];
        F[v] = u;
    }
    bool same(int u,int v)
    {
        return root(u) == root(v);
    }
};


int n,q;
int l[100005],r[100005],a[100005] , ans[100005];
set <ii> S;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    Disjoinset dsu(n);

    for(int i = 1 ; i <= q ; i++)
    {
        cin >> a[i] >> l[i] >> r[i];
        if(l[i] > r[i]) swap(l[i],r[i]);
    }

    for(int i = q / 2+1 ; i <= q ; i++)
    if(a[i] == 2) S.insert({l[i], r[i]});

    for(int i = 1 ; i <= q / 2 ; i++)
    if(S.find({l[i], r[i]}) == S.end())
    dsu.join(l[i], r[i]);

    for(int i = q ; i > q / 2 ; i--)
    if(a[i] == 2) dsu.join(l[i], r[i]);
    else ans[i] = dsu.same(l[i],r[i]);

    for(int i = q/2+1 ; i <= q ; i++)
    if(a[i] == 3)
    {
        if(ans[i]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
