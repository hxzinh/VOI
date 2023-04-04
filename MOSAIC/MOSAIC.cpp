#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 105;
int n, m, q;
bool cx[NM][NM];

void readfile(){
    freopen("MOSAIC.INP", "r", stdin);
    freopen("MOSAIC.OUT", "w", stdout);
    cin >> n >> m;
    cin >> q;
    for(int t = 1; t <= q; t++){
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        int l = min(u, x) + 1;
        int r = min(v, y) + 1;
        int d = max(u, x);
        int c = max(v, y);
        for(int i = l; i <= d; i++)
            for(int j = r; j <= c; j++) cx[i][j] = true;
    }
}
void xuli(){
    int res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) res += (!cx[i][j]);
    cout << res;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
