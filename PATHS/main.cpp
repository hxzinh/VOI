#include <bits/stdc++.h>
#define ll long long
#define oo 1e18
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=550;
ll T,n,m;
ll s[NM][NM],r[NM][NM], w[NM][NM], numRoad[NM][NM];
bool cx[NM][NM];
ll a[NM][NM];
///-----------------------------------------------------------------------------///
struct Path
{
    ll u,fa,cost;
    bool inline operator < (const Path &A) const {
        return cost > A.cost;
    }
};
priority_queue <Path> pq;

void readfile(){
    freopen("paths.inp","r",stdin);
    freopen("paths.out","w",stdout);
    cin >> T;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            w[i][j] = a[i][j] = oo;
            numRoad[i][j] = 0;
        }
        w[i][i] = 0;
    }
    for(int j = 1; j <= m; j++){
        ll u,v,cost;
        cin >> u >> v >> cost;
        w[u][v] = w[v][u] = cost;
        a[u][v] = a[v][u] = cost;
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++) s[i][j] = oo;
    memset(cx,true,sizeof(cx));
}
void full(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
                if(w[i][j] > w[i][k] + w[j][k])
                    w[i][j] = w[i][k] + w[j][k];
            }
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
                if(w[i][j] == w[i][k] + a[j][k] && w[i][j] != oo) numRoad[i][j]++;
            }
    }
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            int res = 0;
            for(int k = 1; k <= n; k++)
                if(w[i][j] == w[i][k] + w[j][k]) res += numRoad[i][k];
            cout << res << " ";
        }
        cout << '\n';
    }
}
int main(){
    FastIO
    readfile();
    full();
    return 0;
}
