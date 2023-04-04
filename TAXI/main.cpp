#include <bits/stdc++.h>
#define ll long long
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define oo INT_MAX
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e6 + 1e5;
int n, numNode;
int a[100][100], cost[100][100]; /// duong di ngan nhat tu i -> j
int f[25][NM];
vector<int> T[100][100], ans;
pair<int,int> Tdp[25][NM];

struct Data{
    int u, cost;

    bool inline operator < (const Data &A) const {
        return cost > A.cost;
    }
};

void readfile(){
    freopen("TAXI.INP","r",stdin);
    freopen("TAXI.OUT","w",stdout);
    cin >> n;
    numNode = 2 * n;
    for(int i = 0; i <= numNode; i++){
        for(int j = 0; j <= numNode; j++){
            cin >> cost[i][j];
            T[i][j].push_back(i);
            T[i][j].push_back(j);
        }
    }
    /**
    for(int i = 0; i <= numNode; i++)
        for(int j = 0; j <= numNode; j++){
            if(i == j) cost[i][j] = 0;
            else cost[i][j] = oo;
        }
    **/
    for(int j = 0; j <= MASK(2 * n) - 1; j++)
        for(int i = 0; i <= numNode; i++){
            f[i][j] = oo;
            Tdp[i][j].first = -1;
            Tdp[i][j].second = 0;
        }

    f[0][0] = 0;
}
void floyd(){
    for(int k = 0; k <= numNode; k++)
        for(int i = 0; i <= numNode; i++)
            for(int j = 0; j <= numNode; j++){
                 if(cost[i][j] > cost[i][k] + cost[k][j]){
                    cost[i][j] = cost[i][k] + cost[k][j];
                    T[i][j].clear();
                    for(int v : T[i][k]) T[i][j].push_back(v);
                    for(int p = 1; p < T[k][j].size(); p++) T[i][j].push_back(T[k][j][p]);
                 }
            }
}
void dijtra(int u){
    priority_queue<Data> pq;
    cost[u][u] = 0;
    pq.push({u, 0});
    while(!pq.empty()){
        int top = pq.top().u, k = pq.top().cost;
        pq.pop();
        if(cost[u][top] != k) continue;
        for(int i = 0; i <= numNode; i++){
            if(cost[u][i] > cost[u][top] + a[top][i]){
                cost[u][i] = cost[u][top] + a[top][i];
                T[u][i].clear();
                for(int k : T[u][top]) T[u][i].push_back(k);
                ///for(int k : T[top][i]) T[u][i].push_back(k);
                for(int v = 1; v < T[top][i].size(); v++)
                    T[u][i].push_back(T[top][i][v]);

                pq.push({i, cost[u][i]});
            }
        }
    }
}
bool check(int u, int mask){
    if(BIT(u - n - 1, mask) && u > n) return true;
    if(u <= n) return true;
    return false;
}
void xuli(){
    int res = oo;
    floyd();
    for(int i = 1; i <= n; i++){
        f[i][MASK(i - 1)] = cost[0][i];
        Tdp[i][MASK(i - 1)].first = 0;
        Tdp[i][MASK(i - 1)].second = 0;
    }
    for(int j = 1; j <= MASK(numNode) - 1; j++){
        for(int i = 1; i <= numNode; i++){
            if(f[i][j] != oo){
                for(int v = 1; v <= numNode; v++){
                    if(check(v, j) && MASK(v - 1) && i != v){
                        int newMask = j | MASK(v - 1);
                        if(f[v][newMask] > f[i][j] + cost[i][v]){
                            f[v][newMask] = f[i][j] + cost[i][v];
                            Tdp[v][newMask].first = i;
                            Tdp[v][newMask].second = j;
                        }
                    }
                }
            }
        }
    }
    int last = -1, mask = MASK(numNode) - 1;
    for(int i  = 1; i <= numNode; i++){
        if(res > f[i][MASK(numNode) - 1] + cost[i][0]){
            last = i;
            res = f[i][MASK(numNode) - 1] + cost[i][0];
        }
    }
    for(int i = T[last][0].size() - 1; i > 0; i--){
        int v = T[last][0][i];
        ans.push_back(v);
    }
    ///for(int v : T[last][0]) ans.push_back(v);
    int preU, preMask;
    while(mask != 0){
        preU = Tdp[last][mask].first;
        preMask = Tdp[last][mask].second;
        for(int i = T[preU][last].size() - 1; i > 0; i--) ans.push_back(T[preU][last][i]);
        last = preU;
        mask = preMask;
    }
    ans.push_back(0);
    cout << res << '\n';
    cout << ans.size() << '\n';
    for(int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
