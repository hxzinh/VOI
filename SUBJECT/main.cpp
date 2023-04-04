#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e3 + 10;
int n, m;
int a[NM], ans[300005];
pii q[300005];

int sub4(int x){
    priority_queue<int, vector<int>, greater<int>> pq;

    int sum = x, cnt = 0;
    for(int i = 1; i <= n; i++){
        pq.push(a[i]);
        sum += a[i];
        if(sum < 0){     ///co bn thg lam sum bi am
            sum -= pq.top();
            pq.pop();
            cnt++;
        }
    }
    return cnt;
}
void solve(int l, int r, int minAns, int maxAns){
    if(l > r) return;
    assert(minAns <= maxAns);
    if(minAns == maxAns){
        for(int i = l; i <= r; i++) ans[q[i].se] = minAns;
        return;
    }
    int m = (l + r) >> 1;
    int tmp = sub4(q[m].fi);
    ans[q[m].se] = tmp;
    solve(l, m - 1, tmp, maxAns);
    solve(m + 1, r, minAns, tmp);
    return;
}
void xuli(){
    sort(q + 1, q + m + 1);
    solve(1, m, 0, n);
    for(int i = 1; i <= m; i++) cout << n - ans[i] << " ";
}
int32_t main()
{
    FastIO
    freopen("SUBJECT.INP", "r", stdin);
    freopen("SUBJECT.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++){
        cin >> q[i].fi;
        q[i].se = i;
    }

    xuli();
    return 0;
}
