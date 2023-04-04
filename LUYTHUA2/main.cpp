#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int MOD = 1e9 + 7;
const int NM = 1e6 + 10;
ll a, b, c, T;
ll frac[NM], finv[NM];

long long solve(long long base , long long exp , long long mod)
{
   long long res = 1;
    while(exp){
        if(exp & 1) res = (res%mod * base%mod) % mod;
        exp = exp >> 1;
        base = (base%mod * base%mod) % mod;
    }
    return res;
}
int main()
{
    FastIO
    cin >> T;
    while(T--){
        cin >> a >> b >> c;
        if(a == -1 &&  b == -1 && c == -1) break;
        if(c == 0) cout << (a % MOD) << '\n';
        else if(b == 0) cout << "1" << '\n';
        else if(a % MOD == 0) cout << "0" << '\n';
        else {
            long long result2 = solve(b, c, MOD - 1);
            long long result1 = solve(a, result2, MOD);
            cout << result1 << '\n';
        }
    }
    return 0;
}
