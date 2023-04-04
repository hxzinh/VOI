#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define ii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2400000;
int k, h, n;
int cnt = 1;
int high[NM], a[500005], par[NM];
int f[100][100][100][100];
vector<int> edges[NM], t[20];
bool cx[500005];

struct Data {
    int cnt, high;
    bool inline operator < (const Data &A) const {
        return cnt > A.cnt;
    }
};
priority_queue<Data> pq;

bool tmp(const int &A, const int &B){
    return A > B;
}
void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> k >> h >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, tmp);
    memset(cx, false, sizeof(cx));
}
pair<int, int> LCA(int u, int v){
    int step = 0;
    if(high[u] < high[v]) swap(u, v);
    while(high[u] > high[v]){
        u = par[u];
        step++;
        cx[u] = false;
    }
    while(u != v){
        u = par[u];
        v = par[v];
        cx[u] = cx[v] = false;
        step += 2;
    }
    return make_pair(u, step);
}
void progress(){
    pq.push({1, 1});
    while(!pq.empty()){
        Data u = pq.top();
        pq.pop();

        if(u.high >= h) continue;
        for(int i = 1; i <= k; i++){
            edges[u.cnt].push_back(++cnt);
            pq.push({cnt, u.high + 1});
            high[cnt] = u.high + 1;
            par[cnt] = u.cnt;
        }
    }
}
void sub1(){
    int ans = 0;
    for(int i = 1; i <= n; i++){
        t[high[a[i]]].push_back(a[i]);
        cx[a[i]] = true;
    }

    ii u;
    for(int i = h; i > 1; i--) if(!t[i].empty()){
        if(t[i].size() == 1){
            t[i - 1].push_back(par[t[i][0]]);
            ans++;
            continue;
        }
        u = make_pair(t[i][0], 0);
        for(int j = 1; j < t[i].size();j++) if(cx[t[i][j]]) {
            u = LCA(u.fi, t[i][j]);
            ans += u.se;
        }
        if(!cx[u.fi]){
            t[high[u.fi]].push_back(u.fi);
            cx[u.fi] = true;
        }
    }
    while(u.fi != 1){u.fi = par[u.fi]; ans++;};
    cout << ans;
}
void sub2(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int u = i; u <= n; u++){
                for(int v = j; v <= m; v++){

                }
            }
        }
    }
}
void sub3(){
    if(n == 2){
        ii u = LCA(a[1], a[2]);
        while(u.fi != 1) u = make_pair(par[u.fi], u.se + 1);
        cout << u.se;
    } else if(n == 3){
        ii u = LCA(a[1], a[2]);
        ii v = LCA(u.fi, a[3]);
        v.se += u.se;
        while(v.fi != 1) v = make_pair(par[v.fi], v.se + 1);
        cout << v.se;
    }
}
int32_t main()
{
    FastIO
    readfile();
    progress();
    if(k <= 5 && h <= 5) sub1();
    else if(k <= 8 && h <= 8 && n <= 3) sub23();
    else sub1();
    return 0;
}
