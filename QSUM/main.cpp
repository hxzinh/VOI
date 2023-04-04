#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e5+10;
int n,q; /// n phan tu va q truy van

///Fenwick Tree
struct FenwickTree
{
    vector<int> v;
    int n;

    FenwickTree(int _n = 0){
        n = _n;
        v.assign(n+1, 0);
    }

    void update(int x, int d){
        for(; x <= n; x += x & -x) v[x] += d;
    }

    int get(int x){
        int res = 0;
        for(; x >= 1; x &= x-1) res += v[x];
        return res;
    }

    int getSum(int from, int to){
        return get(to) - get(from - 1);
    }
};
FenwickTree bit(NM);

void readfile(){
    freopen("QSUM.INP","r",stdin);
    freopen("QSUM.OUT","w",stdout);
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        int u; cin >> u;
        bit.update(i, u);
    }
}
void xuli(){
    for(int i=1; i<=q; i++){
        int sta,u,v;
        cin >> sta >> u >> v;
        if(sta == 1) bit.update(u, v);
        else cout << bit.getSum(u, v) << " ";
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
