#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
const int MOD = 1e9 + 7;
int dx[] = {1, 2};
int dy[] = {2, 1};
int n, m;
map<int, bool> cx;
map<int, int> f;
set<int> S;

struct Data {
    int u, v;

    bool inline operator < (const Data &A) const {
        return (u == A.u ? v > A.v : u > A.u);
    }
};

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void dfs(int x, int y){
    S.insert((x - 1) * n + y);
    cx[(x - 1) * n + y] = true;
    for(int i = 0; i < 2; i++){
        int u = x + dx[i], v = y + dy[i];
        if(u <= n && v <= m && !cx[(u - 1) * n + v]) dfs(u, v);
    }
}
void xuli(){
    n++; m++;
    dfs(1, 1);

    f[1] = 1;
    for(int u : S){
        for(int i = 0; i < 2; i++){
            int newS = u + n * dx[i] + dy[i];
            add(f[newS], f[u]);
        }
    }
    cout << f[n * m];
}
int32_t main()
{
    FastIO
    freopen("KNIGHT.INP", "r", stdin);
    freopen("KNIGHT.OUT", "w", stdout);
    cin >> n >> m;

    xuli();
    return 0;
}
