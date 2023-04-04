#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e4 + 10;
int n, k;
int a[NM];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void xuli(){
    int s = a[1];
    for(int i = 2; i <= n; i++){
        s = s ^ a[i];
    }
    s = 0;
    cout << s;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
