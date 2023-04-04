#include <bits/stdc++.h>
#define ll long long
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define oo 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 7e4 + 10;
int n;
int a[20][NM], f[20][NM];

void readfile(){
    freopen("TRIP.INP","r",stdin);
    freopen("TRIP.OUT","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= MASK(n) - 1; j++) f[i][j] = oo;
    for(int i = 1; i <= n; i++) f[i][MASK(i - 1)] = 0;
}
void xuli(){
    int res = oo;
    for(int j = 1; j <= MASK(n) - 1; j++){
        for(int i = 1; i <= n; i++){
            if(f[i][j] != oo){
                for(int v = 1; v <= n; v++){
                    if(i != v && !BIT(v - 1, j))
                        f[v][j | MASK(v - 1)] = min(f[v][j | MASK(v - 1)], f[i][j] + a[i][v]);
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) res = min(res, f[i][MASK(n) - 1]);
    cout << res << " ";
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
