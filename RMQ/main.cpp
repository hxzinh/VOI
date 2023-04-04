#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1LL)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int n, q;
int a[NM];
int m[NM][25];

void readfile(){
    freopen("RMQ.INP", "r", stdin);
    freopen("RMQ.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void xuli(){
    for(int i = 1; i <= n; i++) m[i][0] = a[i];

    for(int k = 1; MASK(k) <= n; k++){
        for(int i = 1; i + MASK(k) - 1 <= n; i++){
            m[i][k] = min(m[i][k - 1], m[i + MASK(k - 1)][k - 1]);
        }
    }

    int u, v;
    while(q--){
        cin >> u >> v;
        int k = log2(v - u + 1);
        cout << min(m[u][k], m[v - MASK(k) + 1][k]) << " ";
    }
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
