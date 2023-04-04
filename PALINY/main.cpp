#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 5e5 + 10;
const int MOD = 1e9 + 7;
const int BASE = 256;
int n;
string s;
int Hash[NM], Rash[NM], pw[NM];

int getHash(int l, int r) {
	return 1LL * (Hash[r] - Hash[l - 1] + MOD) * pw[NM - r] % MOD;
}
int getRash(int l, int r){
    return 1LL * (Rash[r] - Rash[l - 1] + MOD) * pw[NM - r] % MOD;
}
bool check(int x){
    for(int i = 1; i <= n - x + 1; i++){
        int u, v;
        if(x % 2 != 0) u = v = i + x/2;
        else {
            u = i + x/2 - 1;
            v = i + x/2;
        }
        int hashL = getHash(i, u);
        int hashR = getRash(n - (i + x - 1) + 1, n - v + 1);
        if(hashL == hashR) return true;
    }
    return false;
}
void xuli(){
    int res = 0;
    int l = 1, r = n;
    while(l <= r){
        int m = (l + r) >> 1;
        if(check(m)){
            res = m;
            l = m + 1;
        } else if(check(m - 1)){
            res = m - 1;
            l = m + 1;
        } else r = m - 1;
    }
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("PALINY.INP", "r", stdin);
    freopen("PALINY.OUT", "w", stdout);
    cin >> n;
    cin >> s;
    s = " " + s;
    pw[0] = 1;
    for(int i = 1; i < NM; i++) pw[i] = 1LL * pw[i - 1] * BASE % MOD;
    for(int i = 1; i <= n; i++) Hash[i] = (Hash[i - 1] + 1LL * s[i] * pw[i]) % MOD;
    for(int i = n; i > 0; i--){
        int id = n - i + 1;
        Rash[id] = (Rash[id - 1] + 1LL * s[i] * pw[id]) % MOD;
    }

    xuli();
    return 0;
}
