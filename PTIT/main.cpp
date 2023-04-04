#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e4+10;
ll n,s[NM];
struct Data
{
    ll d,c;
};
Data a[NM];

void readfile()
{
    freopen("PTIT.INP","r",stdin);
    freopen("PTIT.OUT","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i].d >> a[i].c;
        s[i]=1;
    }
}
bool cmp(Data A,Data B)
{
    return A.d<B.d;
}
void xuli()
{
    sort(a+1,a+n+1,cmp);
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(a[i].d>=a[j].c)
            {
                s[i]=max(s[i],s[j]+1);
            }=
        }
    }
    ll res=-oo;
    for(int i=1;i<=n;i++) res=max(res,s[i]);
    cout << res;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
