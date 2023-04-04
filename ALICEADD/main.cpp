#include <bits/stdc++.h>
#define ll long long
#define oo 1e18
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
ll t;

void sum(string a,string b)
{
    ll nho=0,tam;
    string res;
    for(int i=a.length()-1;i>=0;i--)
    {
        ll u,x,y;
        x=int(a[i])-48;
        y=int(b[i])-48;
        u=(x+y+nho)%10;
        nho=(x+y+nho)/10;
        res=char(u+48)+res;
    }
    if(nho>0) res=char(nho+48)+res;
    cout << res << '\n';
}
void readfile(){
    freopen("aliceadd.inp","r",stdin);
    freopen("aliceadd.out","w",stdout);
    cin >> t;
    for(int i=1;i<=t;i++){
        string a,b;
        cin >> a >> b;
        while(a.length()<b.length()) a='0'+a;
        while(b.length()<a.length()) b='0'+b;
        sum(a,b);
    }
}
int main(){
    FastIO
    readfile();
    return 0;
}
