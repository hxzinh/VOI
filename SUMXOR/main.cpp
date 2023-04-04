#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define oo 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e6 + 10;
int sub,n,q;
int p[NM], ans[NM];
vector<ii> g[NM];

struct Data{
    int pos,val,stt;
};
Data a[NM];

struct FenwickTree{
    vector<int> v;
    int n;

    FenwickTree(int _n = 0){
        n = _n;
        v.assign(n + 7, 0);
    }

    void update(int x, int d){
        for(; x <= n; x += x & -x) v[x] ^= d;
    }

    int xorr(int x){
        int res = 0;
        for(; x >= 1; x &= x - 1) res ^= v[x];
        return res;
    }

    int getXor(int u, int v){
        return xorr(u) ^ xorr(v - 1);
    }
};
FenwickTree tree(NM);

void readfile(){
    freopen("SUMXOR.INP","r",stdin);
    freopen("SUMXOR.OUT","w",stdout);
    cin >> sub;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].val;
        a[i].pos = i;
    }
}
bool cval(Data A, Data B){
    return A.val < B.val;
}
bool cpos(Data A,Data B){
    return A.pos < B.pos;
}
void minium(){
    sort(a + 1, a + n + 1, cval);
    int dem = 1;
    for(int i = 1; i <= n; i++){
        a[i].stt = dem;
        while(a[i + 1].val == a[i].val){
            i++; a[i].stt = dem;
        }
        dem++;
    }
    sort(a + 1, a + n + 1, cpos);
    ///for(int  i = 1; i <= n; i++) cout << a[i].stt << " ";
}
void xuli(){
    minium();
    cin >> q;
    for(int i = 1; i <= q; i++){
        int u,v; cin >> u >> v;
        g[v].push_back({u,i});
    }
    memset(p, 0, sizeof(p));
    for(int i = 1; i <= n; i++){
        if(p[a[i].stt]){
            tree.update(p[a[i].stt], a[i].val);
        }
        p[a[i].stt] = i;
        for(ii u : g[i]){
            ans[u.second] = tree.getXor(i, u.first);
        }
    }
    for(int i = 1; i <= q; i++)
        cout << ans[i] << " ";
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
