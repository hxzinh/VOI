#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int NM=1e6+5;
ll a,k,b,T,m;
struct sett
{
    ll u,v;
};

bool tong(ll u,ll v,ll x,ll y)
{
    ll a=y-x;
    ll b=v-u;
    if(a==b && a>=0) return true;
    else return false;
}
bool tich(ll u,ll v,ll k,ll x,ll y)
{
    ll tam;
    u=u*k;
    v=v*k;
    tam=u-v;
    if(tong(u,v,a,b)==true) return true;
    else {
        if(v-u<y-x)
        {
            if(tich(u,v,k,x,y)==true) return true;
        }
        else return  false;
    }
}
bool check(ll u,ll v,ll x,ll y)
{
    ll a,b;
    if(tong(u,v,x,y)==true) return true;
    else {
        if(v-u==0) return false;
        if(v-u<y-x)
        {
            if(tich(u,v,k,x,y)==true) return true;
        }
        else return false;
    }
}
void readfile()
{
    ll u,v;
    freopen("SET.INP","r",stdin);
    freopen("SET.OUT","w",stdout);
    cin >> T;
    for(int i=1;i<=T;i++)
    {
        cin >> k >> a >> b;
        cin >> m;
        for(ll j=1;j<=m;j++)
        {
            cin >> u >> v;
            if(v-u!=0) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
}
int main()
{
    readfile();
    return 0;
}
