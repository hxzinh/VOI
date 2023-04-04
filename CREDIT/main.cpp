#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 3e5 + 10;
int n, k, sub;
int s[2005][4005], t[NM];
pair<int, int> cp[NM]; ///copy of a, use to trace
vector<int> values;

struct Data {
    int one, two, index;

    Data(int _one = 0, int _two = 0, int _index = 0){
        one = _one;
        two = _two;
        index = _index;
    }

    bool operator < (const Data &a) const {
        return two < a.two;
    }
};
Data a[NM];

struct Cmp {
    int points, index;

    bool operator < (const Cmp &a) const {
        return points > a.points;
    }
};

struct SegmentTree {
    vector<ll> sum;
    vector<int> cnt;
    int n;

    SegmentTree(int _n = 0){
        n = _n;
        sum.assign(4 * n + 7, 0);
        cnt.assign(4 * n + 7, 0);
    }

    ///delta = 1 : add, delta = -1 : delete
    void update(int i, int l, int r, int pos, int delta, int value){
        sum[i] += delta * value;
        cnt[i] += delta;
        if(l == r) return;
        int m = (l + r) >> 1;
        if(pos > m) update(2 * i + 1, m + 1, r, pos, delta, value);
        else update(2 * i, l, m, pos, delta, value);
    }

    ll minSum(int k) const {
        if(k > cnt[1]) return INF;
        if(k < 0) return 0;
        ll res = 0;
        int l = 1, r = n, i = 1;
        while(true){
            if(k == 0) return res;
            if(l == r) return res + sum[i] / cnt[i] * k;
            int m = (l + r) >> 1;
            if(cnt[2 * i] <= k){
                res += sum[2 * i];
                k -= cnt[2 * i];
                i = 2 * i + 1; l = m + 1;
            } else {
                i = 2 * i; r = m;
            }
        }
    }

    void update(int pos, int delta, int value){
        update(1, 1, n, pos, delta, value);
    }
};

bool minimize(ll &a, ll b){
    if(a > b){a = b; return true;}
    else return false;
}
void readfile(){
    freopen("CREDIT.INP", "r", stdin);
    freopen("CREDIT.OUT", "w", stdout);
    cin >> sub;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int u, v; cin >> u >> v;
        a[i] = Data(u, v, i);
    }
    sort(a + 1, a + n + 1);
}
/*
void sub2nd(){
    int res = INF;

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= k + 1; j++) s[i][j] = INF;
    s[0][0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++) if(s[i][j] < INF) {
            if(minimize(s[i + 1][j], s[i][j])) t[i + 1] = 0;
            if(minimize(s[i + 1][j + 1], s[i][j] + a[i + 1].one)) t[i + 1] = 1;
            if(minimize(s[i + 1][j + 2], s[i][j] + a[i + 1].two)) t[i + 1] = 2;
        }
    }
    for(int i = 1; i <= n; i++){
        minimize(res, s[i][k]);
        minimize(res, s[i][k + 1]);
    }
    int numT = k, numNode = n;
    cout << res << '\n';
    for(int i = 1; i <= n; i++) cout << t[i];
}*/
void xuli(){
    for(int i = 1; i <= n; i++){
        values.push_back(a[i].one);
        values.push_back(a[i].two - a[i].one);
    }
    sort(values.begin(), values.end());
    values.resize(unique(values.begin(), values.end()) - values.begin());

    SegmentTree tree(values.size());

    for(int i = 1; i <= n; i++){
        int pos = lower_bound(values.begin(), values.end(), a[i].one) - values.begin() + 1;
        tree.update(pos, 1, a[i].one);
    }
    ll best = tree.minSum(k);
    int bestI = 0;
    ll sumOne = 0;
    for(int i = 1; i <= n; i++){
        if(i > 1) {
            int val = a[i - 1].two - a[i - 1].one;
            int pos = lower_bound(values.begin(), values.end(), val) - values.begin() + 1;
            tree.update(pos, 1, val);
        }
        int val = a[i].one;
        int pos = lower_bound(values.begin(), values.end(), val) - values.begin() + 1;
        tree.update(pos, -1LL, val);
        sumOne += a[i].one;
        if(minimize(best, sumOne + a[i].two - a[i].one + tree.minSum(k - (i + 1)))) bestI = i;
        ///cout << best << " " << bestI << '\n';
    }

    priority_queue<Cmp> pq;
    for(int i = 1; i <= bestI; i++){
        t[a[i].index]++;
        pq.push({a[i].two - a[i].one, a[i].index});
    }
    for(int i = bestI + 1; i <= n; i++){
        pq.push({a[i].one, a[i].index});
    }
    int dem = bestI;
    while(dem < k && !pq.empty()){
        int u = pq.top().index;
        pq.pop();
        t[u]++;
        dem++;
    }

    cout << best << '\n';
    for(int i = 1; i <= n; i++) cout << t[i];
}
int32_t main(){
    FastIO
    readfile();
    xuli();
    return 0;
}
