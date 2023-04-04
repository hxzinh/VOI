#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}
const int NM = 3e3 + 10;
int n, m;
string a, b;
int f[NM][NM];
queue<char> st;


int dp(int x, int y){
    if(x > n || y > m) return 0;
    int &res = f[x][y];
    if(res > -1) return res;
    if(a[x] == b[y]) maximize(res, 1 + dp(x + 1, y + 1));
    maximize(res, dp(x + 1, y));
    maximize(res, dp(x, y + 1));
    return res;
}
void trace(int x, int y){
    if(x > n || y > m) return;
    if(a[x] == b[y]){
        //Lis[++cnt] = a[x];
        st.push(a[x]);
        trace(x + 1, y + 1);
        return;
    }
    if(f[x + 1][y] >= f[x][y + 1]) trace(x + 1, y);
    else trace(x, y + 1);
}
void xuli(){
    memset(f, -1, sizeof(f));

    n = a.size(); m = b.size();
    a = '#' + a; b = '#' + b;
    dp(1, 1);
    trace(1, 1);

    while(!st.empty()){
        cout << st.front();
        st.pop();
    }
}
int32_t main()
{
    FastIO
    freopen("LCS.INP", "r", stdin);
    freopen("LCS.OUT", "w", stdout);
    cin >> a >> b;

    xuli();
    return 0;
}
