#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e3 + 10;
int n, d;
int ans = 0;
int a[NM], t[NM], f[105][205];
vector<int> id[NM];

void readfile(){
    freopen("NOEL.INP", "r", stdin);
    freopen("NOEL.OUT", "w", stdout);
    cin >> n >> d;
    n = 2 * n;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
int dp(int x, int y, int w){
    if(x > w || y > n) return 0;
    int &res = f[x][y];
    if(res != -1) return res;
    if(abs(a[x] - a[y]) <= d) maximize(res, 1 + dp(x + 1, y + 1, w));
    maximize(res, dp(x + 1, y, w));
    maximize(res, dp(x, y + 1, w));
    return res;
}
void sub12(){
    int res = 0;
    for(int i = 1; i <= n; i++){
        memset(f, -1, sizeof(f));
        maximize(res, dp(1, i + 1, i));
    }
    cout << res;
}
void xuli(){
    vector<int> val, s;
    for(int i = 1; i <= n; i++){
        for(int j = n; j > i; j--) if(abs(a[i] - a[j]) <= d) id[i].push_back(j);
    }

    int res = 0;
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= i; j++) for(int k : id[j]) if(k > i) s.push_back(k);

        if(s.empty()) continue;
        val.push_back(0);
        val.push_back(s[0]);
        for(int u = 1; u < s.size(); u++){
            int index = lower_bound(ALL(val), s[u]) - val.begin();
            if(index == val.size()) val.push_back(s[u]);
            minimize(val[index], s[u]);
            maximize(res, index);
        }
        s.clear(); val.clear();
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    if(n <= 200) sub12();
    else xuli();
    return 0;
}
