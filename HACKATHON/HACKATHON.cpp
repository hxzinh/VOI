#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 3e5 + 10;
int n, m, p, k;
int ans = INF;
int f[NM], g[NM];

struct Data {
    int x, y, z;
};
Data a[NM];

struct Hackathon {
    int cost, id;

    bool inline operator < (const Hackathon &A) const {
        return cost < A.cost;
    }
};

void backtrack(int x, int sum, int cntx, int cnty, int cntz){
    if(x > k){
        if(cntx + cnty + cntz == k) minimize(ans, sum);
        return;
    }
    if(cntx < n) backtrack(x + 1, sum + a[x].x, cntx + 1, cnty, cntz);
    if(cnty < m) backtrack(x + 1, sum + a[x].y, cntx, cnty + 1, cntz);
    if(cntz < p) backtrack(x + 1, sum + a[x].z, cntx, cnty, cntz + 1);
    return;
}
void sub1(){
    backtrack(1, 0, 0, 0, 0);
    cout << ans;
}

bool cmp(const Data &A, const Data &B){
    return (A.x - A.y) < (B.x - B.y);
}
void xuli(){
    int sumC = 0;
    for(int i = 1; i <= k; i++){
        a[i].x -= a[i].z;
        a[i].y -= a[i].z;
        sumC += a[i].z;
        a[i].z = 0;
    }
    sort(a + 1, a + k + 1, cmp);

    memset(f, INF, sizeof f);
    memset(g, INF, sizeof g);

    priority_queue<Hackathon> pq;
    int S = 0;
    for(int i = 1; i <= k; i++){
        pq.push({a[i].x, i});
        S += a[i].x;
        if(pq.size() > m){
            S -= pq.top().cost;
            pq.pop();
        }
        if(pq.size() == m) f[i] = S;
    }

    while(pq.size()) pq.pop();
    S = 0;
    for(int i = k; i > 0; i--){
        pq.push({a[i].y, i});
        S += a[i].y;
        if(pq.size() > n){
            S -= pq.top().cost;
            pq.pop();
        }
        if(pq.size() == n) g[i] = S;
    }

    int res = INF;
    for(int i = 1; i <= k; i++) minimize(res, f[i] + g[i + 1]);
    res += sumC;
    cout << res;
}
int main()
{
    FastIO
    freopen("HACKATHON.INP", "r", stdin);
    freopen("HACKATHON.OUT", "w", stdout);
    cin >> n >> m >> p;
    k = n + m + p;
    for(int i = 1; i <= k; i++){
        cin >> a[i].x >> a[i].y >> a[i].z;
    }

    xuli();
    return 0;
}
