#include <bits/stdc++.h>
#define int long long
#define oo 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e5+10;
int n, f[NM];

struct Data{
    int pos, val, stt;
};
Data a[NM];

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
    freopen("DPLIQ4.INP","r",stdin);
    freopen("DPLIQ4.OUT","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        a[i].val = u;
        a[i].pos = i;
    }
}
bool cval(Data A, Data B){
    return A.val < B.val;
}
bool cstt(Data A, Data B){
    return A.pos < B.pos;
}
void xuli(){
    int dem = 1, res = -oo;
    sort(a + 1, a + n + 1, cval);
    for(int i = 1; i <= n; i++){
        a[i].stt = dem;
        while(a[i].val == a[i+1].val){
            a[i + 1].stt = dem;
            i++;
        }
        dem++;
    }
    sort(a+1,a+n+1,cstt);
    for(int i = 1; i <= n; i++){
        f[i] = tree.getMax(a[i].stt - 1) + 1;
        tree.update(a[i].stt, f[i]);
    }
    for(int i = 1; i <= n; i++) res = max(res, f[i]);
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
