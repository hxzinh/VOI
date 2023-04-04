#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 5e4 + 10;
int n, k, T;
int a[NM];

int UCLN(int a, int b){
    int tmp;
    if(a < b) swap(a, b);
    while(a % b != 0){
        tmp = a % b;
        a = b;
        b = r;
    }
    return b;
}
int BCNN(int a, int b){
    return (a * b) / UCLN(a, b);
}
int main()
{
    FastIO
    freopen("NUMCODE.INP", "r", stdin);
    freopen("NUMCODE.OUT", "w", stdout);
    cin >> T;
    while(T--){

    }
    return 0;
}
