#include <bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 5e5 + 10;
int sub, numNode, numEdges;
int nodes[NM], cntNode;
vector<int> blocks[NM];
bool cx[NM];

struct Data {
    int u, v, cost;
    bool used, res;

    Data(int _u = 0, int _v = 0, int _cost = 0){
        u = _u; v = _v; cost = _cost;
        used = false; res = false;
    }

    bool inline operator < (const Data &A) const {
        return cost < A.cost;
    }
};
Data edges[NM];

struct DijoinsetUnion {
    vector<int> par;
    int n;

    DijoinsetUnion(int _n = 0){
        n = _n;
        par.assign(n + 7, -1);
    }

    int root(int x){
        if(par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool join(int u, int v){
        int x = root(u);
        int y = root(v);
        if(x == y) return false;
        if(par[x] > par[y]) swap(x, y);
        par[x] += y;
        par[y] = x;
        return true;
    }

    bool check(int u, int v){
        return root(u) == root(v);
    }
};
DijoinsetUnion dsu;

void readfile(){
    freopen("MST.INP", "r", stdin);
    freopen("MST.OUT", "w", stdout);
    cin >> sub;
    cin >> numNode >> numEdges;
    for(int i = 1; i <= numEdges; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
    }
    vector<int> cost;
    for(int i = 1; i <= numEdges; i++) cost.push_back(edges[i].cost);
    sort(ALL(cost));
    cost.resize(unique(ALL(cost)) - cost.begin());
    for(int i = 1; i <= numEdges; i++){
        int pos = lower_bound(ALL(cost), edges[i].cost) - cost.begin() + 1;
        blocks[pos].push_back(i);
    }
    dsu = DijoinsetUnion(n);
}
void solve(const vector<int> &index){
    for(auto id : index){
        int u = dsu.root(edges[id].u);
        int v = dsu.root(edges[id].v);
        if(!cx[u]){
            nodes[cntNode++] = u;
        }
    }
}
int main()
{
    FastIO
    cout << "Hello world!" << endl;
    return 0;
}
