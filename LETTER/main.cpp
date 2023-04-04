#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define ii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e5 + 1;
string s;
int n;
int f[NM][26][2];
ii trace[NM][26][2];

void readfile(){
    freopen("LETTERS.INP", "r", stdin);
    freopen("LETTERS.OUT", "w", stdout);
    cin >> s;
    n = s.length();
    s = ' ' + s;
}
void xuli(){
    for(int i = 0; i <= n; i++)
        for(int last = 0; last < 26; last++)
            for(int ok = 0; ok < 2; ok++) f[i][last][ok] = INF;

    ///memset(f, 0x3f, sizeof(f));
    for(int i = 0; i < 26; i++) f[1][i][0] = abs(s[1] - 'A' - i);

    for(int i = 1; i < n; i++){
        for(int last = 0; last < 26; last++) for(int ok = 0; ok < 2; ok++) if(f[i][last][ok] < INF) {
            if(!ok){
                if(minimize(f[i + 1][last][true], f[i][last][ok] + abs(s[i + 1] - 'A' - last)))
                    trace[i + 1][last][true] = {last, ok};
            } else {
                for(int j = 0; j < 26; j++){
                    if(minimize(f[i + 1][j][j == last], f[i][last][ok] + abs(s[i + 1] - 'A' - j)))
                        trace[i + 1][j][j == last] = {last, ok};
                }
            }
        }
    }

    int res = INF, last = -1;
    for(int i = 0; i < 26; i++) if(minimize(res, f[n][i][true])) last = i;
    cout << res << '\n';

    string t;
    for(int i = 0; i < n; i++) t += '.';
    bool ok = true;

    while(true){
        t[n - 1] = last + 'A';
        ii tmp = trace[n][last][ok];
        if(n-- == 1) break;
        last = tmp.fi; ok = tmp.se;
    }
    cout << t;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
