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

const int NM = 1e6 + 10;
int n, curTime = 0, cntQr = 0;
int p[NM];
char a[NM], c[NM];
vector<int> cur[27], edges[NM], vec;
bool ok[NM];

struct Data {
    int t;
    char u, v;
    int id;
};
Data query[NM];
vector<Data> qr;

void sub1() {
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        Data u = query[i];
        if(u.t == 1) {
            cnt++;
            a[cnt] = u.u;
        }
        else {
            for(int j = 1; j <= cnt; j++)
                if(a[j] == u.u) a[j] = u.v;
        }
    }

    for(int i = 1; i <= n; i++) cout << a[i];
}
void dfs(int u, char x) {
    a[u] = x;
    vec.push_back(u);
    ok[u] = true;
    for(int v : edges[u])
        if(!ok[v]) dfs(v, x);
}
void xuli() {
    int cntChar = 0;
    string k = "";
    for(int i = 1; i <= n; i++) {
        Data u = query[i];
        if(u.t == 1) {
            curTime++;
            a[curTime] = u.u;
            if(p[u.u - 'a']) edges[curTime].push_back(p[u.u - 'a']);
            p[u.u - 'a'] = curTime;
            k += u.u;
        }
        else {
            if(p[u.u - 'a']) {
                if(p[u.v - 'a']) {
                    edges[p[u.v - 'a']].push_back(p[u.u - 'a']);
                    p[u.u - 'a'] = 0;
                }
                else {
                    p[u.v - 'a'] = p[u.u - 'a'];
                    p[u.u - 'a'] = 0;
                }
            }
        }
    }

    for(int i = 0; i < 26; i++)
        if(p[i]) dfs(p[i], i + 'a');

    for(int i = 1; i <= curTime; i++) cout << a[i];
}
int32_t main()
{
    FastIO
    freopen("PAINT.INP", "r", stdin);
    freopen("PAINT.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int type;
        char u, v;
        cin >> type >> u;
        if(type == 2) cin >> v;
        query[i] = {type, u, v, i};
    }

    xuli();
    return 0;
}

/* Author: hxzinh */


