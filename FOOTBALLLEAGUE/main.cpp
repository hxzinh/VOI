#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e3 + 10;
int n;
int ans[NM];
string s[NM], t[NM];
map<string, bool> cx, ok;
map<string, vector<int>> edges;

void xuli(){
    for(int i = 1; i <= n; i++) if(!cx[s[i]]) {
        cx[s[i]] = true;
        if(edges[s[i]].size() >= 2){
            for(int u : edges[s[i]]){
                if(ok[t[u]]){
                    cout << "NO";
                    return;
                }
                ans[u] = 2;
                ok[t[u]] = true;
            }
        }
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            if(ans[j] == 0 && ok[s[j]]){
                if(ok[t[j]]){
                    cout << "NO";
                    return;
                } else {
                    ans[j] = 2;
                    ok[t[j]] = true;
                }
            }
        }

    cout << "YES" << '\n';
    for(int i = 1; i <= n; i++){
        if(ans[i] == 0) cout << s[i] << '\n';
        else cout << t[i] << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("LEAGUE.INP", "r", stdin);
    freopen("LEAGUE.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        string u, v; cin >> u >> v;
        s[i] = u[0]; s[i] += u[1]; s[i] += u[2];
        t[i] = u[0]; t[i] += u[1]; t[i] += v[0];

        edges[s[i]].push_back(i);
    }

    xuli();
    return 0;
}

/* Author: hxzinh */

/*
-----code ko bug-----code ko bug-----code ko bug--------------

          _.-/`)
         // / / )
      .=// / / / )
     //`/ / / / /
    // /     ` /
   ||         /
    \\       /
     ))    .'
    //    /
         /
*/
