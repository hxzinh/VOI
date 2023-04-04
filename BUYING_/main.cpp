#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 3e3 + 10;
int n;
ll f[NM][NM][5];

struct Data{
    ll costA, costB, costC;
    ll dist;

    Data(ll _costA = 0, ll _costB = 0, ll _costC = 0){
        costA = _costA; costB = _costB; costC = _costC;
        dist = costB - costA;
    }

    bool inline operator < (const Data &A) const {
        return dist < A.dist;
    }
};
Data a[NM];

bool minimize(ll &a, ll b){
    if(a > b){a = b; return 1;}
    else return 0;
}

void readfile(){
    freopen("BUYING.INP", "r", stdin);
    freopen("BUYING.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        ll u, v, w; cin >> u >> v >> w;
        a[i] = Data(u, v, w);
    }
    for(int i = 0; i <= n; i++)
    for(int j = 0; j <= n; j++) f[i][j][0] = f[i][j][1] = INF;
    f[0][0][0] = 0;
}
void xuli(){
    sort(a + 1, a + n + 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            for(int cxA = 0; cxA < 2; cxA++) if(f[i][j][cxA] < INF){
                minimize(f[i + 1][j][1], f[i][j][cxA] + a[i + 1].costA);
                if(cxA == 0) minimize(f[i + 1][j][0], f[i][j][cxA] + a[i + 1].costB - (i - j));
                minimize(f[i + 1][j + 1][cxA], f[i][j][cxA] + a[i + 1].costC - j);
            }
        }
    }
    ll res = INF;
    for(int i = 0; i <= n; i++){
        res = min({res, f[n][i][1], f[n][i][0]});
    }
    cout << res;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
