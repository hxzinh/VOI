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

const int NM = 1e6 + 10;
int n;
int a[NM];

int solve(int x, int cnt){
    if(x == 1) return (cnt == 1);
    if(x % 2 != 0) return cnt;
    else return (x >> 2, cnt * 2);
}
void xuli(){
    int pre = INF;
    while(n > 0){
        if(n % 2 != 0){
            cout << 1 << endl;
            n--;
            pre = 1;
        } else {
            int u = 1, k = 0;
            while(MASK(++k) <= min(n, pre)) if(n % MASK(k) == 0) u = MASK(k);
            if(u == n && pre == INF) {
                u = 0;
                cout << 0 << endl;
            } else cout << u << endl;
            n -= u;
            pre = (u ? u : pre);
        }
        if(!n) break;
        int u; cin >> u;
        n -= u;
        pre = u;
    }
}
int32_t main()
{
    FastIO
    cin >> n;

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
