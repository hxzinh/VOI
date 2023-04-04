#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e3 + 10;
int n, m, q;
int a[NM][NM];
bool cx[1000005], ok = true;
///---------------sub3----------------------
int f[NM][NM][25];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(a[i][j] > 20) ok = false;
        }
    }
    cin >> q;
}
void sub1(){
    set<int> s;
    while(q--){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        s.clear();
        int res = 0;
        for(int i = x; i <= u; i++)
            for(int j = y; j <= v; j++) s.insert(a[i][j]);
        cout << s.size() << '\n';
    }
}
void sub3(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            for(int num = 1; num <= 20; num++)
                f[i][j][num] = f[i - 1][j][num] + f[i][j - 1][num] - f[i - 1][j - 1][num] + (a[i][j] == num);
    while(q--){
        int x, y, u, v;
        int ans = 0;
        cin >> x >> y >> u >> v;
        for(int i = 1; i <= 20; i++){
            int cntNum = f[u][v][i] - f[u][y - 1][i] - f[x - 1][v][i] + f[x - 1][y - 1][i];
            if(cntNum > 0) ans++;
        }
        cout << ans << '\n';
    }
}
int main()
{
    FastIO
    readfile();
    if(ok) sub3();
    else if(n <= 200 && m <= 200 && q <= 200) sub1();
    return 0;
}
