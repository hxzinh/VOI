#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e4+10;
ll a[14];

bool  check()
{
    sort(a+1,a+13);
    for(int i=2;i<=4;i++) if(a[i]!=a[i-1]) return false;
    for(int i=6;i<=8;i++) if(a[i]!=a[i-1]) return false;
    for(int i=10;i<=12;i++) if(a[i]!=a[i-1]) return false;
    return true;
}
void readfile()
{
    freopen("PARALLEL.INP","r",stdin);
    freopen("PARALLEL.OUT","w",stdout);
    while(true)
    {
        bool cx=false;
        memset(a,0,sizeof(a));
        for(int i=1;i<=12;i++)
        {
            cin >> a[i];
        }
        for(int i=1;i<=12;i++)
            if(a[i]!=0) cx=true;
        if(!cx) break;
        else if(check()) cout << "yes" << '\n';
             else cout << "no" << '\n';
    }
}
int main()
{
    FastIO
    readfile();
    return 0;
}
