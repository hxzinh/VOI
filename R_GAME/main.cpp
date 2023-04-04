#include <bits/stdc++.h>
#define ll long long
#define oo 1e18
#define tp double
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e6+5;
ll T,n;
double a[NM];
bool cx[NM];
double s[NM][3];

double dp(ll x,ll t)
{
    double &res=s[x][t];
    if(res!=-oo) return res;
    if(t==0)
    {
        res=max({res,a[x+1]+dp(x+1,0),dp(x+1,1)});
    }
    if(t==1)
    {
        res=max({res,(a[x-1]+a[x+1])/2+dp(x+1,0),a[x-1]+dp(x+1,1)});
    }
    return res;
}
void readfile()
{
    freopen("RGAME.INP","r",stdin);
    freopen("RGAME.OUT","w",stdout);
    cin >> T;
    for(int i=1;i<=T;i++)
    {
        cin >> n;
      ///  memset(cx,true,sizeof(cx));
        for(int j=1;j<=n;j++) cin >> a[j];
        for(int c=1;c<=n;c++)
            for(int j=0;j<=1;j++) s[c][j]=-oo;
        s[n][1]=a[n-1];
        s[n][0]=0;
        cout << fixed << setprecision(1) << dp(1,0) << '\n';
    }
}
int main()
{
    FastIO
    readfile();
    return 0;
}






















































 double dp(ll l,ll r,ll x,ll y)
{
    if(l>r) return 0;
    if(l==r)
    {
        if(x==1 && y==1) return (a[l-1]+a[l+1])/2;
        if(x==1) return a[l-1];
        if(y==1) return a[l+1];
        return 0;
    }
    double &res=s[l][r];
    if(s[l][r]!=-1) return s[l][r];
    for(int i=l;i<=r;i++)
    {
        if(cx[i-1] && cx[i+1]) {
            cx[i]=false;
            res=max(res,(a[i-1]+a[i+1])/2+dp(l,i-1,x,0)+dp(i+1,r,0,y));
            cx[i]=true;
            continue;
        }
        if(cx[i-1]) {
            cx[i]=false;
            res=max(res,a[i-1]+dp(l,i-1,x,0)+dp(i+2,r,0,y));
            cx[i]=true;
            continue;
        }
        if(cx[i+1]) {
            cx[i]=false;
            res=max(res,a[i+1]+dp(i+1,r,0,y)+dp(l,i-2,x,0));
            cx[i]=true;
            continue;
        }
    }
    return res;
}
void readfile()
{
    freopen("RGAME.INP","r",stdin);
    freopen("RGAME.OUT","w",stdout);
    cin >> T;
    for(int i=1;i<=T;i++)
    {
        memset(cx,true,sizeof(cx));
        memset(a,0,sizeof(a));
        cin >> n;
        for(int c=1;c<=n;c++)
            for(int j=1;j<=n;j++) s[c][j]=-1;
        cx[0]=false;
        cx[n+1]=false;
        for(int j=1;j<=n;j++)
            cin >> a[j];
        cout << fixed << setprecision(1) << dp(1,n,0,0) << '\n';
    }
} **/
