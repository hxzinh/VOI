#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int oo = 1e12;
const int NM = 1e5+10;
int n;
int a[NM],t[NM];

///Fenwick Tree
struct FenwickTree
{
    int n;
    vector<int> v;

    FenwickTree(int _n = 0){
        n = _n;
        v.assign(n+1, -oo);
    }

    void update(int x,int d){
        for(; x <= n; x += x & -x) v[x]= max(v[x], d);
    }

    int get(int x){
        int res = 0;
        for(; x >= 1; x &= x-1) res += v[x];
        return res;
    }

    int getMax(int x){
        int res = -oo;
        for(; x >= 1; x &= x-1) res = max(res, v[x]);
        return res;
    }
};
FenwickTree bit(NM);

void readfile(){
    freopen("DCTDN2.INP","r",stdin);
    freopen("DCTDN2.OUT","w",stdout);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
}
void xuli(){
    int res = 0;
    for(int i=1; i<=n; i++) t[i] = 1;
    for(int i=1; i<=n; i++){
        t[i] = bit.getMax(a[i] - 1) + 1;
        bit.update(a[i],t[i]);
    }
    for(int i=1; i<=n; i++) res = max(res, t[i]);
    cout << res;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
