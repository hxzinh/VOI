#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 305;
int n;
int res = 0, cnt = 0;
int f[NM][NM], t[NM][NM], ans[NM];
string s;

bool CorChar(int x, int y){
    return (s[x] == '(' && s[y] == ')') || (s[x] == '[' && s[y] == ']') || (s[x] == '{' && s[y] == '}');
}
void trace(int x, int y){
    if(x >= y) return;
    if(f[x][y] == y - x + 1){
        for(int i = x; i <= y; i++) cout << s[i];
        return;
    }
    if(CorChar(x, y) && f[x][y] == f[x + 1][y - 1]){
        cout << s[x];
        trace(x + 1, y - 1);
        cout << s[y];
        return;
    }
    trace(x, t[x][y]);
    trace(t[x][y] + 1, y);
    return;
}
void xuli(){
    memset(f, INF, sizeof f);
    memset(t, -1, sizeof t);
    for(int i = 1; i <= n; i++){
        f[i][i] = 1;
        f[i][i - 1] = 0;
    }

    for(int i = n; i > 0; i--){
        for(int j = i + 1; j <= n; j++){
            if(CorChar(i, j)){
                minimize(f[i][j], f[i + 1][j - 1]);
                continue;
            }
            for(int k = i + 1; k < j; k++){
                if(minimize(f[i][j], f[i][k] + f[k + 1][j]))
                    t[i][j] = k;
            }
        }
    }
    cout << f[1][n];
    cout << res;

    //trace(1, n);
}
int main()
{
    FastIO
    freopen("DELCHAR.INP", "r", stdin);
    freopen("DELCHAR.OUT", "w", stdout);
    cin >> s;
    n = s.size();
    s = ' ' + s;
    xuli();
    return 0;
}
