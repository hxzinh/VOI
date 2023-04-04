#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, q;
int a[NM];

struct FenwickTree {
    vector<int> sum;
    int _n;

    FenwickTree(int _n = 0){
        n = _n;
        sum.assign(n + 7, 0);
    }

    void update(int x, int d){
        for(int i = x; i <= n; i += i & (-i)){
            sum[i] += d;
        }
    }

    int getSum(int x){
        int res = 0;
        for(int i = x; i > 0; i -= i & (-i)){
            res += sum[i];
        }
        return res;
    }
};

void readfile(){
    freopen("QSUM.INP", "r", stdin);
    freopen("QSUM.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void xuli(){
    FenwickTree tree(n);
    for(int i = 1; i <= n; i++) tree.update(i, a[i]);

    while(q--){
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 1) tree.update(u, v);
        else {
            int res = tree.getSum(v) - tree.getSum(u - 1);
            cout << res << '\n';
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
