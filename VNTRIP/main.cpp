#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e3 + 10;
int n, m, k;
int a[NM][NM], f[NM][NM], visit[NM];

struct Data {
    int v, cost;

    bool inline operator < (const Data &A) const {
        return cost > A.cost;
    }
};
vector<Data> edges[NM];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++) cin >> visit[i];
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = w;
        edges[u].push_back({v, w});
    }
}
void sub1(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) if(i != j) f[i][j] = (a[i][j] != 0 ? a[i][j] : INF);

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) minimize(f[i][j], f[i][k] + f[k][j]);
        }
    }

    int res = INF;
    do {
        int ans = f[1][visit[1]] + f[visit[k]][1];
        bool ok = true;
        for(int i = 1; i < k; i++){
            int u = visit[i], v = visit[i + 1];
            if(f[u][v] == INF){
                ok = false;
                break;
            }
            ans += f[u][v];
        }
        if(ok) minimize(res, ans);
    } while(next_permutation(visit + 1, visit + k + 1));
    cout << res;
}
int main()
{
    FastIO
    readfile();
    sub1();
    return 0;
}
