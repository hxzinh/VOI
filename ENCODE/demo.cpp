#include <bits/stdc++.h>

#define ii pair<int,int>
#define fi first
#define se second
#define BIT(u,i) (((u) >> (i)) & 1LL)
#define MASK(u) (1LL << (u))
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FORD(i,r,l) for(int i = r ; i >= l ; i--)
#define FORE(e,Op) for(auto e : Op)
#define MOD 1000000007
using namespace std;

int t;
int pw[7] , a[10];
long long Ans[1000006];
long long dp[100005][10][3],Ld[100005][10][3];
void tru1(string &a)
{
    int nho = 1;
    for(int i = a.size() - 1 ; i >= 0 ; i--)
    {
        int q = a[i] - '0';
        if(q < nho)
        {
            q = 10+q;
            q -= nho;
            nho = 1;
        }
        else q -= nho , nho = 0;
        a[i] = char(q + '0');
    }
    while(a[0] == '0' && a.size() > 1) a.erase(0,1);
}
void add(long long &a,long long b)
{
    a = a + b;
    a = a % MOD;
}

long long walkonsegemntree(string D)
{
    for(auto &u : D) u -='0';

    D = " " + D;
    int n = D.size() - 1;
    FOR(i,1,n) FOR(j,0,9) FOR(u,0,2) dp[i][j][u] = Ld[i][j][u] = 0;

    FOR(i,1,9)
    {
        int s = 2;
        if(i > D[1]) s = 0;
        if(i == D[1]) s = 1;

        dp[1][i][s] = i;
        Ld[1][i][s] = 1;
    }

    FOR(i,1,n-1)
    FOR(u,0,9)
    FOR(s,0,2)
    if(dp[i][u][s])
    {
        FOR(v,0,9)
        {
            int ns = s;
            if(s == 1)
            {
                if(v > D[i+1]) ns = 0;
                if(v < D[i+1]) ns = 2;
                if(v == D[i+1]) ns = 1;
            }

            add(dp[i+1][v][ns],(dp[i][u][s]*10 + (v != u)*v*Ld[i][u][s])%MOD);
            add(Ld[i+1][v][ns],Ld[i][u][s]);
        }
    }
    /*FOR(i,n-1,n-1)
    FOR(u,0,9)
    FOR(s,1,2)
    if(dp[i][u][s])
    {
        FOR(v,0,9)
        {
            int ns = s;
            if(s == 1)
            {
                if(v > D[i+1]) ns = 0;
                if(v < D[i+1]) ns = 2;
                if(v == D[i+1]) ns = 1;
            }

            add(dp[i+1][v][ns],dp[i][u][s]*10%MOD + (v != u)*v);
        }
    }*/
    long long Ans = 0;
    FOR(i,1,n-1)
    FOR(u,0,9)
    FOR(s,0,2)
    add(Ans,dp[i][u][s]);

    FOR(u,0,9)
    {
        add(Ans,dp[n][u][1]) , add(Ans,dp[n][u][2]);
    }
    return Ans;

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        string a,b;
        cin >> a >> b;
        tru1(a);
        cout<<(walkonsegemntree(b) - walkonsegemntree(a) + MOD)%MOD<<'\n';
    }

    return 0;
}x