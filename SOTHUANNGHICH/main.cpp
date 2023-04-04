#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

ll n, m;
int cntPrime[10000005];
bool isPrime[10000005];
vector<int> prime;

bool check(ll x){
    ll cur = x, tmp = 0;
    while(x != 0){
        tmp = tmp * 10 + x % 10;
        x /= 10;
    }
    return (cur == tmp);
}
int main()
{
    FastIO
    cin >> n >>  m;

    for(ll i = 1; i <= m; i++) cntPrime[i] = 0;
    for(ll i = 2; i * i <= m; i++) if(!isPrime[i]) {
        for(ll j = i + i; j <= m; j += i) isPrime[j] = true;
    }
    for(int i = 2; i <= m; i++) if(!isPrime[i]) prime.push_back(i);

    for(int u : prime){
        for(int i = u; i <= m; i += u) cntPrime[i]++;
    }

    bool ok = false;
    for(ll i = n; i <= m; i++) if(cntPrime[i] >= 3) {
        if(check(i)) {
            cout << i << " ";
            ok = true;
        }
    }
    if(!ok) cout << -1;
    return 0;
}
