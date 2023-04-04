#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
string a,b;

void readfile()
{
    freopen("TONGHIEU.INP","r",stdin);
    freopen("TONGHIEU.OUT","w",stdout);
    getline(cin,a);
    getline(cin,b);
}
string tong(string x,string y)
{
    string s="";
    int nho=0;
    while(x.length()<y.length()) x='0'+x;
    while(x.length()>y.length()) y='0'+y;
    for(int i=x.length()-1;i>=0;i--)
    {
        int u=int(x[i]-48);
        int v=int(y[i]-48);
        char w=char((u+v+nho)%10+48);
        nho=(u+v)/10;
        s=w+s;
    }
    if(nho!=0) s='1'+s;
    return s;
}
string hieu(string a,string b)
{
    string res="";
    ll nho=0,tam;
    if(a>b)
    for(int i=a.length()-1;i>=0;i--)
    {

        while(b.length()<a.length())
        {
            b='0'+b;
        }
        ll u,x,y;
        x=int(a[i])-48;
        y=int(b[i])-48;
        if(x-nho<y)
        {
            u=(x-nho)+10-y;
            nho=1;
        }
        else
        {
            u=(x-nho)-y;
            nho=0;
        }
        res=char(u+48)+res;
        while(res[0]=='0') res.erase(0,1);
    }
    else
    {
        for(int i=a.length()-1;i>=0;i--)
        {
            while(b.length()>a.length())
            {
                a='0'+a;
            }
            ll u,x,y;
            x=int(b[i]-48);
            y=int(a[i]-48);
            if(x-nho<y)
            {
                u=(x-nho)+10-y;
                nho=1;
            }
            else
            {
                u=(x-nho)-y;
                nho=0;
            }
            res=char(u+48)+res;
            while(res[0]=='0') res.erase(0,1);
        }
        res='-'+res;
    }
    return res;
}
string chia(string x)
{
    bool ok=true;
    int k=x.length();
    if(int(x[k-1]-48)%2!=0)
    {
        ok=false;
        x[k-1]=char(int(x[k-1]-48-1)+48);
    }
}
void xuli()
{
    string t;
    if(a[0]=='-' && b[0]=='-')
    {
        a.erase(0,1);
        b.erase(0,1);
        t='-'+tong(a,b);
    }
    else if(a[0]=='-') t=hieu(a,b);
    else if(b[0]=='-') t=hieu(a,b);
    else t=tong(a,b);
    cout << t;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
