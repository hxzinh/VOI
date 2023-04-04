#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e6+5;
////ll n,c[NM],minn=0,s[100000][1000],S[NM];
ll n,s[100000][1000];
vector <ll> a[NM];

void readfile()
{
    freopen("PIG.INP","r",stdin);
    freopen("PIG.OUT","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        ll u;
        cin >> u;
        for(int j=1;j<=u;j++)
        {
            ll v;
            cin >> v;
            a[i].push_back(v);
        }
    }
}
/** ll dp(ll x,ll y,ll m)
{
    if(x>n) return 0;
    ll &res=s[x][y];
    if(res!=-1) return res;
    if(a[x][y]<m)
    {
        for(int i=0;i<a[x+1].size();i++)
        {
            res=max(res,dp(x+1,i,m));
        }
    }
    for(int i=0;i<=a[x+1].size();i++)
    {
        res=max(res,a[x][y]+dp(x+1,i,a[x][y]));
    }
    return res;
}
void xuli()
{
    ll ans=-oo;
    memset(s,-1,sizeof(s));
    for(int i=0;i<a[1].size();i++) ans=max(ans,dp(1,i,0));
    cout << ans;
}
 **/
void xuli()
{
    ll res=-oo;
    memset(s,-1,sizeof(s));
    for(int i=0;i<a[1].size();i++) s[1][i]=a[1][i];
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            ll u=a[i][j];
            for(int k=1;k<i;k++)
            {
                for(int g=0;g<a[k].size();g++)
                {
                    ll v=a[k][g];
                    if(u>=v && s[k][g]+u>s[i][j]) s[i][j]=s[k][g]+u;
                    res=max(res,s[i][j]);
                }
            }
        }
    }
    cout << res;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
