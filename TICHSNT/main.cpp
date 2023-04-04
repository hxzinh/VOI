#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e7 + 10;
ll T, n, k;
bool isPrime[NM];
vector<ll> prime;

void sieve() {
    for(ll i = 2; i * i <= 10000000; i++) if(!isPrime[i]) {
        for(ll j = i * i; j <= 10000000; j += i) isPrime[j] = true;
    }

    for(int i = 2; i <= 10000000; i++) if(!isPrime[i]) {
        prime.push_back(i);
    }

    cout << 1LL * 9999991 * 9999973 << '\n';
}
ll pw(ll x, ll k) {
    if(k <= 1) return k ? x : 1;
    ll tmp = pw(x, k / 2);
    if(tmp == 0) return 0;
    if(k & 1) return (tmp * tmp * x > n) ? 0 : (tmp * tmp * x);
    else return (tmp * tmp > n) ? 0 : (tmp * tmp);
}
void xuli() {
    int cnt = 0, id = -1;
    bool ok = false;
    for(ll i = 2; i * i <= n; i++) if(n % i == 0) {
        if(!ok) {
            if(!pw(i, k - cnt)) {
                cout << "NO" << '\n';
                return;
            } else ok = true;
        }

        n /= i;
        if(n % i == 0) {
            cout << "NO" << '\n';
            return;
        }

        cnt++;
        if(id == -1) id = lower_bound(ALL(prime), i) - prime.begin();
        else {
            if(prime[id + 1] != i) {
                cout << "NO" << '\n';
                return;
            } else id++;
        }
    }
    if(n > 1) {
        if(id == -1) cnt++;
        else {
            if(prime[id + 1] == n) cnt++;
            else {
                cout << "NO" << '\n';
                return;
            }
        }
    }

    if(cnt == k) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
void sub1() {
    bool ok = false;
    for(ll i = 2; i * i <= n; i++) if(n % i == 0) {
        cout << "NO" << '\n';
        return;
    }

    if(n > 1) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
int32_t main()
{
    FastIO
    freopen("TICHSNT.INP", "r", stdin);
    freopen("TICHSNT.OUT", "w", stdout);
    cin >> T;
    sieve();
    while(T--) {
        cin >> n >> k;

        if(k == 1) sub1();
        else xuli();
    }
    return 0;
}

