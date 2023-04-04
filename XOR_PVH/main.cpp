#include <bits/stdc++.h>
#define ll long long

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("XOR.INP", "r", stdin);
    freopen("XOR.OUT", "w", stdout);

    ll n, m;
    cin >> n >> m;

    ll res, ans, kqua;
    ll tmp = m * (n / m), tam = m * (n / m + (n % m != 0));
    res = n ^ tmp;
    ans = n ^ m;
    kqua = n ^ tam;
    cout << min({res, ans, kqua, n});

    //int cur = 100 ^ 122;
    //cout << cur;
    return 0;
}
