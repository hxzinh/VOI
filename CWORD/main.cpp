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

const int NM = 55 + 10;
int n, result = INF;
string a[NM];
vector<int> edges[NM];
int ans[NM];

void backtrack(int x, int id) {
    if(id >= result) return;

    if(x > n) {
        minimize(result, id);
        return;
    }

    int cntDiff = 0;
    for(int i = 1; i <= id; i++) {
        bool cx = true;
        for(int u : edges[x]) {
            if(ans[u] == i) {
                cx = false;
                break;
            }
        }
        if(!cx) {
            cntDiff++;
            continue;
        }
        ans[x] = i;
        backtrack(x + 1, id);
        ans[x] = 0;
    }

    ans[x] = id + 1;
    backtrack(x + 1, id + 1);
    ans[x] = 0;
}
void xuli() {

    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(a[i].size() != a[j].size()) {
                //edges[i].push_back(j);
                edges[j].push_back(i);
            } else {
                bool cx = true;
                for(int u = 0; u < a[i].size(); u++) {
                    if(a[i][u] == '*' || a[j][u] == '*') continue;
                    if(a[i][u] != a[j][u]) {
                        cx = false;
                        break;
                    }
                }
                if(!cx) {
                    //edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
    }

    backtrack(1, 1);

    cout << result;
}
int32_t main()
{
    FastIO
    freopen("CWORD.INP", "r", stdin);
    freopen("CWORD.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

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
