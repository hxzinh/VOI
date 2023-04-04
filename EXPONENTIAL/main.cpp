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

bool check(int x){
    int cnt = 0;
    for(int i = 2; i * i <= x; i++) if(x % i == 0){
        int tam = x;
        while(tam % i == 0)
            tam /= i;
        if(tam == 1) return true;
    }
    return false;
}
void xuli(){
    int k = sqrt(n);
    int res = -1;
    for(int i = k * k; i <= n; i++)
        if(check(i)) res = i;

    cout << res;
}
int main()
{
    FastIO
    freopen("EXPONENTIAL.INP", "r", stdin);
    freopen("EXPONENTIAL.OUT", "w", stdout);
    cin >> n;

    xuli();
    return 0;
}
