#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, q;
int par[NM], ans[NM];
bool r[1005][1005], cx[NM];
bool s2 = true;
set<pii> S;

struct Data {
    int type, u, v, id;
};
Data a[NM];

struct DijointsetUnion {
    int n;
    vector<int> T;

    DijointsetUnion(int _n = 0){
        n = _n;
        T.assign(n + 1, -1);
    }

    int root(int x){
        if(T[x] < 0) return T[x];
        else return T[x] = root(T[x]);
    }

    void join(int x, int y){
        int u = root(x), v = root(y);
        if(u == v) return;
        if(T[u] > T[v]) swap(u, v);
        T[u] += T[v];
        T[v] = u;
    }

    bool check(int u, int v){
        return root(u) == root(v);
    }
};


bool bfs(int u, int fin){
    cx[u] = false;
    if(u == fin) return true;
    for(int v = 1; v <= n; v++) if(v != u && cx[v]){
        if(r[u][v]) if(bfs(v, fin)) return true;
    }
    return false;
}
void sub1(){
    for(int i = 1; i <= q; i++){
        int u = a[i].u, v = a[i].v;
        if(a[i].type == 1) r[u][v] = r[v][u] = true;
        if(a[i].type == 2) r[u][v] = r[v][u] = false;
        if(a[i].type == 3){
            memset(cx, true, (n + 1) * sizeof(bool));
            if(bfs(u, v)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
}
void sub2(){
    DijointsetUnion dsu(n);
    for(int i = 1; i <= q; i++){
        int u = a[i].u, v = a[i].v;
        if(a[i].type == 1) dsu.join(u, v);
        if(a[i].type == 3){
            if(dsu.check(u, v)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
}
void sub3(){
    DijointsetUnion dsu(n);

    for(int i = q/2 + 1; i <= q; i++)
        if(a[i].type == 2) S.insert({a[i].u, a[i].v});

    for(int i = 1; i <= q/2; i++){
        int u = a[i].u, v = a[i].v;
        if(S.find({u, v}) == S.end()) dsu.join(u, v);
    }
    for(int i = q; i > q/2; i--){
        int u = a[i].u, v = a[i].v;
        if(a[i].type == 2) dsu.join(u, v);
        else ans[i] = dsu.check(u, v);
    }

    for(int i = q/2 + 1; i <= q; i++) if(a[i].type == 3) {
        if(ans[i]) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
int main()
{
    FastIO
    freopen("DSUR.INP", "r", stdin);
    freopen("DSUR.OUT", "w", stdout);
    cin >> n >> q;
    s2 = true;
    for(int i = 1; i <= q; i++){
        cin >> a[i].type >> a[i].u >> a[i].v;
        a[i].id = i;
        if(a[i].u > a[i].v) swap(a[i].u, a[i].v);
        if(a[i].type == 2) s2 = false;
    }

    sub3();
    return 0;
}
