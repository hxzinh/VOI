#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
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

char b[] = {'G', 'S', 'P', 'V', 'H', 'C', 'U', 'T', 'E'};
int m, k, dem = 0;
int cnt[1000], f[1000];
vector<int> edges[1000];

struct Data {
    char u;
    int cnt;
} a[100];

void backtrack(int x) {
    for(int i = 0; i < 9; i++) if(cnt[b[i]]) {
        bool ok = false;
        for(int v : edges[x]) if(f[v] == i && v < x) {
            ok = true;
            break;
        }
        if(ok) continue;

        dem++;
        f[x] = i;
        if(dem == k){
            for(int i = 1; i <= x; i++) cout << b[f[i]];
            exit(0);
        }
        cnt[b[i]]--;
        backtrack(x + 1);
        cnt[b[i]]++;
    }
}
void xuli(){
    backtrack(1);
}
int32_t main()
{
    FastIO
    freopen("CONNECTCHAR.INP", "r", stdin);
    freopen("CONNECTCHAR.OUT", "w", stdout);
    for(int i = 0; i < 9; i++){
        cin >> cnt[b[i]];
        a[i].u = b[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cin >> k;
    sort(b, b + 9);

    xuli();
    return 0;
}

/* Author: hxzinh */

/*
-----code ko bug-----code ko bug-----code ko bug--------------

          _.-/`)
         // / / )
      .=// / / / )
     //`/ / / / /
    // /     ` /
   ||         /
    \\       /
     ))    .'
    //    /
         /
*/
