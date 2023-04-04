#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

ll n;
bool isPrime[10000005];
vector<ll> prime;

int main()
{
    FastIO
    cin >> n;

    for(ll i = 2; i * i <= n; i++) if(!isPrime[i]) {
        for(ll j = i * i; j <= n; j += i) isPrime[j] = true;
    }
    for(ll i = 2; i <= n; i++) if(!isPrime[i]) prime.push_back(i);

    int cnt = 0;
    for(ll i : prime){
        bool ok = true;
        ll tmp = i;
        int last = tmp % 10;
        tmp /= 10;
        while(tmp != 0){
            if(maximize(last, tmp % 10)){
                ok = false;
                break;
            }
            tmp /= 10;
        }
        if(ok) {
            cnt++;
            cout << i << " ";
        }
    }
    cout << '\n';
    cout << cnt;
    return 0;
}
