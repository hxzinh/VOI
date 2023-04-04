#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e3+10;
ll clx[]={0,1};
ll cly[]={1,0};
ll n,s[NM][NM];
char a[NM][NM];
string k;
///--------------------------------------///
struct Data
{
    ll x,y;
    string str;
};
queue <Data> q;
/** bool operator < (const Data &A,const Data &B)
{
    return A.nu < B.nu;
} **/

void readfile()
{
    freopen("FGIRD.INP","r",stdin);
    freopen("FGIRD.OUT","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> k;
}
void xuli()
{
    s[1][1]=1;
    s[1][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==k[i+j-2])
                s[i][j]=(s[i-1][j]+s[i][j-1])%1000003;
        }
    }
    cout << s[n][n] << '\n' ;
    ///cout << k;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
