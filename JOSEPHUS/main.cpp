#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int n, m, p, y;
vector<int> id;

void readfile(){
    freopen("JOSEPHUS.INP", "r", stdin);
    freopen("JOSEPHUS.OUT", "w", stdout);
    cin >> n >> m >> p >> y;
}
void xuli(){
    int f = 0;
    for(int i = 2; i <= n; i++){
        f = (f + m) % i;
    }
    int u = (f + p >= n ? f + p - n : f + p);
    int v = (y - f <
             0 ? y - f + n : y - f);
    cout << u << " " << v;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
