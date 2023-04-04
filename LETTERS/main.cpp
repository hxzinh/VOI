#include <bits/stdc++.h>
#define ll long long
#define int unsigned int
#define INF 1e9
#define ii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 505;
int n, m;
int k, s[NM][NM];
long long t[135];
char a[NM][NM];

void readfile(){
    freopen("LETTERS.INP", "r", stdin);
    freopen("LETTERS.OUT", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j];

    s[1][0] = s[0][1] = s[0][0] = 0;

    int i, j;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++) s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (a[i][j] == 'a');
}
int sum(int i, int j, int u, int v){
    return s[j][v] - s[j][u - 1] - s[i - 1][v] + s[i - 1][u - 1];
}
void xuli(){
    long long res = 0;
    int i, j;
    for(i = 1; i <= n; i++){
        for(j = i + 1; j <= n; j++){
            memset(t, 0, sizeof(t));
            int u = 1, v;
            for(v = 1; v <= m; v++){
                while(u < v && sum(i, j, u, v) > k){
                    if(a[i][u] == a[j][v]) t[a[i][u]]--;
                    u++;
                }
                if(a[i][v] == a[j][v]){
                    res += (long long)t[a[i][v]];
                    t[a[i][v]]++;
                }
            }
        }
    }

    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
