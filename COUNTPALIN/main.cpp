#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

string s;
int n, f[1000];

bool isPalin(int x, int y){
    if(x >= y) return true;
    if(s[x] != s[y]) return false;
    return isPalin(x + 1, y - 1);
}
int main()
{
    FastIO
    freopen("COUNTPALIN.INP", "r", stdin);
    freopen("COUNTPALIN.OUT", "w", stdout);
    cin >> s;
    n = s.size();
    s = " " + s;

    memset(f, INF, sizeof f);
    f[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j > 0; j--){
            if(isPalin(j, i)) minimize(f[i], f[j - 1] + 1);
        }
    }
    cout << f[n];
    return 0;
}
