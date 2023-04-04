#include <bits/stdc++.h>
#define int long long
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

const int NM = 1e5 + 10;
int n, k;
ii a[NM];

bool tmp(const ii &A, const ii &B){
    return A.fi < B.fi;
}
void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int u, v;
        cin >> a[i].fi >> a[i].se;
    }
    cin >> k;
    sort(a + 1, a + n + 1, tmp);
}
void xuli(){
    for(int i = 1; i <= n; i++){
        if(k <= a[i].se) cout << a[i].fi;
        k -= a[i].se;
        if(k <= 0) break;
    }
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
