#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int MOD = 123456789;
const int NMOD = 3 * MOD;
const int NM = 1e6 + 10;
int T, n;
int s[10000005];

void prepare(){
    s[0] = 0;
    s[1] = 0;
    for(int i = 1; i <= 10000000; i++){
        if(i % 2 == 0) s[i] = (s[i - 1] * 2 + 1) % MOD;
        else s[i] = (s[i - 1] * 2) % MOD;
    }
}
int pw(int x){
    if(x == 0) return 1;
    if(x == 1) return 4;
    int t = pw(x >> 1);
    if(x % 2 == 0) return t * t % NMOD;
    else return t * t * 4 % NMOD;
}
int getAns(int x){
    if(x <= 1) return 0;

    int k = n / 2;
    int res = pw(k);
    res = (res + NMOD - 1) % NMOD;
    res /= 3;
    if(x % 2 != 0) return (res << 1) % MOD;
    else return res;
}
int32_t main()
{
    FastIO
    freopen("SAMEBIT.INP", "r", stdin);
    freopen("SAMEBIT.OUT", "w", stdout);
    cin >> T;
    prepare();

    while(T--){
        cin >> n;
        cout << getAns(n) << '\n';
    }
    return 0;
}
