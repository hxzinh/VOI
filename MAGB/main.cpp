#include <bits/stdc++.h>
#define ll long long
#define oo 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e5+10;
int n;
int a[NM];

struct FenwickTree
{
    int n;
    vector <int> v;

    FenwickTree(int _n){
        n = _n;
        v.assign(n + 1, 0);
    }

    ll gett(int x) const {
        int res = 0;
        for(; x >= 1; x &= x -1) res += v[x];
        return res;
    }

    void update(int x,int d){
        for(; x <= n; x += x & -x) v[x] += d;
    }
};

void readfile(){
    freopen("MAGB.INP","r",stdin);
    freopen("MAGB.OUT","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}
void xuli(){
    FenwickTree bit(n);
    ll res = 0;
    for(int i = n; i >= 1; i--){
        res += bit.gett(a[i] - 1);
        bit.update(a[i],1);
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
