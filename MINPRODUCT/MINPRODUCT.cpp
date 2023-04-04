#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int n;
int minn = INF, tinn = INF, maxx = -INF, tann = -INF;
int a[NM];
bool zero;

int32_t main()
{
    FastIO
    freopen("MINPRODUCT.INP", "r", stdin);
    freopen("MINPRODUCT.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(minn >= a[i]){
            tinn = minn;
            minn = a[i];
        }
        if(maxx <= a[i]){
            tann = maxx;
            maxx = a[i];
        }
    }

    int res;
    if(minn >= 0) res = minn * tinn;
    else if(maxx <= 0) res = maxx * tann;
    else res = minn * maxx;
    cout << res;
    return 0;
}
