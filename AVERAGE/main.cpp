#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, k;
double a[NM];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        k += a[i];
    }
}
void xuli(){
    sort(a + 1, a + n + 1);
    double res = a[1];
    for(int i = 2; i <= n; i++) res = double(res + a[i]) / double(2);
    double ans = double(res * n);
    cout << fixed << setprecision(5) << double(ans - k);
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
