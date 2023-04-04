#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mp make_pair
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int n, m, start;
ll s[NM], c[NM], numStep[NM], Low[NM], Num[NM], cntTime = 0, numNode = 0;
ll weight[NM], id[NM], f[NM];
vector<pair<ll, ll>> edges[NM], e[NM];
vector<ll> sumCost;
stack<int> st;
bool criticalNode[NM], inq[NM];

struct Data {
    ll u, cost;
};

void init() {
    int i = 1;
    while(s[i - 1] <= 100000000) {
        s[i] = s[i - 1] + i;
        c[i] = c[i - 1] + s[i];
        sumCost.push_back(s[i]);
        i++;
    }
}
void dfs(ll u, ll p) {
    Low[u] = Num[u] = ++cntTime;
    st.push(u);

    for(pll nxt : edges[u]) {
        ll v = nxt.fi, w = nxt.se;
        if(Num[v]) minimize(Low[u], Num[v]);
        else {
            dfs(v, u);
            minimize(Low[u], Low[v]);
        }
    }

    if(Num[u] == Low[u]) {
        numNode++;
        int v;

        do {
            v = st.top();
            st.pop();
            id[v] = numNode;
            Num[v] = Low[v] = INF;
        } while(v != u);
    }
}
void xuli() {
    init();
    for(int i = 1; i <= n; i++) if(!Num[i]) dfs(i, -1);

    for(int i = 1; i <= n; i++) {
        for(pll v : edges[i]) {
            if(id[i] == id[v.fi]) {
                int it = upper_bound(ALL(sumCost), v.se) - sumCost.begin() + 1;
                if(it > 1) {
                    it--;
                    weight[id[i]] += v.se * (it + 1) - c[it];
                }
            } else {
                e[id[i]].push_back({id[v.fi], v.se});
            }
        }
    }

    queue<ll> q;
    f[id[start]] = weight[id[start]];
    q.push(id[start]);
    inq[id[start]] = true;

    while(q.size()) {
        ll u = q.front();
        q.pop();

        inq[u] = false;

        for(pll v : e[u]) {
            if(maximize(f[v.fi], f[u] + v.se + weight[v.fi])) {
                if(!inq[v.fi]) q.push(v.fi);
            }
        }
    }

    ll res = 0;
    for(int i = 1; i <= numNode; i++) maximize(res, f[i]);
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("GOLDEN.INP", "r", stdin);
    freopen("GOLDEN.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
    }
    cin >> start;

    xuli();
    return 0;
}
