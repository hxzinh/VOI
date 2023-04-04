#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define ii pair<int, int>
#define ALL(v) (v).begin(), (v).end()
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 55;
int n, m;
int res = INF, tmp = 0;
int sum[NM], f[NM];
bool cx[NM], check[NM];
vector<int> a[NM];

void readfile(){
    freopen("GROUP.INP", "r", stdin);
    freopen("GROUP.OUT", "w", stdout);
    cin >> n >> m;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        for(int j = 1; j <= u; j++){
            int u; cin >> u;
            a[i].push_back(u);
            sum[i] += u;
        }
    }
    for(int i = 1; i <= n; i++) sort(ALL(a[i]));
}
void backtrack(vector<ii> ans, int cnt){
    if(cnt > n) return;
    if(cnt == n){
        int dem = 0;
        for(auto u : ans) if(a[u.fi][u.se] < sum[++dem]) return;
        minimize(res, tmp);
        return;
    }
    for(int i = 1; i <= n; i++) if(check[i]){
        check[i] = false;
        for(int j = 0; j < a[i].size(); j++){
            int tam = a[i][j];
            sum[i] -= tam;
            tmp += a[i][j];
            ans.push_back(make_pair(i, j));
            backtrack(ans, cnt + 1);
            ans.erase(ans.end() - 1);
            tmp -= a[i][j];
            sum[i] += tam;
        }
        check[i] = true;
    }
}
void xuli(){
    vector<ii> ans;
    memset(cx, true, sizeof(cx));
    memset(check, true, sizeof(check));
    backtrack(ans, 0);
    cout << (res < INF ? res : -1);
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
