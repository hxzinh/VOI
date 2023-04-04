#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int n;
ll a[200005];

int main()
{
    FastIO
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    ll res = 0;
    for(int i = 2; i <= n; i++) if(a[i] < a[i - 1]){
        res += a[i - 1] - a[i];
        a[i] = a[i - 1];
    }
    cout << res;
    return 0;
}
