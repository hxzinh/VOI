#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e4 + 10;
int n, k;
int a[NM];
int minn = INF, maxx = -INF;
vector<int> ans, trace;

void readfile(){
    freopen("VITRI.INP", "r", stdin);
    freopen("VITRI.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
bool check(int x){
    int cnt = 0, id = 1;
    ans.clear();
    while(id <= n){
        int v = upper_bound(a + 1, a + n + 1, a[id] + x) - a - 1;
        ans.push_back(v);
        id = upper_bound(a + 1, a + n + 1, a[v] + x) - a;
        cnt++;
    }
    return (cnt <= k);
}
void xuli(){
    int l = INF, r = -INF, res = -1;
    for(int i = 1; i < n; i++){
        minimize(l, abs(a[i + 1] - a[i]));
        maximize(r, abs(a[i + 1] - a[i]));
    }
    a[0] = 0; a[n + 1] = INF;
    while(l <= r){
        int m = (l + r) >> 1;
        if(check(m)){
            r = m - 1;
            trace.clear();
            trace.insert(trace.end(), ALL(ans));
        } else l = m + 1;
    }
    for(int u : trace) cout << u << '\n';
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
