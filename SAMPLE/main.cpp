#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e6+5;
ll n,m,k;
ll oct[NM],mem[NM],v[NM];
string a[NM];

void readfile()
{
    freopen("SAMPLE.INP","r",stdin);
    freopen("SAMPLE.OUT","w",stdout);
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    memset(mem,0,sizeof(mem));
}
ll sett(string x)
{
    ll res=0,t=-1;
    for(int i=x.length()-1;i>=0;i--)
    {
        t++;
        ll u=int(x[i]-48);
        res+=u*pow(2,t);
    }
    return res;
}
void xuli()
{
    ll dem=0,ans=0;
    for(int i=0;i<n;i++)
    {
        ll u=sett(a[i]);
        if(mem[u]==0)
        {
            dem++;
            v[dem]=u;
        }
        mem[u]++;
    }
    ///for(int i=1;i<=dem;i++) cout << v[i] << " ";
    if(m==k)
    {
        string tam="";
        for(int i=1;i<=k;i++) tam+='1';
        ll u=sett(tam);
        for(int i=1;i<=dem;i++)
        {
            if(mem[u^v[i]]!=0 && mem[v[i]]>0)
            {
                ans+=mem[u^v[i]]*mem[v[i]];
                mem[u^v[i]]=mem[v[i]]=0;
            }
        }
    }
    else
    {
        for(int i=1;i<dem;i++)
        {
            for(int j=i+1;j<=dem;j++)
            {
                ll u=__builtin_popcountll(v[i]^v[j]);
                if(u==k) ans+=mem[v[i]]*mem[v[j]];
            }
        }
    }
    cout << ans;
}
int main()
{
    FastIO
    readfile();
    ///for(int i=0;i<n;i++) cout << a[i] << '\n';
    xuli();
    return 0;
}
