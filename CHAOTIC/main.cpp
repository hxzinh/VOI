#include <bits/stdc++.h>
#define int long long
#define oo 1e9
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = MASK(17);
int numCow, k;
int a[NM], f[20][NM];

void readfile(){
    freopen("CHAOTIC.INP", "r", stdin);
    freopen("CHAOTIC.OUT", "w", stdout);
    cin >> numCow >> k;
    for(int i = 1; i <= numCow; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= numCow; i++)
        for(int j = 1; j <= MASK(numCow) - 1; j++) f[i][j] = 0;
    for(int i = 1; i <= numCow; i++) f[i][MASK(i - 1)] = 1;
}
void xuli(){
    int mask = MASK(numCow) - 1;
    for(int j = 1; j <= mask; j++){
        for(int i = 1; i <= numCow; i++){
            for(int u = 1; u <= numCow; u++){
                if(!BIT(j, u - 1) && abs(a[u] - a[i]) > k && u != i){
                    int newMask = j | MASK(u - 1);
                    f[u][newMask] += f[i][j];
                }
            }
        }
    }
    int res = 0;
    for(int i = 1; i <= numCow; i++) res += f[i][mask];
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
