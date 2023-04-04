#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 3e5 + 10;
int n, m, Sub;
int a[NM], s1[NM], s2[NM];

struct FenwickTree {
    vector<int> cnt1, cnt2;
    int n;

    FenwickTree(int _n = 0){
        n = _n;
        cnt1.assign(2 * n + 7, 0);
        cnt2.assign(2 * n + 7, 0);
    }

    void update(int x, vector<int> &val){
        for(; x < 2 * n; x += x & (-x)) val[x]++;
    }

    int getCnt(int x, vector<int> &val){
        int res = 0;
        for(; x > 0; x &= x - 1) res += val[x];
        return res;
    }
};

void xuli(){
    int res = 0, ans = 0;
    s1[0] = s2[0] = NM;
    FenwickTree tree(NM);
    tree.update(NM, tree.cnt1);
    tree.update(NM, tree.cnt2);
    for(int i = 1; i <= n; i++){
        if(a[i] <= m) s1[i] = 1;
        else s1[i] = -1;

        if(a[i] < m) s2[i] = 1;
        else s2[i] = -1;
        s1[i] += s1[i - 1];
        s2[i] += s2[i - 1];
        res += tree.getCnt(s1[i], tree.cnt1);
        ans += tree.getCnt(s2[i], tree.cnt2);
        tree.update(s1[i], tree.cnt1);
        tree.update(s2[i], tree.cnt2);
    }
    cout << abs(res - ans);
}
int32_t main()
{
    FastIO
    freopen("SREDNJI.INP", "r", stdin);
    freopen("SREDNJI.OUT", "w", stdout);
    cin >> Sub;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    xuli();
    return 0;
}
