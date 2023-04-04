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

const int NM = 2e2 + 10;
const int MAX = 50001;
int n, k;
int a[NM];
unordered_map<int, int> mp[205];
vector<int> p;

void xuli(){
    mp[1][a[1]] = 1;
    mp[2][a[1] - a[2]] = -1;

    for(int i = 2; i <= n; i++){
        for(int u = -MAX; u <= MAX; u++) if(mp[i].count(u)){
            mp[i + 1][u + a[i + 1]] = 1;
            mp[i + 1][u - a[i + 1]] = -1;
        }
    }

    int id = n, Plus = 0;
    while(id){
        if(mp[id][k] == -1 && Plus){
            while(Plus){
                p.push_back(id);
                Plus--;
            }
        }
        if(mp[id][k] == 1){
            k -= a[id];
            Plus++;
        } else k += a[id];
        id--;
    }

    int res = 0;
    for(int u : p){
        cout << u << " ";
        res++;
    }
    while(res < n - 1){
        cout << 1 << " ";
        res++;
    }
}
int32_t main()
{
    FastIO
    freopen("SUBTRACT.INP", "r", stdin);
    freopen("SUBTRACT.OUT", "w", stdout);
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
