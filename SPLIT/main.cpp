#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define ALL(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define fi first
#define se second
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 7e3 + 1;
const int MOD = 998244353;
int n;
int cnt = 0;
int f[NM][NM], lcp[NM][NM];
string s;

int add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void sub2(){
    for(int i = 1; i <= n; i++) f[i][i] = 1;

    for(int i = 1; i <= n; i++){
        if(s[i + 1] == '0') continue;
        for(int j = 1; j <= i; j++){
            for(int k = i + j; k <= n; k++){
                if(k - i > j) add(f[k][k - i], f[i][j]);
                else if(lcp[i - j + 1][i + 1] < j) {
                    int l = lcp[i - j + 1][i + 1];
                    if(s[i + l + 1] > s[i - j + l + 1])
                        add(f[k][k - i], f[i][j]);
                }
            }
        }
    }


    int res = 0;
    for(int i = 1; i <= n; i++){
        add(res, f[n][i]);
        //if(f[n][i]) cout << i << " " << f[n][i] << '\n';
    }
    cout << res;
}
bool check(int x, int y){
    int len = lcp[x][y];
    if(x + len >= y) return 0;
    return s[y + len] > s[x + len];
}
void xuli(){
    memset(f, 0, sizeof f);
    f[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            add(f[i][j], f[i][j - 1]);
            if(s[i - j + 1] == '0') continue;
            if(i >= 2 * j){
                int id = i - j + 1;
                int preID = id - j;
                if(check(preID, id)){
                    add(f[i][j], f[i - j][j]);
                    continue;
                }
            }
            add(f[i][j], f[i - j][min(i - j, j - 1)]);
        }
    }

    cout << f[n][n];
}
int32_t main()
{
    FastIO
    freopen("SPLIT.INP", "r", stdin);
    freopen("SPLIT.OUT", "w", stdout);
    cin >> s;
    n = s.size();
    s = ' ' + s;

    for(int i = n; i > 0; i--){
        for(int j = n; j > i; j--) {
            if(s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
            else lcp[i][j] = 0;
        }
    }


    bool ok = true;
    for(int i = 1; i < n; i++) if(s[i] != s[i + 1]) ok = false;

    xuli();
    return 0;
}





#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define ALL(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define fi first
#define se second
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 7e3 + 1;
const int MOD = 998244353;
int n;
int cnt = 0;
int f[NM][NM], lcp[NM][NM];
string s;

int add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void sub2(){
    for(int i = 1; i <= n; i++) f[i][i] = 1;

    for(int i = 1; i <= n; i++){
        if(s[i + 1] == '0') continue;
        for(int j = 1; j <= i; j++){
            for(int k = i + j; k <= n; k++){
                if(k - i > j) add(f[k][k - i], f[i][j]);
                else if(lcp[i - j + 1][i + 1] < j) {
                    int l = lcp[i - j + 1][i + 1];
                    if(s[i + l + 1] > s[i - j + l + 1])
                        add(f[k][k - i], f[i][j]);
                }
            }
        }
    }


    int res = 0;
    for(int i = 1; i <= n; i++){
        add(res, f[n][i]);
        //if(f[n][i]) cout << i << " " << f[n][i] << '\n';
    }
    cout << res;
}
bool check(int x, int y){
    int len = lcp[x][y];
    if(x + len >= y) return 0;
    return s[y + len] > s[x + len];
}
void xuli(){
    memset(f, 0, sizeof f);
    f[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            add(f[i][j], f[i][j - 1]);
            if(s[i - j + 1] == '0') continue;
            if(i >= 2 * j){
                int id = i - j + 1;
                int preID = id - j;
                if(check(preID, id)){
                    add(f[i][j], f[i - j][j]);
                    continue;
                }
            }
            add(f[i][j], f[i - j][min(i - j, j - 1)]);
        }
    }

    cout << f[n][n];
}
int32_t main()
{
    FastIO
    freopen("SPLIT.INP", "r", stdin);
    freopen("SPLIT.OUT", "w", stdout);
    cin >> s;
    n = s.size();
    s = ' ' + s;

    for(int i = n; i > 0; i--){
        for(int j = n; j > i; j--) {
            if(s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
            else lcp[i][j] = 0;
        }
    }


    bool ok = true;
    for(int i = 1; i < n; i++) if(s[i] != s[i + 1]) ok = false;

    xuli();
    return 0;
}





