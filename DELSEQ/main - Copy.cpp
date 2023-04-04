#include <bits/stdc++.h>
#define int long long

#define MASK(u) (1LL << (u))
#define BIT(u,i) (((u) >> (i)) & 1LL)
using namespace std;

long long F[2500][MASK(11)] , a[1005];
int n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];

    int d = 1;
    for(int i = 2 ; i <= n ; i = i*2)
    d++;

    for(int i = 0 ; i <= n ; i++)
    for(int j = 0 ; j < MASK(d) ; j++)
    F[i][j] = -1e18;

    F[1][MASK(d) - 1] = a[1];
    F[1][ (MASK(d) - 1)^1] = 0;
    for(int i = 1 ; i < n ; i++)
    for(int j = 0 ; j < MASK(d) ; j++)
    if(F[i][j] != -1e18)
    {
        int p = 1;
        for(int v = 0 ; v < d ; v++)
        {
            if(v != 0) p = p*2;
            if(BIT(j,v))
            {
                int nma = j ^ MASK(v);
                F[i + p][nma] = max(F[i+p][nma],F[i][j]);

            }

        }
        F[i+1][j] = max(F[i+1][j],F[i][j] + a[i+1]);

    }
    long long Ans = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 0 ; j < MASK(d) ; j++)
        Ans = max(Ans,F[i][j]);
    }
    cout<<Ans;
    return 0;
}