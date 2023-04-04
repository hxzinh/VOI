#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int x, y, u, v;

int main()
{
    FastIO
    cin >> x >> y >> u >> v;
    if(x > y) swap(x, y);
    if(u > v) swap(u, v);
    if(x > u){
        swap(x, u);
        swap(y, v);
    }

    int res = 0;
    if(y >= u) res = max(v, y) - x;
    else res = y - x + v - u;
    cout << res;
    return 0;
}
