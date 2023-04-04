#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
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

const int NM = 2e5 + 10;
int n, q;
int a[NM], id[NM];

void xuli() {
    memset(id, 0, sizeof id);

    int L = 1;
    for(int i = 1; i <= n; i++) id[a[i]] = i;

    int res = 1;
    for(int i = 1; i <= n; i++) {
        if(L > id[i]) res++;
        L = id[i];
    }

    while(q--) {
        int u, v;
        cin >> u >> v;
        int r = a[u], s = a[v];

        swap(a[u], a[v]);

        if(id[r - 1] <= id[r] && id[r - 1] > v) res++;
        if(id[r - 1] > id[r] && id[r - 1] <= v) res--;
        if(id[r] <= id[r + 1] && v > id[r + 1]) res++;
        if(id[r] > id[r + 1] && v <= id[r + 1]) res--;
        id[r] = v;
        if(id[s - 1] <= id[s] && id[s - 1] > u) res++;
        if(id[s - 1] > id[s] && id[s - 1] <= u) res--;
        if(id[s] <= id[s + 1] && u > id[s + 1]) res++;
        if(id[s] > id[s + 1] && u <= id[s + 1]) res--;
        id[s] = u;

        cout << res << '\n';
    }
}
int32_t main()
{
    FastIO
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];

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
