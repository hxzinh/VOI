#include <bits/stdc++.h>
#define int long long
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

const int NM = 1e6 + 10;
int n, m, k;
int b[NM], g[NM];
int res = INF;
///----------------------------sub1----------------------------------
bool cb[20], cg[20];

void readfile(){
    freopen("COUPLE.INP", "r", stdin);
    freopen("COUPLE.OUT", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= m; i++) cin >> g[i];

    sort(b + 1, b + n + 1);
    sort(g + 1, g + m + 1);
}
void backtrack(vector<int> ans, int cnt){
    if(cnt == k){
        int tmp = -INF;
        for(int u : ans) maximize(tmp, u);
        minimize(res, tmp);
        return;
    }
    for(int i = 1; i <= n; i++) if(cb[i]) {
        cb[i] = false;
        for(int j = 1; j <= m; j++) if(cg[j]) {
            cg[j] = false;
            ans.push_back(abs(b[i] - g[j]));
            backtrack(ans, cnt + 1);
            ans.erase(ans.end() - 1);
            cg[j] = true;
        }
        cb[i] = true;
    }
}
void sub1(){
    memset(cb, true, sizeof(cb));
    memset(cg, true, sizeof(cg));
    vector<int> ans;
    backtrack(ans, 0);
    cout << res;
}
bool check(int x){
    int u = 1, v = 1, cnt = 0;
    while(cnt < k && u <= n && v <= m){
        if(abs(b[u] - g[v]) <= x){u++; v++; cnt++;}
        else if(b[u] > g[v]) v++;
             else u++;
    }

    if(cnt == k) return true;
    else return false;
}
void full(){
    int l = 1, r = max(abs(b[1] - g[m]), abs(b[n] - g[1]));
    while(l <= r){
        int m = (l + r) >> 1;
        if(check(m)){
            res = m;
            r = m - 1;
        } else l = m + 1;
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    full();
    return 0;
}
