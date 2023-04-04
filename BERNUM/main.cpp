#include <bits/stdc++.h>
#define int long long
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

const int NM = 2e3 + 10;
int n, k;
int a[NM];
bool ok[NM], visited[NM];

void sub12(){
    memset(ok, false, sizeof false);
    ok[0] = 1;
    for(int i = 0; i <= k; i++) if(ok[i]) {
        for(int j = 1; j <= n; j++) ok[a[j] + i] = true;
    }

    int res = INF;
    for(int i = k; i <= k + 2000; i++) if(ok[i]){
        minimize(res, i);
    }
    cout << res;
}
void xuli(){
    memset(visited, false, sizeof visited);
    vector<int> node;
    for(int i = 1; i <= n; i++) {
        visited[a[i] % a[1]] = true;
        node.push_back(a[i] % a[1]);
    }

    while(node.size()){
        vector<int> tmp;
        for(int v : node){
            for(int i = 1; i <= n; i++) if(!visited[(v + a[i]) % a[1]]) {
                int w = (v + a[i]) % a[1];
                tmp.push_back(w);
                visited[w] = true;
            }
        }
        node.clear();
        for(int v : tmp) node.push_back(v);
    }

    for(int i = k; i <= k + a[1]; i++) if(visited[i % a[1]]){
        cout << i;
        break;
    }
}
int32_t main()
{
    FastIO
    freopen("BERNUM.INP", "r", stdin);
    freopen("BERNUM.OUT", "w", stdout);
    cin >> n >> k;
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
