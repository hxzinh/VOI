#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, t;
int last;
int f[NM], trace[NM];

struct Data {
    int start, fin, cost, id;
};
Data a[NM];

struct Employ {
    int u, cost;

    bool inline operator < (const Employ &A) const {
        return cost > A.cost;
    }
};

bool cmp(const Data &A, const Data &B){
    return A.start < B.start;
}
void xuli(){
    memset(trace, -1, sizeof(trace));
    for(int i = 1; i <= n; i++) f[i] = INF;
    sort(a + 1, a + n + 1, cmp);
    a[0] = {0, 0, 0};
    a[n + 1] = {n + 1, n + 1, 0};
    f[0] = 0;

    priority_queue<Employ> pq;
    pq.push({0, 0});

    while(true){
        int u = pq.top().u, cost = pq.top().cost;
        pq.pop();
        if(cost != f[u]) return;
        if(a[u].fin >= t){
            cout << cost << '\n';
            last = u;
            break;
        };
        for(int v = u + 1; v <= n + 1; v++){
            if(a[u].fin < a[v].start) break;
            if(f[v] == INF){
                f[v] = f[u] + a[v].cost;
                trace[v] = u;
                pq.push({v, f[v]});
            }
        }
    }

    stack<int> st;
    while(last != 0){
        st.push(last);
        last = trace[last];
    }

    while(!st.empty()){
        int u = st.top();
        cout << a[u].id << " ";
        st.pop();
    }
}
void readfile(){
    freopen("EMPLOY.INP", "r", stdin);
    freopen("EMPLOY.OUT", "w", stdout);
    cin >> n >> t;
    for(int i = 1; i <= n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {u, v, w, i};
    }
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
