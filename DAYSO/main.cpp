#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=2*1e5+10;
ll T,N;
ll a[NM],s[NM];

void readfile()
{
    freopen("DAYSO.INP","r",stdin);
    freopen("DAYSO.OUT","w",stdout);
    cin >> T;
}
ll cut(ll x,ll y)
{
    if(x>=y || x<=0 || y>N || x>N || y<=0) return 0;
    for(int i=x;i<=y;i++)
        if(s[i]-s[x-1]==(s[y]-s[x-1])-(s[i]-s[x-1])) return max(1+cut(x,i),1+cut(i+1,y));
    return 0;
}
void xuli()
{
    for(int i=1;i<=T;i++)
    {
        cin >> N;
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
        for(int j=1;j<=N;j++)
        {
            cin >> a[j];
            s[j]=s[j-1]+a[j];
        }
        cout << cut(1,N) << '\n';
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
