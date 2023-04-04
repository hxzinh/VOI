#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e4;
ll n,a[105],q[NM][200],k,mx=-1;

void readfile()
{
    ll i;
    freopen("CHANGE.INP","r",stdin);
    freopen("CHANGE.OUT","w",stdout);
    cin >> k >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        mx=max(mx,a[i]);
    }
    for(i=n+1;i<=2*n;i++)
    {
        a[i]=-a[i-n];
    }
}
void xuli()
{
    ll i,j,tam,kqua=1e9;
    for(i=0;i<=k;i++) q[0][i]=1e9;
    for(i=0;i<=n;i++) q[i][0]=0;
    for(i=n+1;i<=2*n;i++) q[i][0]=1;
    for(i=1;i<=2*n;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(j>=a[i]){
                q[i][j]=min(q[i-1][j],q[i][j-a[i]]+1);
            }else q[i][j]=q[i-1][j];
        }
    }
    for(i=1;i<=2*n;i++)
    {
        for(j=1;j<=k;j++)
        {
            cout << q[i][j] << "\t";
        }
        cout << '\n';
    }
    cout << '\n';
    cout << q[n][k];
}
int main()
{
    readfile();
    xuli();
    return 0;
}
