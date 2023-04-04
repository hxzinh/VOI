#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int n, m;
int a[NM], b[NM];
int f[1005][1005];
vector<int> p[2 * NM + 100];

void readfile(){
    freopen("LCS.INP", "r", stdin);
    freopen("LCS.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
}
void xuli(){
    memset(f, -1, sizeof(f));
    for(int i = 0; i <= n; i++) f[i][0] = 0;

    for(int i = 1; i <= m; i++) p[b[i] + NM].push_back(i);

    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= n; k++) if(f[i - 1][k - 1] != -1) {
            int t = f[i - 1][k - 1];
            int pos = 0;
            pos = lower_bound(p[a[i] + NM].begin(), p[a[i] + NM].end(), t) - p[a[i] + NM].begin();
            if(f[i - 1][k] != -1) f[i][k] = min(f[i - 1][k], p[a[i] + NM][pos]);
            else f[i][k] = p[a[i] + NM][pos];
        }
    }

    int res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) if(f[i][j] != -1) maximize(res, j);
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
