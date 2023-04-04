#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e4 + 10;
int numPerson, numSpec, k, m;
int cntPerson = 0;
int cnt[NM];
string a[NM];
map<string, int> id;
string s[NM];
bool isSpec[NM], ok[NM], adj[10001][10001];;
vector<int> edges[NM];
vector<string> ans;

void xuli(){
    for(int i = 1; i <= numPerson; i++){
        for(int j : edges[i]) adj[i][j] = adj[j][i] = 1;
    }

    queue<int> q;
    for(int i = 1; i <= numSpec; i++){
        int u = id[a[i]];
        isSpec[u] = ok[u] = true;
        ans.push_back(a[i]);
        for(int j = 1; j <= numPerson; j++) if(adj[u][j]){
            cnt[j]++;
            if(cnt[j] >= k && !ok[j]){
                ok[j] = true;
                q.push(j);
            }
        }
    }

    while(q.size()){
        int u = q.front();
        q.pop();
        ans.push_back(s[u]);
        isSpec[u] = true;
        for(int v = 1; v <= numPerson; v++) if(adj[u][v]) {
            cnt[v]++;
            if(cnt[v] >= k && !ok[v]){
                ok[v] = true;
                q.push(v);
            }
        }
    }

    sort(ALL(ans));
    ans.resize(unique(ALL(ans)) - ans.begin());
    cout << ans.size() << '\n';
    for(auto u : ans) cout << u << " ";
}
int main()
{
    FastIO
    freopen("SPECONE.INP", "r", stdin);
    freopen("SPECONE.OUT", "w", stdout);
    cin >> numPerson >> k >> numSpec >> m;
    for(int i = 1; i <= numSpec; i++){
        cin >> a[i];
        if(!id[a[i]]){
            id[a[i]] = ++cntPerson;
            s[cntPerson] = a[i];
            isSpec[cntPerson] = true;
        }
    }
    for(int i = 1; i <= m; i++){
        string u, v;
        cin >> u >> v;
        if(!id[u]){
            id[u] = ++cntPerson;
            s[cntPerson] = u;
        }
        if(!id[v]){
            id[v] = ++cntPerson;
            s[cntPerson] = v;
        }
        edges[id[u]].push_back(id[v]);
        edges[id[v]].push_back(id[u]);
    }

    xuli();
    return 0;
}
