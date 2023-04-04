#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 5e5 + 1;
const int MOD = 998255353;
int Sub, n;
int cnt = 0;
int par[NM], high[NM], Left[NM], Right[NM];
vector<int> child[NM];

struct SegmentTree_Num_1 {
    vector<int> sum, lazy;
    int n;

    SegmentTree_Num_1(int _n = 0){
        int n = _n;
        sum.assign(4 * n + 7, 0);
        lazy.assign(4 * n + 7, 0);
    }

    void pushDown(int i){
        for(int t = 0; t < 2; t++){
            sum[2 * i + t] += lazy[i];
            lazy[2 * i + t] += lazy[i];
            lazy[i] = 0;
        }
        return;
    }

    void update(int i, int l, int r, int u, int v, int d){
        if(l > v || r < u || l > r) return;
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
        if(l > v || r < u || l > r) return 0;
        if(l >= u && r <= v) return sum[i];
        int m = (l + r) >> 1;
        int sumL = getSum(2 * i, l, m, u, v);
        int sumR = getSum(2 * i + 1, m + 1, r, u, v);
        return (sumL + sumR) % MOD;
    }

    void update(int u, int v, int d){
        update(1, 1, n, u, v, d);
    }

    int getSum(int u, int v){
        return getSum(1, 1, n, u, v);
    }
};

void dfs(int u){
    Left[u] = ++cnt;
    for(int v : child[u]) dfs(u);
    Right[u] = cnt;
}
void sub2(){
    SegmentTree_Num_1 tree(n);
    while(q--){
        string type;
        int u, k, l;
        cin >> type;
        if(type == "add"){
            cin >> u >> k >> l;
            tree.update(Left[u], Right[u], k);
        }
        if(type == "get"){
            cin >> u;
            cout << tree.getSum(Left[u], Left[u]) << '\n';
        }
        if(type == "sum"){
            cin >> u;
            cout << tree.getSum(Left[u], Right[u]) << '\n';
        }
    }
}
int32_t main()
{
    FastIO
    freopen("TALLTREE.INP", "r", stdin);
    freopen("TALLTREE.OUT", "w", stdout);
    cin >> Sub >> n;
    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        child[u].push_back(i);
    }

    dfs(1);
    return 0;
}
