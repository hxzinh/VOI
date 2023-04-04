#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
string a,b;

void readfile()
{
    freopen("SUMBIG.INP","r",stdin);
    freopen("SUMBIG.OUT","w",stdout);
    getline(cin,a);
    getline(cin,b);
}
string sum(string x,string y)
{
    ll nho=0;
    string res="";
    while(x.length()<y.length()) x='0'+x;
    while(y.length()<x.length()) y='0'+y;
    for(int i=x.length()-1;i>=0;i--)
    {
        int a=int(x[i]-48);
        int b=int(y[i]-48);

    }
}
int main()
{
    FastIO
    cout << "Hello world!" << endl;
    return 0;
}
