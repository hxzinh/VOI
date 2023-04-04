#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define ii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n;
ii r[NM], c[NM];
ii a[NM];
///-------------------------------sub1---------------------------------
int T[NM];

struct Data {
    int u, v, cost;
    bool inline operator < (const Data &A) const {
        return cost < A.cost;
    }
};
vector<Data> road;

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
    memset(T, -1, sizeof(T));
}
int root(int x){
    if(T[x] == -1) return x;
    else return T[x] = root(T[x]);
}
void sub1(){
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            int cost = min(abs(a[i].fi - a[j].fi), abs(a[i].se - a[j].se));
            road.push_back({i, j, cost});
        }
    }
    sort(ALL(road));
    int cnt = 0, res = 0;
    for(int i = 0; i < road.size(); i++){
        if(cnt == n - 1) break;
        int u = root(road[i].u), v = root(road[i].v);
        if(u != v){
            res += road[i].cost;
            cnt++;
            T[max(u, v)] = min(u, v);
        }
    }
    cout << res;
}
void full(){
    for(int i = 1; i <= n; i++){
        r[i].fi = a[i].fi;
        r[i].se = i;
        c[i].fi = a[i].se;
        c[i].se = i;
    }
    sort(r + 1, r + n + 1);
    sort(c + 1, c + n + 1);
    for(int i = 2; i < n; i++){
        int t = abs(r[i].fi - r[i - 1].fi);
        int m = abs(c[i].fi - c[i - 1].fi);
        road.push_back({r[i - 1].se, r[i].se, t});
        road.push_back({c[i - 1].se, c[i].se, m});
    }
    sort(ALL(road));
    int cnt = 0, res = 0;
    for(int i = 0; i < road.size(); i++){
        if(cnt == n - 1) break;
        int u = root(road[i].u), v = root(road[i].v);
        if(u != v){
            res += road[i].cost;
            cnt++;
            T[max(u, v)] = min(u, v);
        }
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    if(n <= 1000) sub1();
    else full();
    return 0;
}
