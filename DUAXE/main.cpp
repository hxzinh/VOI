#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int n;
int a[NM];

void readfile(){
    freopen("DUAXE.INP", "r", stdin);
    freopen("DUAXE.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void xuli(){
    bool cx = true;
    int i = 1, res = 0;
    while(i <= n){
        int tam = a[i];
        while(a[i + 1] < a[i]) i++;
        while(a[i + 1] > a[i]){
            if(a[i + 1] > tam) res += (a[i + 1] - a[i]);
            i++;
        }
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
