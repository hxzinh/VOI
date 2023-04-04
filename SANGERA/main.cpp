#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

using namespace std;
int n;

void readfilr(){
    freopen("ERATHANOS.INP", "r", stdin);
    freopen("ERATHANOS.OUT", "w", stdout);
    cin >> n;
}
void erathanos(int l, int r){
    vector<bool> isPrime(r - l + 1, true);
    for(int i = 2; i * i <= r; i++){
        for(int j = max((i * i), (l + i - 1) / i * i); j <= r; j += i){
            isPrime[j - l] = false;
        }
    }
    if(1 >= l) isPrime[1 - l] = false;
    for(int i = l; i <= r; i++) if(isPrime[i - l]) cout << i << " ";
}
void xuli(){
    while(n--){
        int l, r;
        cin >> l >> r;
        erathanos(l, r);
        cout << '\n';
    }
}
int32_t main()
{
    FastIO
    readfilr();
    xuli();
    return 0;
}
