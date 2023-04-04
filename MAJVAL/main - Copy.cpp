#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 5e5 + 10;
int n, sz;
int numMax, numMin;
int a[NM];
int d[5005][5005], f[NM], c[NM];
vector<int> pos[NM];

long long C2(int x) {
    return x * (x - 1) / 2;
}

long long arithSum(long long k, long long d, int len) {
    return k * len + C2(len) * d;
}

struct SegmentTree {
    int n;
    vector<int> sum, lazy, down;
    vector<bool> cx;
    vector<int> save;

    SegmentTree(int _n = 0){
        n = _n;
        sum.assign(4 * n + 7, 0);
        lazy.assign(4 * n + 7, 0);
        down.assign(4 * n + 7, 0);
        cx.assign(4 * n + 7, false);
    }

    void pushDown(int i, int l, int r){
        int m = (l + r) >> 1;
        lazy[2 * i] += lazy[i]; lazy[2 * i + 1] += lazy[i] + (m - l + 1) * down[i];
        down[2 * i] += down[i]; down[2 * i + 1] += down[i];
        sum[2 * i] += arithSum(lazy[i], down[i], m - l + 1);
        sum[2 * i + 1] += arithSum(lazy[i] + (m - l + 1) * down[i], down[i], r - m);
        lazy[i] = down[i] = 0;
        return;
    }

    void update(int i, int l, int r, int u, int v, int k, int d){
        if(!cx[i]){
            cx[i] = true;
            save.push_back(i);
        }
        if(v < l || u > r) return;
        if(u <= l && r <= v){
            lazy[i] += k;
            down[i] += d;
            sum[i] += arithSum(k, d, r - l + 1);
            return;
        }
        pushDown(i, l, r);
        int m = (l + r) >> 1;
        update(2*i, l, m, u, v, k, d);
        update(2*i + 1, m + 1, r, u, v, k + max(0LL, m - max(u, l) + 1)*d, d);
        sum[i] = sum[2 * i] + sum[2 * i + 1];
    }

    int getCnt(int i, int l, int r, int u, int v){
        if(!cx[i]){
            cx[i] = true;
            save.push_back(i);
        }

        if(u > r || v < l) return 0;
        if(u <= l && r <= v) return sum[i];
        pushDown(i, l, r);
        int m = (l + r) >> 1;
        int cntL = getCnt(2 * i, l, m, u, v);
        int cntR = getCnt(2 * i + 1, m + 1, r, u, v);
        return cntL + cntR;
    }

    void update(int u, int v, int k, int d){
        update(1, 1, n, u, v, k, d);
    }

    int getCnt(int u, int v){
        return getCnt(1, 1, n, u, v);
    }

    void rollback(){
        for(int id : save){
            sum[id] = lazy[id] = down[id] = 0;
            cx[id] = false;
        }
        save.clear();
    }
};

struct FenwickTree{
    vector<int> val;
    int n;

    FenwickTree(int _n = 0){
        n = _n;
        val.assign(n + 7, 0);
    }

    void update(int x, int d){
        for(; x <= n; x += x & (-x)) val[x] += d;
    }

    int getCnt(int x){
        int cnt = 0;
        for(; x > 0; x -= x & (-x)) cnt += val[x];
        return cnt;
    }
};

void readfile(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void progress(){
    vector<int> s;
    for(int i = 1; i <= n; i++) s.push_back(a[i]);
    sort(ALL(s));
    s.resize(unique(ALL(s)) - s.begin());
    sz = s.size();
    for(int i = 1; i <= n; i++) a[i] = lower_bound(ALL(s), a[i]) - s.begin() + 1;

    numMax = *max_element(a + 1, a + n + 1);
    for(int i = 1; i <= numMax; i++) pos[i].push_back(0);
    for(int i = 1; i <= n; i++) pos[a[i]].push_back(i);
    for(int i = 1; i <= numMax; i++) pos[i].push_back(n + 1);
}
void sub1(){
    progress();
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++) d[a[i]][j]++;
    }
    int res = 0;
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = i + 1; j <= n; j++){
            maximize(cnt, d[a[j]][j] - d[a[j]][i - 1]);
            if(cnt <= (j - i + 1) / 2) res++;
        }
    }

    cout << res << '\n';
}
int solve(int x){
    FenwickTree tree(2 * n + 10);

    for(int i = 1; i <= n; i++) c[i] = c[i - 1] + (a[i] == x);
    for(int i = 1; i <= n; i++) f[i] = 2 * c[i] - i + n;
    int ans = 0;
    tree.update(n, 1);
    for(int i = 1; i <= n; i++){
        ans += tree.getCnt(f[i] - 1);
        tree.update(f[i], 1);
    }
    return ans;
}
void sub2(){
    progress();
    int res = 0;
    for(int i = 1; i <= numMax; i++) res += solve(i);
    cout << res;
}
void full(){
    progress();
    SegmentTree tree(2 * n + 5);
    int res = 0;

    for(int i = 1; i <= numMax; i++){
        for(int j = 1; j < pos[i].size(); j++){
            int l = 2 * (j - 1) - (pos[i][j] - 1) + n + 1;
            int r = 2 * (j - 1) - pos[i][j - 1] + n + 1;
            res += tree.getCnt(max(1LL, l - 1), r - 1);
            tree.update(l, r, 1, 1);
            tree.update(r + 1, 2 * n + 1, r - l + 1, 0);
        }
        tree.rollback();
    }

    ///res = C2(n + 1) - res;
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    full();
    return 0;
}
