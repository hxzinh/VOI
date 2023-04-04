#include <bits/stdc++.h>
#define ll long long
#define oo 1e18
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

string a;
ll ans=0;

void readfile(){
    freopen("STRALT.INP","r",stdin);
    freopen("STRALT.OUT","w",stdout);
    cin >> a;
}
string repeatt(string x,ll n){
    string res="";
    for(int i=1;i<=n;i++) res=res+x;
    return res;
}
string even(string x){
    string res=x;
    for(int i=x.length()-1;i>=0;i--) res=res+x[i];
    return res;
}
string odd(string x){
    string res=x;
    for(int i=x.length()-2;i>=0;i--) res=res+x[i];
    return res;
}
string dp(int d,int c){
    ll dem=0;
    string res="";
    for(int i=d;i<=c;i++){
        if(a[i]<='9' && a[i]>='0'){
            dem=dem*10+int(a[i]-48);
        } else
        if(a[i]=='('){
            ll j=i+1,t=0;
            ans++;
            while(a[j]!=')' || t!=0){
                if(a[j]=='(') t++;
                if(a[j]==')') t--;
                j++;
            }
            res=res+repeatt(dp(i+1,j-1),dem);
            dem=0;
            i=j;
        } else
        if(a[i]=='[' && a[i+1]=='*'){
            ll j=i+2, t=0;
            ans++;
            while(a[j]!=']' || t!=0){
                if(a[j]=='[') t++;
                if(a[j]==']') t--;
                j++;
            }
            res=res+even(dp(i+2,j-1));
            i=j;
        } else
        if(a[i]=='['){
            ll j=i+1, t=0;
            ans++;
            while(a[j]!=']' || t!=0){
                if(a[j]=='[') t++;
                if(a[j]==']') t--;
                j++;
            }
            res=res+odd(dp(i+1,j-1));
            i=j;
        } else
        if(a[i]!=']' && a[i]!='*' && a[i]!=')') res=res+a[i];
    }
    return res;
}
void xuli(){
    string res=dp(0,a.length()-1);
    cout << ans << '\n';
    cout << res << '\n';
    cout << clock() << fixed << setprecision(2);
}
int main(){
    FastIO
    readfile();
    xuli();
    return 0;
}
