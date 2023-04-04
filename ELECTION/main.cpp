#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 6e5 + 10;
const int VOTE_MAX = 6e5;
const int NUM_MAX = 50;
int sub, n;
int index[NM], curVote = 0;
pair<int, int> vote[NM];
vector<int> tmp[NM];

struct SegmentTree{
    int n;
    vector<ll> sumCost;
    vector<int> cnt;

    SegmentTree(int _n) {
        n = _n;
        sumCost.assign(4 * n + 7, 0);
        cnt.assign(4 * n + 7, 0);
    }

    void update(int pos, int val){
        int i = 1, l = 1, r = n;
        while(true){
            sumCost[i] += val;
            cnt[i]++;
            if(l == r) return;
            int m = (l + r) >> 1;
            if(pos > m){
                i = 2 * i + 1;
                l = m + 1;
            } else {
                i = 2 * i;
                r = m;
            }
        }
    }

    ll getSum(ll k) const {
        int tam = cnt[1];
        if(k > cnt[1]) return INF;
        if(k <= 0) return 0;
        ll res = 0;
        int i = 1, l = 1, r = n;
        while(true){
            if(k == 0) return res;
            if(l == r) return (res + sumCost[i] / cnt[i] * k);
            int m = (l + r) >> 1;
            if(cnt[2 * i] <= k){
                res += sumCost[2 * i];
                k -= cnt[2 * i];
                i = 2 * i + 1;
                l = m + 1;
            } else {i = 2 * i; r = m;}
        }
    }

};

bool minimize(ll &a, ll b){
    if(a > b){
        a = b;
        return true;
    } else return false;
}
bool cmp(pair<int, int> &x, pair<int, int> &y){
    return x.fi == y.fi ? x.se > y.se : x.fi < y.fi;
}
void readfile(){
    freopen("ELECTION.INP", "r", stdin);
    freopen("ELECTION.OUT", "w", stdout);
    cin >> sub;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int u, v; cin >> u >> v;
        if(u == 0) curVote++;
        vote[i] = make_pair(u, v);
    }
    sort(vote + 1, vote + n + 1, cmp);
}
void xuli(){
    vector<int> val;
    ll ans = 0, tam = 0;
    for(int i = curVote + 1; i <= n; i++){
        if(vote[i].fi != vote[i - 1].fi) tam = 1;
        else tam++;
        tmp[tam].push_back(vote[i].se);
        val.push_back(vote[i].se);
        ans += vote[i].se;
    }
    sort(val.begin(), val.end());
    val.resize(unique(val.begin(), val.end()) - val.begin());

    SegmentTree tree(val.size());

    ll res = INF;
    int cnt = n - curVote;
    for(int i = 1; i <= n; i++){
        ll u = i - curVote - cnt;
        minimize(res, 1LL * (ans + tree.getSum(max(u, 0LL))));
        for(auto v : tmp[i]){
            int pos = lower_bound(val.begin(), val.end(), v) - val.begin() + 1;
            tree.update(pos, v);
            ans -= v;
            cnt--;
        }
    }
    cout << res;
}
int32_t main()
{
    readfile();
    xuli();
    return 0;
}
