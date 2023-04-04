#include <bits/stdc++.h>
#define ll long long
#define FastIO

using namespace std;
const int NM=1e3+5;
ll n,kqua=-99999999;
ll a[NM][NM],s[NM][NM];

void readfile()
{
    freopen("SQUARE.INP","r",stdin);
    freopen("SQUARE.OUT","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        s[i][0]=0;
        s[0][i]=0;
    }
    s[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> a[i][j];
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
            ///cout << s[i][j] << " ";
        }
        ///cout << '\n';
    }
}
void xuli()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=k;i<=n;i++)
        {
            for(int j=k;j<=n;j++)
            {
                ll uv=0;
                ll u=k;
                ll tam=-9999999;
                ll top=0;
                if(u<=2)
                {
                    if(u==1) tam=a[i][j];
                    else tam=max(tam,s[i][j]-s[i-u][j]-s[i][j-u]+s[i-u][j-u]);
                }
                else
                {
                    tam=0;
                    while(u>0)
                    {
                        ll x=i,y=j;
                        x=x-top;
                        y=y-top;
                        ll shiba=s[x][y]-s[x-u][y]-s[x][y-u]+s[x-u][y-u];
                        if(top%2==0) tam+=shiba;
                        else tam=tam-shiba;
                        u=u-2;
                        top++;
                    }
                }
                kqua=max(kqua,tam);
            }
        }
    }
    cout << kqua << '\n';
}
int main()
{
    readfile();
    xuli();
    return 0;
}
