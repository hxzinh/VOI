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

int dx[] = {1, 0};
int dy[] = {0, 1};

const int NM = 1e6 + 10;
int n, m, k;
int s[NM];
vector<vector<char>> a;

void xuli() {
    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= m; j++) {
            if(a[i - 1][j] == 'X' && a[i][j - 1] == 'X') s[j] = 1;
        }
    }

    for(int i = 2; i <= m; i++) s[i] += s[i - 1];

    while(k--) {
        int u, v;
        cin >> u >> v;
        if(s[v] - s[u] == 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("CODE.INP", "r", stdin);
    freopen("CODE.OUT", "w", stdout);
    cin >> n >> m;
    a.assign(n + 2, vector<char>(m + 2, '.'));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    cin >> k;

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
