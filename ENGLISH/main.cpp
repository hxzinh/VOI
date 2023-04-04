#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

double x, y, u, v;

double toInt(double res){
    double tmp = int(x);
    double K1 = float(tmp);
    double K2 = float(tmp) + 0.5;
    double K3 = float(tmp + 1);
    if(res - K1 < abs(res - K2)) res = K1;
    else if(abs(K2 - res) < K3 - res) res = K2;
    else res = K3;

    return res;
}
int main()
{
    FastIO
    freopen("ENGLISH.INP", "r", stdin);
    freopen("ENGLISH.OUT", "w", stdout);
    cin >> x >> y >> u >> v;
    //x = toInt(x); y = toInt(y); u = toInt(u); v = toInt(v);
    double res = (x + y + u + v) / 4.00;
    res = toInt(res);
    cout << fixed << setprecision(1) << res << " ";
    if(res >= 4.0 && res < 5.5) cout << "B1";
    else if(res >= 5.5 && res < 7.0) cout << "B2";
    else if(res >= 7.0 && res < 8.5) cout << "C1";
    else if(res >= 8.5 && res <= 9.0) cout << "C2";
    return 0;
}
