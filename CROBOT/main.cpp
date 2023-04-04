#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e4 + 10;
int n, m, k;

struct Data {
    int v, w;

    bool inline operator < (const Data &A) const{
        return w > A.w;
    }
};
vector<Data> edges[NM];

struct Delta {
    int u, cost, step, fin;
    bool inline operator < (const Delta &A) const {
        return (step == A.step ? cost > A.cost : step > A.step);
    }
};

void readfile(){
    freopen("CROBOT.INP", "r", stdin);
    freopen("CROBOT.OUT", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        edges[u].push_back({v, w});
    }
}
void xuli(){
    priority_queue<Delta> pq;

    for(int i = 1; i <= n; i++) pq.push({i, 0, 0, i});

    int res = INF;
    while(!pq.empty()){
        int u = pq.top().u, cost = pq.top().cost, t = pq.top().step;
        int fin = pq.top().fin;
        pq.pop();
        if(t == k){
            if(u == fin) minimize(res, cost);
            continue;
        }
        for(Data v : edges[u]){
            pq.push({v.v, cost + v.w, t + 1, fin});
        }
    }
    cout << res;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
