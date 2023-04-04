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
int a[NM];

int32_t main()
{
    FastIO
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    int id = 0;
    for(int i = 1; i < n; i++){
        bool ok = false;
        for(int j = 1; j < n; j++){
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                ok = true;
            }
        }
        if(!ok) break;

        cout << "Buoc " << i << ": ";
        for(int u = 1; u <= n; u++) cout << a[u] << " ";
        cout << '\n';
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
