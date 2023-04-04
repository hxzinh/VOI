#include <bits/stdc++.h>
#define ll long long
#define oo 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e5+10;
ll n,m,r;
ll c[NM],R[NM],s[NM],k[NM];
struct ban
{
    ll sp,g;
};
ban p[NM];

void readfile()
{
    freopen("BASE.INP","r",stdin);
    freopen("BASE.OUT","w",stdout);
    cin >> n >> m >> r;
    for(int i=1;i<=n;i++)
    {
        cin >> c[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin >> p[i].sp >> p[i].g;
    }
    for(int i=1;i<=r;i++)
    {
        cin >> R[i];
    }
}
bool cmp(ll a,ll b)
{
    return a > b;
}
bool cap(ban a,ban b)
{
    return  a.g > b.g;
}
void xuli()
{
    ll d=1,res=-oo;
    sort(c+1,c+n+1,cmp);
    sort(R+1,R+r+1,cmp);
    sort(p+1,p+m+1,cap);
    for(int i=1;i<=n;i++)
    {
        while(c[i]>0)
        {
            if(d>r) break;
            if(c[i]<=p[d].sp)
            {
                s[i]+=p[d].g*c[i];
                p[d].sp-=c[i];
                c[i]=0;
            }
            else {
                s[i]+=p[d].sp*p[d].g;
                c[i]-=p[d].sp;
                d++;
            }
        }
        s[i]+=s[i-1];
        ///cout << s[i] << '\n';
    }
    for(int i=1;i<=n;i++)
    {
        k[i]=k[i-1]+R[i];
        ///cout << k[i] << '\n';
    }
    for(int i=0;i<=n;i++)
    {
        res=max(res,s[i]+k[n-i]);
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
