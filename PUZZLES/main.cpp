#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 7e5 + 1;
int n;
int result = 0;
int f[700001][26][26], s[26][26], Len[NM];
char a[NM][16];

void backtrack(int x, char first, char last, int sum){
    if(x > n){
        if(first == last) maximize(result, sum);
        return;
    }
    backtrack(x + 1, first, last, sum);
    int len = Len[x];
    if(last == a[x][0]) backtrack(x + 1, first, a[x][len - 1], sum + len);
    if(sum == 0) backtrack(x + 1, a[x][0], a[x][len - 1], len);
    return;
}
void sub1(){
    char u = ' ';
    backtrack(1, u, u, 0);
    cout << result;
}
void sub3(){
    for(int i = 1; i <= n; i++){
        int len = Len[i];
        f[i][a[i][0] - 'a'][a[i][len - 1] - 'a'] = len;
    }

    for(int i = 1; i < n; i++){
        for(int first = 0; first < 26; first++){
            for(int last = 0; last < 26; last++) if(f[i][first][last]){
                int len = Len[i + 1];
                maximize(f[i + 1][first][last], f[i][first][last]);
                int newLast = a[i + 1][len - 1] - 'a';
                if(last == a[i + 1][0] - 'a') maximize(f[i + 1][first][newLast], f[i][first][last] + len);
            }
        }
    }

    int res = 0;
    for(int i = 0; i < 26; i++) maximize(res, f[n][i][i]);
    cout << res;
}
void full(){
    memset(s, 0, sizeof(s));
    for(int i = 1; i <= n; i++){
        int len = Len[i] - 1;
        for(int j = 0; j < 26; j++) if(s[j][a[i][0] - 'a']){
            maximize(s[j][a[i][len] - 'a'], s[j][a[i][0] - 'a'] + Len[i]);
        }
        maximize(s[a[i][0] - 'a'][a[i][len] - 'a'], Len[i]);
    }

    int res = 0;
    for(int i = 0; i < 26; i++) maximize(res, s[i][i]);
    cout << res;
}
int main()
{
    FastIO
    freopen("PUZZLES.INP", "r", stdin);
    freopen("PUZZLES.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string u; cin >> u;
        for(int j = 0; j < u.size(); j++) a[i][j] = u[j];
        Len[i] = u.size();
    }

    if(n <= 20) sub1();
    else if(n <= 100000) sub3();
    else full();
    return 0;
}
