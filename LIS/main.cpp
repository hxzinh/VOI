#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
int n;

void nen(vector<int> &a) {
    set<int> s(a.begin(), a.end());
    vector<int> b(s.begin(), s.end());
    for (int &x: a) {
        x = lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
    }
}

struct FenwickTree{
    int n;
    vector<int> v;

    FenwickTree(int _n = 0){
        n = _n;
        v.assign(n + 7, 0);
    }

    void update(int d,int x){
        for(; x <= n; x += x & -x) v[x] = max(v[x], d);
    }

    int getMax(int x) const {
        int res = 0;
        for(; x >= 1; x -= x & -x) res = max(res, v[x]);
        return res;
    }

};

void readfile(){
    freopen("LIS.INP","r",stdin);
    freopen("LIS.OUT","w",stdout);
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        int u; cin >> u;
        a[i] = u;
    }
    nen(a);
    int res = 0;
    FenwickTree tree(n);
    for(int u : a){
        int m = tree.getMax(u - 1) + 1;
        tree.update(m, u);
    }
    cout << tree.getMax(n);
}
int main()
{
    FastIO
    readfile();
    return 0;
}
