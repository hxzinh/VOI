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

const int NM = 1005;
int n, m;
ll T;
string mod;

struct Data {
    int type, u, v;
} a[NM];

int32_t main()
{
    FastIO
    freopen("THBAC.INP", "r", stdin);
    freopen("THBAC.OUT", "w", stdout);
    cin >> n >> m >> T;
    cin >> mod;
    for(int i = 0; i < m; i++) {
        string type;
        int u, v;
        cin >> type >> u >> v;
        if(type == "die") a[i].type = 0;
        if(type == "reproduce") a[i].type = 1;
        if(type == "copy") a[i].type = 2;
        if(type == "teleport") a[i].type = 3;
        if(type == "swap") a[i].type = 4;
        if(type == "merry-go-round") a[i].type = 5;
    }
    return 0;
}

/* Author: hxzinh */


