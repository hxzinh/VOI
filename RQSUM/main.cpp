#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, q;
int a[NM];

struct SegmentTree {
    int n;
    vector<int> sum, lazy;

    SegmentTree(int _n = 0){
        n = _n;
        lazy.assign(4 * n + 7, 0);
        sum.assign(4 * n + 7, 0);
    }

    void pushDown(int i){
        if(lazy[i] == 0) return;
        sum[2 * i] += lazy[i];
        sum[2 * i + 1] += lazy[i];
        lazy[i] = 0;
        return;
    }

    void update(int i, int l, int r, int u, int v, int d){
        if(u > r || v < l || l > r) return;
        if(l >= u && r <= v){
            sum[i] += d;
            lazy[i] += d;
            return;
        }
        pushDown(i);
        int m = (l + r) >> 1;
        update(2 * i, l, m, u, v, d);
        update(2 * i + 1, m + 1, r, u, v, d);
        sum[i] = sum[2 * i] + sum[2 * i + 1];
        return;
    }

    int getSum(int i, int l, int r, int u, int v){

    }
};

int main(){
    FastIO
    freopen("RQSUM.INP", "r", stdin);
    freopen("RQSUM.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    return 0;
}
