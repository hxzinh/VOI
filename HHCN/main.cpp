#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const long long MOD = 1e9 + 7;
long long sAB, sAH, sBH;

int main()
{
    FastIO
    cin >> sAB >> sAH >> sBH;
    long long a = sqrt(sAH * sAB * sBH) / sBH;
    long long b = sqrt(sAH * sAB * sBH) / sAH;
    long long h = sqrt(sAH * sAB * sBH) / sAB;
    long long res = ((4 * a % MOD) + (4 * h % MOD) + (4 * b % MOD)) % MOD;
    cout << res;
    return 0;
}
