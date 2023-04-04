#include <bits/stdc++.h>
#define ll long long
#define oo 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e6+10;
int n,a[NM],f[NM];

struct FenwickTree{
    int numb;
    vector<int> v;

    FenwickTree(int _numb = 0){
        numb = _numb;
        v.assign(numb + 7, 0);
    }

    void update(int x, int d){
        for(; x <= numb; x += x & -x) v[x] = max(v[x], d);
    }

    int getMax(int x){
        int res = 0;
        for(; x >= 1; x &= x - 1) res = max(res, v[x]);
        return res;
    }
};
FenwickTree tree(NM);

void readfile(){
    freopen("dpliq3.inp","r",stdin);
    freopen("dpliq3.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void xuli(){
    int res = 0;
    for(int i = 1; i <= n; i++){
        f[i] = tree.getMax(a[i] - 1) + 1;
        tree.update(a[i], f[i]);
    }

    for(int i = 1; i <= n; i++) res = max(res, f[i]);
    cout << res;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
