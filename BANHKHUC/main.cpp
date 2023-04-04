#include <bits/stdc++.h>
#define ll long long
#define oo INT_MAX
#define MASK(x) (1LL << (x))
#define BIT(i,x) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 5e2+10;
int numHouse,order;
int a[NM][NM];
int b[NM],s[NM][NM]; /// duong di ngan nhat tu i den j
int f[MASK(20)][21]; /// mang quan ly trang thai
vector<int> c[MASK(20) + 7];

struct Data
{
    int u,cost;
    bool inline operator < (const Data &A) const {
        return cost > A.cost;
    }
};

///  read my code if u can :> ///

void readfile(){
    freopen("banhkhuc.inp","r",stdin);
    freopen("banhkhuc.out","w",stdout);
    cin >> numHouse >> order;
    for(int i=1;i<=numHouse;i++){
        for(int j=1;j<=numHouse;j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= numHouse; i++) a[i][i] = 0;
    for(int i=0;i<order;i++){
        cin >> b[i];
    }
}
void prepare(){
    int mask = MASK(order) - 1;
    /**
    for(int k = 1; k <= numHouse; k++)
        for(int i = 1; i <= numHouse; i++)
            for(int j = 1; j <= numHouse; j++) a[i][j] = min(a[i][j], a[i][k] + a[j][k]);
    **/
    for(int i = 1; i <= numHouse; i++)
        for(int j = 1; j <= numHouse; j++)
            for(int k = 1; k <= numHouse; k++) a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
    for(int i = 1; i <= mask; i++)
        for(int j = 0; j < order; j++) f[i][j] = oo;
    for(int i = 0; i < order; i++) f[MASK(i)][i] = a[1][b[i]];
}
void xuli(){
    prepare();
    int mask = MASK(order) - 1;
    for(int i = 1; i <= mask; i++){
        for(int j = 0; j < order; j++)
            if(!(i & MASK(j))) c[i].push_back(j);
    }
    for(int i = 1; i <= mask; ++i){
        for(int j = 0; j < order; ++j){
            if(f[i][j] < oo)
            for(int u : c[i]){
                f[i | MASK(u)][u] = min(f[i | MASK(u)][u], f[i][j] + a[b[j]][b[u]]);
            }
        }
    }
    int res = oo;
    for(int i = 0; i < order; i++) res = min(res, f[mask][i] + a[b[i]][1]);
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
