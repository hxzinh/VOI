#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

/**
//PRAGMA
#pragma GCC target("popcnt")
**/

/**
//ordered_set
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pii,
             null_type,
             less<pii>,
             rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;
**/

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

string a, s;

void xuli(){
    bool ok = false;
    queue<string> q;
    q.push(s);

    while(q.size()){
        string u = q.front();
        q.pop();
        if(u == a){
            ok = true;
            cout << "Yes" << '\n';
            break;
        }
        if(u.size() <= a.size()) continue;
        string v;
        if(u[0] == 'B'){
            v = u.substr(1);
            reverse(ALL(v));
            q.push(v);
        }
        if(u.back() == 'A'){
            u.pop_back();
            q.push(u);
        }
    }
    if(!ok) cout << "No" << '\n';
}
int main()
{
    FastIO
    freopen("ABBA.INP", "r", stdin);
    freopen("ABBA.OUT", "w", stdout);
    while(cin >> a >> s){
        xuli();
    }
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
