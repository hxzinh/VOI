#include <bits/stdc++.h>
#define task "dsur"
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LID(x) (x << 1LL)
#define RID(x) ((x << 1LL) + 1LL)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pi;

const ll MAXN = 1e5 + 3;
const ll INF = 1e9 + 7;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rand(ll l, ll r)
{
    return uniform_int_distribution<ll>(l, r)(rng);
}

struct QUERY
{
    bool type;
    ll l, r, u, v;

    QUERY() {}

    QUERY(ll _u, ll _v, ll _t, ll _l, ll _r): u(_u), v(_v), type(_t), l(_l), r(_r) {}

    bool operator< (const QUERY& rhs)
    {
        return type > rhs.type;
    }
};

struct DSU_UPDATE
{
    ll l, r, u, su, v, sv;

    DSU_UPDATE() {}

    DSU_UPDATE(ll _l, ll _r, ll _u, ll _su, ll _v, ll _sv): l(_l), r(_r), u(_u), su(_su), v(_v), sv(_sv) {}
};

vector<QUERY> qr;
ll n, q, par[MAXN], sum[MAXN], ans[MAXN];
stack<DSU_UPDATE> updates;

ll find_par(ll u)
{
    if (u == par[u]) return u;
    return find_par(par[u]);
}

void merge_set(ll l, ll r, ll u, ll v)
{
    u = find_par(u), v = find_par(v);
    if (u == v) return;
    if (sum[u] < sum[v]) swap(u, v);
    updates.push(DSU_UPDATE(l, r, u, sum[u], v, sum[v]));
    par[v] = u;
    sum[u] += sum[v];
}

void solve(ll l, ll r, vector<QUERY>& curqr)
{
    if (l == r)
    {
        for (auto [tt, tl, tr, tu, tv] : curqr)
        {
            if (tt)
            {
                if (tl <= l && r <= tr) merge_set(l, r, tu, tv);
            }
            else
            {
                if (l <= tl && tl <= r)
                {
                    ans[tl] = (find_par(tu) == find_par(tv) ? 1 : -1);
                }
            }
        }
        while (!updates.empty())
        {
            auto [tl, tr, u, su, v, sv] = updates.top();
            if (!(tl == l && tr == r)) break;
            updates.pop();
            par[u] = u, sum[u] = su;
            par[v] = v, sum[v] = sv;
        }
        return;
    }

    vector<QUERY> qr2;
    for (auto _ : curqr)
    {
        auto [tt, tl, tr, tu, tv] = _;
        if (tt)
        {
            if (tl <= l && r <= tr) merge_set(l, r, tu, tv);
            else if (!(r < tl || tr < l)) qr2.pb(_);
        }
        else
        {
            if (l <= tl && tl <= r) qr2.pb(_);
        }
    }
//    for (auto [tt, tl, tr, tu, tv] : qr2) cerr << tt << " " << tl << " " << tr << " " << tu << " " << tv << endl;
//    cerr << endl;
    ll mid = (l + r) / 2;
    solve(l, mid, qr2);
    solve(mid + 1, r, qr2);
    while (!updates.empty())
    {
        auto [tl, tr, u, su, v, sv] = updates.top();
        if (!(tl == l && tr == r)) break;
//        cerr << tl << " " << tr << " - " << u << " " << v << endl;
        updates.pop();
        par[u] = u, sum[u] = su;
        par[v] = v, sum[v] = sv;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef OFFLINE
    freopen(task".inp", "r", stdin);
//    freopen(task".out", "w", stdout);
    #endif

    cin >> n >> q;
    map<pi, ll> stored;
    for (ll i = 1; i <= q; ++i)
    {
        ll t, u, v; cin >> t >> u >> v;
        if (u > v) swap(u, v);
        if (t == 1) stored[{u, v}] = i;
        else if (t == 2)
        {
            qr.pb(QUERY(u, v, 1, stored[{u, v}], i - 1));
            stored.erase({u, v});
        }
        else qr.pb(QUERY(u, v, 0, i, i));
    }
    for (auto e : stored) qr.pb(QUERY(e.fi.fi, e.fi.se, 1, e.se, q));
    sort(qr.begin(), qr.end());
    fill(sum + 1, sum + n + 1, 1);
    iota(par + 1, par + n + 1, 1);
    solve(1, q, qr);
    for (ll i = 1; i <= q; ++i)
    {
        if (ans[i] == 0) continue;
        cout << (ans[i] == 1 ? "YES\n" : "NO\n");
    }
    #ifdef OFFLINE
//    cout << flush;
//    fclose(stdin);
//    fclose(stdout);
    #endif
}
