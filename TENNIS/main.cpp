#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define ii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n;
ii a[NM];
vector<ii> trace;

void readfile(){
    freopen("TENNIS.INP", "r", stdin);
    freopen("TENNIS.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi;
        a[i].se = i;
    }
}
void xuli(){
    priority_queue<ii> pq;
    for(int i = 1; i <= n; i++) pq.push(a[i]);

    while(!pq.empty()){
        ii u = pq.top();
        pq.pop();
        while(u.fi--){
            ii v = pq.top();
            pq.pop();
            if(v.fi > 1) trace.push_back(make_pair(v.fi - 1, v.se));
            cout << min(v.se, u.se) << " " << max(v.se, u.se) << '\n';
        }
        for(ii v : trace) pq.push(v);
        trace.clear();
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
