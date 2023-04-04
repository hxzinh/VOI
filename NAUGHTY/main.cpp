#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e6+10;
ll n,k;
ll s[NM],t[NM];
struct level
{
    ll s,vt;
};
level a[NM];

void readfile()
{
    freopen("NAUGHTY.INP","r",stdin);
    freopen("NAUGHTY.OUT","w",stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i].s;
        a[i].vt=i;
    }
}
bool cmp(level A,level B)
{
    return A.s < B.s;
}
bool check(ll x,ll y)
{
    if(abs(a[x].s-a[y].s)<k) return true;
    else return false;
}
void xuli()
{
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i].s;
    for(int i=1;i<=n;i++)
    {
        ll d=i,c=n,g;
        while(d<=c)
        {
            g=(d+c)/2;
            if(check(i,g))
            {
                t[a[i].vt]=g;
                d=g+1;
            }
            else c=g-1;
        }
    }
    for(int i=1;i<=n;i++) cout << t[i] << " ";
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
