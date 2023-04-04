#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

string s;
int f[2005][2005];
stack<char> st;

int dp(int x, int y){
    if(x > y) return 0;
    int &res = f[x][y];
    if(x == y) return 1;
    if(res > 0) return res;
    if(s[x] == s[y]) return res = 2 + dp(x + 1, y - 1);
    maximize(res, dp(x + 1, y));
    maximize(res, dp(x, y - 1));
    return res;
}
void trace(int x, int y){
    if(x > y) return;
    if(x == y){
        st.push(s[x]);
        return;
    }
    if(s[x] == s[y]){
        st.push(s[x]);
        trace(x + 1, y - 1);
        st.push(s[y]);
        return;
    }
    if(f[x][y] == f[x + 1][y]) trace(x + 1, y);
    else trace(x, y - 1);
    return;
}
int main()
{
    FastIO
    freopen("NKPALIN.INP", "r", stdin);
    freopen("NKPALIN.OUT", "w", stdout);
    cin >> s;
    s = " " + s;

    memset(f, -1, sizeof f);
    int n = s.size() - 1;
    int res = dp(1, n);
    trace(1, n);
    while(st.size()){
        cout << st.top();
        st.pop();
    }
    return 0;
}
