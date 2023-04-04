#include <bits/stdc++.h>
#define ll long long
#define INF INT_MAX
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FASTIO

using namespace std;
const int NM = 1e3 + 10;
int r, c, k;
int a[NM][10], s[NM][MASK(5)], f[NM][2010][MASK(5)];
vector<int> t;

void maximize(int &a, int b){
    if(a < b) {a = b; return;}
    else return;
}
void readfile(){
    freopen("JUMP.INP", "r", stdin);
    freopen("JUMP.OUT", "w", stdout);
    cin >> r >> c >> k;
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++) cin >> a[i][j];
}
bool check(int mask){
    for(int i = 1; i <= c; i++)
        if(BIT(mask, i - 1) && BIT(mask, i)) return false;
    return true;
}
void progress(){
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            int mask = MASK(j - 1);
            s[i][mask] = a[i][j];
            for(int v = j + 2; v <= c; v++){
                int newMask = mask | MASK(v - 1);
                s[i][newMask] = s[i][mask] + a[i][v];
            }
        }
    }
    for(int i = 0; i < MASK(c); i++)
        if(check(i)) t.push_back(i);

    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= k; j++)
            for(int mask : t) f[i][j][mask] = -INF;

    for(int u : t){
        int numPerson = __builtin_popcount(u);
        f[1][numPerson][u] = s[1][u];
    }
}
void xuli(){
    int res = -INF;
    for(int i = 1; i < r; i++){
        for(int cnt = 0; cnt <= k; cnt++){
            for(int u : t) if(f[i][cnt][u] > -INF) {
                for(int v : t) if((u & v) == 0) {
                    int numPerson = __builtin_popcount(v);
                    maximize(f[i + 1][cnt + numPerson][v], f[i][cnt][u] + s[i + 1][v]);
                }
            }
        }
    }
    for(int i = 1; i <= r; i++)
        for(int mask : t) maximize(res, f[i][k][mask]);
    cout << (res > -INF ? res : -1);
}
int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    readfile();
    progress();
    xuli();
    return 0;
}
