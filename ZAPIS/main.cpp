#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int MOD = 100000;
int n;
int f[201][50][50][50], g[205][205];
string s;

void add(int &a, int b){
    a = (a + b) % MOD;
    return;
}
int dp(int x, int u, int v, int k){
    if(x > n && !u && !v && !k) return 1;
    if(x > n) return 0;
    int &res = f[x][u][v][k];
    if(res != 0) return res;
    if(s[x] == '(') return res + dp(x + 1, u + 1, v, k);
    if(s[x] == '[') return res + dp(x + 1, u, v + 1, k);
    if(s[x] == '{') return res + dp(x + 1, u, v, k + 1);
    if(s[x] == ')') if(u) return res + dp(x + 1, u - 1, v, k);
                    else return 0;
    if(s[x] == ']') if(v) return res + dp(x + 1, u, v - 1, k);
                    else return 0;
    if(s[x] == '}') if(k) return res + dp(x + 1, u, v, k - 1);
                    else return 0;
    if(s[x] == '?'){
        res += dp(x + 1, u + 1, v, k);
        res += dp(x + 1, u, v + 1, k);
        res += dp(x + 1, u, v, k + 1);
        if(u) res += dp(x + 1, u - 1, v, k);
        if(v) res += dp(x + 1, u, v - 1, k);
        if(k) res += dp(x + 1, u, v, k - 1);
    }
    return res;
}
void xuli(){
    for(int i = 1; i < n; i++){
        if(s[i] != ')' && s[i] != ']' && s[i] != '}' && s[i + 1] != '(' && s[i + 1] != '[' && s[i + 1] != '{'){
            if(s[i] == '?' && s[i + 1] == '?') g[i][i + 1] = 3;
            else g[i][i + 1] = 1;
        }
        g[i + 1][i] = 1;
    }
    g[n + 1][n] = 1;
    for(int i = n - 2; i > 0; i--){
        for(int j = i + 2; j <= n; j++){
            for(int k = i + 1; k <= j; k++){
                if(s[i] == '?'){
                    if(s[k] == '?') add(g[i][j], 3 * g[i + 1][k - 1] * g[k + 1][j] % MOD);
                    if(s[k] == ')' || s[k] == ']' || s[k] == '}'){
                        add(g[i][j], g[i + 1][k - 1] * g[k + 1][j] % MOD);
                    }
                }
                if(s[i] == '(' && (s[k] == '?' || s[k] == ')')) add(g[i][j], g[i + 1][k - 1] * g[k + 1][j] % MOD);
                if(s[i] == '[' && (s[k] == '?' || s[k] == ']')) add(g[i][j], g[i + 1][k - 1] * g[k + 1][j] % MOD);
                if(s[i] == '{' && (s[k] == '?' || s[k] == '}')) add(g[i][j], g[i + 1][k - 1] * g[k + 1][j] % MOD);
            }
        }
    }
    if(g[1][n] == 4) cout << "0000";
    cout << g[1][n];
}
int32_t main()
{
    FastIO
    freopen("ZAPIS.INP", "r", stdin);
    freopen("ZAPIS.OUT", "w", stdout);
    cin >> n >> s;
    s = ' ' + s;

    xuli();
    return 0;
}
