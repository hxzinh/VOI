#include <bits/stdc++.h>
#define int long long
#define oo 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e5+10;
int numb,q;
int a[NM];

///Segment tree
struct SegmenTree{
    int n;
    vector<int> sum;

    SegmenTree(int _n = 0){
        n = _n;
        sum.assign(4*n+7, 0);
    }

    void update(int pos, int x){
        int l = 1, r = numb, i = 1;
        while(true){
            sum[i] += x;
            int u = sum[i];
            if(l == r) return;
            int m = (l + r) >> 1;
            if(pos > m){
                i = 2*i+1;
                l = m + 1;
            }
            else{
                i = 2*i;
                r = m;
            }
        }
    }

    int getSum(int i, int l, int r, int u,int v){
        if(l > v || r < u || l > r || u > v) return 0;
        if(u <= l && r <= v ) return sum[i];
        int m = (l + r) >> 1;
        int sumL = getSum(2*i, l, m, u, v);
        int sumR = getSum(2*i+1, m+1, r, u, v);
        return sumL + sumR;
    }

    int getSum(int u, int v){
        return getSum(1, 1, numb, u, v);
    }
};

void readfile(){
    freopen("bitqsum.inp","r",stdin);
    freopen("bitqsum.out","w",stdout);
    cin >> numb >> q;
    for(int i=1; i<=numb; i++){
        cin >> a[i];
    }
}
SegmenTree tree(numb+1);

void xuli(){
    for(int i=1; i<=numb; i++){
        tree.update(i, a[i]);
    }
    for(int i=1; i<=q; i++){
        int type; cin >> type;
        if(type == 1){
            int x,c; cin >> x >> c;
            tree.update(x, c);
        } else {
            int l,r; cin >> l >> r;
            cout << tree.getSum(l, r) << " ";
        }
    }
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
