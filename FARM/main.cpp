 #include <bits/stdc++.h>
 #define ll long long
 #define FastIO

using namespace std;
const int NM=1e3+10;
ll n,m,f,c;
char a[NM][NM];
bool cx[NM][NM];
ll csd[]={-1,0,1,0};
ll csc[]={0,1,0,-1};

void readfile()
{
    freopen("FARM.INP","r",stdin);
    freopen("FARM.OUT","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
            cx[i][j]=true;
        }
    }
}
void DFS(ll x,ll y)
{
    if(a[x][y]=='f') f++;
    else if(a[x][y]=='c') c++;
    for(int i=0;i<=3;i++)
    {
        ll n,m;
        n=x+csd[i];
        m=y+csc[i];
        if(a[n][m]!='#' && cx[n][m]==true)
        {
            cx[n][m]=false;
            DFS(n,m);
        }
    }
}
void xuli()
{
    ll dc=0,df=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(cx[i][j]==true && a[i][j]!='#')
            {
                f=0;
                c=0;
                cx[i][j]=false;
                DFS(i,j);
                if(c>f) dc+=c;
                else df+=f;
            }
        }
    }
    cout << df << " " << dc;
}
int main()
{
    readfile();
    xuli();
    return 0;
}
