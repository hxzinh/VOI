#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e5 + 10;
const int MOD = 123456789;
int q, n, k;
int f[10][NM], g[10][NM], h[10][NM];

void readfile(){
    freopen("TRIPLE.INP", "r", stdin);
    freopen("TRIPLE.OUT", "w", stdout);
    cin >> q;
}
void triple(int x, int d){
    if(g[x][d] != -1 || h[x][d] != 0) return;
    if(d == 0){
        g[x][0] = x % MOD;
        h[x][0] = 10 % MOD;
        return;
    }
    int u = x * 3;
    int v = 1LL * (x * 3) / 10;
    if(v == 0){
        triple(u, d - 1);
        g[x][d] = g[u][d - 1];
        h[x][d] = h[u][d - 1];
    } else {
        triple(v, d - 1);
        triple(u % 10, d - 1);
        g[x][d] = (g[v][d - 1] * h[u % 10][d - 1] + g[u % 10][d - 1]) % MOD;
        h[x][d] = (h[v][d - 1] * h[u % 10][d - 1]) % MOD;
    }
    return;
}
void xuli(){
    memset(g, -1, sizeof(g));
    vector<int> t;
    while(q--){
        cin >> k >> n;

        t.clear();
        while(k != 0){
            t.push_back(k % 10);
            k /= 10;
        }

        int res = 0;
        for(int i = t.size() - 1; i >= 0; i--){
            int u = t[i];
            triple(u, n);
            res = (res * h[u][n] + g[u][n]) % MOD;
        }
        cout << res << '\n';
    }
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
