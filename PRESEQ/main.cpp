#include <bits/stdc++.h>
#define ll long long
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

const int NM = 5e3 + 10;
int n, k;
int curID = 0;
int idd[NM], sizeTree[2 * NM];
int dp[2 * NM][NM], tam[NM];
string a[NM];
vector<pii> edges[2 * NM];

struct Node {
    int id, num, high, cnt;
    int child[26];
};

int getID(int x){
    if(idd[x] == 0) idd[x] = ++curID;
    return idd[x];
}

struct TrieTree {
    vector<Node> tree;

    void build(){
        Node tmp;
        tmp.num = 0;
        for(int i = 0; i < 26; i++) tmp.child[i] = -1;
        tmp.id = tree.size();
        tree.push_back(tmp);
    }

    void update(const string &s){
        int tmp, id = 0;
        for(int i = 0; i < s.size(); i++){
            tree[id].num++;
            tmp = s[i] - 'a';
            if(tree[id].child[tmp] == -1){
                build();
                tree[id].child[tmp] = tree.size() - 1;
            }
            id = tree[id].child[tmp];
        }
        tree[id].num++;
    }

    int getPreCnt(const string &s){
        int tmp, id = 0;
        for(int i = 0; i < s.size(); i++){
            tmp = s[i] - 'a';
            if(tree[id].child[tmp] == -1) return 0;
            id = tree[id].child[tmp];
        }
        return tree[id].num;
    }

    void destruct(){
        tree.clear();
    }

    void dfs(int id, int par, int high){
        tree[id].high = high;
        int numChild = 0;
        for(int i = 0; i < 26; i++) if(tree[id].child[i] > -1) numChild++;
        if(tree[id].num > 0 || numChild > 1){
            if(par != id){
                int u = getID(par), v = high - tree[par].high, k = getID(id);
                edges[u].push_back({k, v});
            }
            par = id;
        }
        if(tree[id].num > 0){
            int u = getID(id);
            sizeTree[u] = tree[id].num;
        }
        for(int i = 0; i < 26; i++){
            if(tree[id].child[i] > -1){
                dfs(tree[id].child[i], par, high + 1);
            }
        }
    }
};
TrieTree tree;

void dfs(int id){
    for(pii t : edges[id]){
        int u = t.fi, cost = t.se;
        dfs(u);
        for(int i = 0; i <= sizeTree[id]; i++){
            for(int j = 0; j <= sizeTree[u]; j++){
                maximize(tam[i + j], dp[id][i] + dp[u][j] + (1LL * j * (j - 1) / 2 * cost));
            }
        }
        sizeTree[id] += sizeTree[u];
        for(int i = 0; i <= sizeTree[id]; i++){
            dp[id][i] = tam[i];
            tam[i] = 0;
        }
    }

}
void xuli(){
    tree.build();
    for(int i = 1; i <= n; i++) tree.update(a[i]);

    tree.dfs(0, 0, 0);
    dfs(1);
    cout << dp[1][k];
}
int main()
{
    FastIO
    freopen("PRESEQ.INP", "r", stdin);
    freopen("PRESEQ.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    xuli();
    return 0;
}
