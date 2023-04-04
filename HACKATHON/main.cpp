#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f
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

    priority_queue<int> pq;
    int S = 0;
    for(int i = 1; i <= k; i++){
        pq.push(a[i].x);
        S += a[i].x;
        if(pq.size() > n){
            S -= pq.top();
            pq.pop();
        }
        if(pq.size() == n) f[i] = S;
    }

    priority_queue<int> q;
    S = 0;
    for(int i = k; i > 0; i--){
        q.push(a[i].y);
        S += a[i].y;
        if(q.size() > m){
            S -= q.top();
            q.pop();
        }
        if(q.size() == m) g[i] = S;
    }

    int res = INF;
    for(int i = 1; i <= k; i++) minimize(res, f[i] + g[i + 1]);
    res += sumC;
    cout << res;
}
int32_t main()
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
