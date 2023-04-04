#include <bits/stdc++.h>
#define ll long long
#define f double

using namespace std;
const int NM=1e6+5;
ll T,a,b,dem=0;

void xuli(ll a,ll b)
{
    double x,y;
    double k,u;
    double tam=2*(a*b);
    while(tam>0)
    {
        y=tam;
        float k=1/(f(a)*f(b))-(1/f(y));
        if(f(k)<=0) break;
        u=1/k;
        if(u>=int(u)+0.9) u=int(u+0.5);
        x=(int)(u+0.5);
        if(x==u)
        {
            if(x==y) dem++;
            else dem+=2;
        }
        tam--;
    }
}
void readfile()
{
    freopen("EQUA.INP","r",stdin);
    freopen("EQUA.OUT","w",stdout);
    cin >> T;
    for(ll i=1;i<=T;i++)
    {
        cin >> a >> b;
        dem=0;
        xuli(a,b);
        cout << dem << '\n';
    }
}
int main()
{
    readfile();
    return 0;
}
