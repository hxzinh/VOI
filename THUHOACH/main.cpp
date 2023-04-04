#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e6+5;
ll n,k,s[NM];
struct Data
{
    ll vt,c;
};
Data a[NM];

bool cmp(Data A,Data B)
{
    return A.vt < B.vt;
}
void readfile()
{
    freopen("THUHOACH.INP","r",stdin);
    freopen("THUHOACH.OUT","w",stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i].c >> a[i].vt;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i].c;
}
int main()
{
    FastIO
    readfile();
    return 0;
}
