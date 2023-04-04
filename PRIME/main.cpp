#include <bits/stdc++.h>
#define ll long long
#define ALL(x) (x).begin(), (x).end()

using namespace std;

const int MAX = 10000000;
int n;
ll s[MAX + 10];
vector<int> primes;
bool cx[MAX + 10];

void sieve() {
    for(int i = 2; i * i <= MAX; i++) if(!cx[i]) {
        for(int j = i * i; j <= MAX; j += i) cx[j] = true;
    }

    for(int i = 2; i <= MAX; i++) if(!cx[i]) primes.push_back(i);
}
int main()
{
    freopen("PRIME.INP", "r", stdin);
    freopen("PRIME.OUT", "w", stdout);
    sieve();
    for(int i = 0; i < primes.size(); i++) s[i + 1] = primes[i] + s[i];
    //cout << primes.size() << '\n';

    cin >> n;
    for(int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;

        int itL = lower_bound(ALL(primes), u) - primes.begin() + 1;
        int itR = upper_bound(ALL(primes), v) - primes.begin();

        double res = (s[itR] - s[itL - 1]) / (1.00 * (itR - itL + 1));
        cout << fixed << setprecision(2) << res << '\n';
    }
    return 0;
}
