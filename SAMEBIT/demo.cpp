#define taskname "SAMEBIT"
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
long long MOD = 123456789;

int pw(int p, int m)
{
    if(p == 0) return 1;
    if(p == 1) return 4;

    int D = pw(p / 2, m);
    D = 1LL D D % m;

    if (p % 2 == 1) D = D * 4 % m;
    return D;
}

void Dp(int n)
{
    if (n == 1 || n == 0)
    {
        cout<<0<<'\n';
        return;
    }
    int D = pw(n / 2, (3 * MOD));
    D = (D + (3 * MOD) - 1) % (3 * MOD);
    D = D / 3;
    if (n % 2 == 1) D = D * 2 % MOD;
    cout<<D<<'\n';
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("SAMEBIT.INP", "r", stdin);
    freopen("SAMEBIT.OUT", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        Dp(n);
    }
}