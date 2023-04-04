#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

/**
//PRAGMA
#pragma GCC target("popcnt")
**/

/**
//ordered_set
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pii,
             null_type,
             less<pii>,
             rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;
**/

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e5 + 10;
int n, q;
int par[NM], ans[NM];

struct Data {
    string type;
    int k, u, v;
} a[NM];

struct Save {
    int k, u, v, id;
};
vector<Save> vec;

int root(int x) {
    if(par[x] < 0) return x;
    return par[x] = root(par[x]);
}

bool join(int u, int v) {
    u = root(u);
    v = root(v);
    if(u == v) return false;

    if(par[u] > par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
    return true;
}

int check(int u, int v) {
    u = root(u);
    v = root(v);
    if(u == v) return 1;
    else return -1;
}

void xuli() {
    memset(par, -1, sizeof par);

    sort(ALL(vec), [](const Save A, const Save B){
        return A.k < B.k;
    });

    int curId = 0, cnt = 0;
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i].k > 0) break;
        ans[vec[i].id] = -1;
        curId = i + 1;
    }

    for(int i = 1; i <= q; i++) {
        Data u = a[i];
        if(u.type == "Q") continue;

        if(u.type == "C") {
            cnt++;
            for(int j = curId; j < vec.size(); j++) {
                Save cur = vec[j];
                if(cur.k > cnt) break;
                ans[cur.id] = check(cur.u, cur.v);
                curId = j + 1;
            }
        }
        if(u.type == "?") ans[i] = check(u.u, u.v);
        if(u.type == "A") join(u.u, u.v);
    }

    for(int i = 1; i <= q; i++) {
        if(ans[i] == 1) cout << "Y";
        if(ans[i] == -1) cout << "N";
    }
}
int32_t main()
{
    FastIO
    freopen("VCS.INP", "r", stdin);
    freopen("VCS.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= q; i++) {
        string type;
        int k = 0, u = 0, v = 0;
        cin >> type;
        if(type == "Q")  {
            cin >> k >> u >> v;
            vec.push_back({k, u, v, i});
            a[i] = {type, k, u, v};
        }
        else
        if(type == "C") a[i] = {type, 0, 0, 0};
        else {
            cin >> u >> v;
            a[i] = {type, k, u, v};
        }
    }

    xuli();
    return 0;
}

/* Author: hxzinh */


