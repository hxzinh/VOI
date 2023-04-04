#include <bits/stdc++.h>
#define ll int
#define oo 1e4
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=25;
ll n,res=0;
ll a[NM];
string ans[100010];
bool cx[1000],ok[NM];

void readfile(){
    freopen("pcircle.inp","r",stdin);
    freopen("pcircle.out","w",stdout);
    cin >> n;
    for(int i=1;i<=2*n;i++) a[i]=-oo;
    a[1]=1; a[2*n+1]=1;
    memset(cx,true,sizeof(cx));
    memset(ok,true,sizeof(ok));
}
void prime(){
    cx[1]=false;
    for(int i=2;i<=32;i++){
        if(cx[i]){
            for(int j=i*i;j<=1000;j+=i) cx[j]=false;
        }
    }
}
void back(ll x){
    for(int i=2;i<=2*n;i++){
        if(!ok[i]) continue;
        ll tam=i+a[x-1];
        if(cx[tam] && ok[i]){
            if(x==2*n && cx[i+1]){
                res++;
                if(res<=10000) for(int j=1;j<=2*n-1;j++) ans[res]=ans[res]+char(a[j]+48);
                ans[res]=ans[res]+char(i+48);
                continue;
            }
            ok[i]=false;
            a[x]=i;
            back(x+1);
            ok[i]=true; a[x]=-oo;
        }
    }
}
void xuli(){
    prime();
    back(2);
    cout << res << '\n';
    for(int i=1;i<=res && i<=10000;i++){
        for(int j=0;j<ans[i].length();j++) cout << int(ans[i][j]-48) << " ";
        cout << '\n';
    }
}
int32_t main(){
    FastIO
    readfile();
    xuli();
    return 0;
}
