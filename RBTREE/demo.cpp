		#include <bits/stdc++.h>
#define oo 20000000000000
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int int
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FOD(i,a,b) for(int i = b; i >= a; i--)
#define REP(i,a) for(int i = 0; i < a; i++)
#define MASK(i) (1LL << (i))
#define BIT(i, a) (((a) >> (i)) & 1)
#define NMOD 3
#define fi first
#define se second
const int BASE = 256;
const long long MOD[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277};
using namespace std;
#define MAX 50050
int pw[NMOD][MAX];
void prepare(void){
    for (int j = 0 ; j < NMOD; j++) {
        pw[j][0] = 1;
        for (int i = 1; i < MAX; i++) pw[j][i] = 1LL * pw[j][i - 1] * BASE % MOD[j];
    }
}

/// --- CACH CAI DAT DISJOINSET UNION --- ///

struct Disjointset{
    vector <int> labor;

    Disjointset(int n = 0){
        labor.assign(n+7, -1);
    }

    int find(int x){
        return labor[x] < 0 ? x : labor[x] = find(labor[x]);
    }

    bool join(int a, int b){
        int x = find(a);
        int y = find(b);
        if(x == y) return false;
        if(labor[x] > labor[y]) swap(x, y);
        labor[x] += labor[y];
        labor[y] = x;
        return true;

    }
};
using ii = pair <int, int>;
using ll = long long;
using ld = long double;
const int Nmax = 200020;
pair <int, int> edge[Nmax]; /// dinh fi lien ket vs se
int n, color[Nmax]; /// so dinh, mau cua cac dinh
vector <int> a[Nmax]; /// dinh
int h[Nmax]; ///do cao cua moi dinh so voi goc
int compID[Nmax];
int numComp; /// chiu :))
int bfs(int x){
    memset(h, -1, (n+1) * sizeof(int));
    queue <int> q;
    h[x] = 0;
    q.push(x);
    int last = x;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        last = u;
        for(auto t : a[u]) if(h[t] < 0){
            h[t] = h[u] + 1;
            q.push(t);
        }
    }
    return last;
}
void readfile(){
    FASTIO
    ///freopen("RBTREE.INP", "r", stdin);
    ///freopen("RBTREE.OUT", "w", stdout);
    int subtask, q; cin >> subtask >> q;
    while(q--){
        cin >> n;
        FOR(i,1,n)
        cin >> color[i];
        FOR(i,0,n-2){
            cin >> edge[i].fi >> edge[i].se;
            //cout << edge[i].fi << " " << edge[i].se << '\n';
        }
goc
        numComp = 0;
        memset(compID, 0, (n+1) * sizeof(int));
        FOR(i,1,n) a[i].clear();

        Disjointset dsu(n);
        REP(i, n-1)
            if(color[edge[i].fi] == color[edge[i].se])
                dsu.join(edge[i].fi, edge[i].se);
        FOR(i,1,n) if(dsu.find(i) == i) compID[i] = ++numComp;
        FOR(i,1,n) if(dsu.find(i) != i) compID[i] = compID[dsu.find(i)];
        REP(i, n-1){
            if(color[edge[i].fi] != color[edge[i].se]){
                int u = compID[edge[i].fi];
                int v = compID[edge[i].se];
                a[u].push_back(v);
                a[v].push_back(u);
            }
        }

        int p1 = bfs(1);
        int p2 = bfs(p1);
        cout << (h[p2] + 1)/2 << " ";
    }
}
int32_t main(){
    ///readfile();
    return 0;
}
