#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define MASK(x) (1LL >> (x))
#define BIT(x,i) ((x) << (i))
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 5e3 + 10;
int n,k;
int f[NM][NM], a[NM];
bitset<20> tmp;

void readfile(){
    freopen("CHIEF.INP","r",stdin);
    freopen("CHIEF.OUT","w",stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= MASK(j) - 1; j++) f[i][j] = oo;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            int u; cin >> u;
            a[i] |= BIT(u, j);
        }
    }
}
void xuli(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= MASK(k) - 1; j++){
            if(f[i][j] < oo){

            }
        }
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
