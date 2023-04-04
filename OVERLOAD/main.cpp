#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e5+10;
ll n,m;
ll t[NM];
struct Data
{
    ll cs,vt;
};
vector <Data> a;

void readfile()
{
    freopen("OVERLOAD.INP","r",stdin);
    freopen("OVERLOAD.OUT","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        ll u;
        cin >> u;
        a.push_back({u,i});
    }
    memset(t,-1,sizeof(t));
    for(int i=1;i<=m;i++)
    {
        ll u;
        cin >> u;
        for(int j=a.size()-1;j>=0;j--)
        {
            ll v=a[j].vt;
            if(a[j].cs<=u && t[v]==-1)
            {
                t[v]=i;
                a.erase(a.begin()+j);
                break;
            }
            else continue;
        }
    }
}
void xuli()
{
    for(int i=1;i<=n;i++) cout << t[i] << '\n';
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
