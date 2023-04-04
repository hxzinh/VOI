#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int T, x, y, u, v;

void readfile(){
    freopen("FRACCMP.INP", "r", stdin);
    freopen("FRACCMP.OUT", "w", stdout);
    cin >> T;
}
bool getAns(int x, int y, int u, int v, bool ok){
    if(x == 0) if(ok) return false;
               else return true;
    if(u == 0) if(ok) return true;
               else return false;

    int a = x / y, b = u / v;
    if(a != b) if(ok) return (a > b ? 1 : 0);
               else return (a > b ? 0 : 1);
    return getAns(y, x % y, v, u % v, (ok == true ? 0 : 1));
}
void xuli(){
    while(T--){
        cin >> x >> y >> u >> v;
        if(x == 0 && u == 0){cout << 0 << '\n'; continue;}
        if(x == 0){cout << -1 << '\n'; continue;}
        if(u == 0){cout << 1 << '\n'; continue;}
        int a = x / y, b = u / v;
        bool cx = x % y == 0, ok = u % v == 0;
        if(a == b && cx && ok){cout << 0 << '\n'; continue;}
        if(a == b) cout << (getAns(x, y, u, v, 1) ? 1 : -1) << '\n';
        else cout << (a > b ? 1 : -1) << '\n';
    }
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
