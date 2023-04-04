#include <bits/stdc++.h>
#define oo 999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
string a;
int so=0,L;
int dem[]={6,2,5,5,4,5,6,3,7,6};

void readfile()
{
    freopen("EVENT.INP","r",stdin);
    freopen("EVENT.OUT","w",stdout);
    getline(cin,a);
    for(int i=0;i<a.length();i++) so+=dem[int(a[i]-48)];
    L=a.length();
}
string add(string a)
{
    string res="";
    string b="1";
    int i;
    ///while(a.length() < b.length()) a = "0" + a;
    while(b.length() < a.length()) b = "0" + b;

    int nho=0;
    int N=a.length()-1;
    for(i=N; i>=0; i--)
    {
        int x = int(a[i]-48);
        int y = int(b[i]-48);
        char z = char((x+y+nho)%10 + 48);
        nho = (x+y+nho)/10;
        res = z + res;
    }
    if (nho!=0) res = "1" + res;
    return res;
}
int hmm(string x)
{
    int d=0;
    for(int i=0;i<x.length();i++) d+=dem[int(x[i]-48)];
    return d;
}
void xuli()
{
    string nw=add(a);
    if(nw[0]=='0')
    {
        cout << "NO SOLUTION";
        return;
    }
    while(hmm(nw)!=so)
    {
        nw=add(nw);
        if(nw.length()>L)
        {
            cout << "NO SOLUTION";
            return;
        }
    }
    cout << nw;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
