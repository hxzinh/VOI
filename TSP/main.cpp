#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1LL)
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 25;
int n, m;
int f[NM][MASK(21)];
int a[NM][NM], trace[NM][MASK(21)];
stack<int> st;

struct Data {
    int u, cost, mask;

    bool inline operator < (const Data &A) const {
        return cost > A.cost;
    }
};

void readfile(){
    freopen("TSP.INP", "r", stdin);
    freopen("TSP.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = w;
        //a[v][u] = w;
    }

    for(int i = 1; i <= n; i++)
        for(int mask = 0; mask <= MASK(n); mask++) f[i][mask] = INF;
}
void xuli(){
    memset(trace, -1, sizeof trace);

    f[1][1] = 0;
    for(int i = 1; i <= n; i++){
        for(int mask = 0; mask < MASK(n); mask++) if(f[i][mask] < INF){
            for(int j = 1; j <= n; j++) if(!BIT(j - 1, mask)){
                int newMask = mask | MASK(j - 1);
                if(minimize(f[j][newMask], f[i][mask] + a[i][j])) trace[j][newMask] = i;
            }
        }
    }

    int res = INF, id = -1;
    for(int i = 1; i <= n; i++){
        if(minimize(res, f[i][MASK(n) - 1] + a[i][1])) id = i;
    }
    cout << res << '\n';

    //st.push(1);
    int curMask = MASK(n) - 1;
    while(id != -1){
        st.push(id);
        int newMask = curMask - MASK(id - 1);
        id = trace[id][curMask];
        curMask = newMask;
    }

    while(st.size()){
        cout << st.top() << " ";
        st.pop();
    }
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
