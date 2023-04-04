#include <bits/stdc++.h>
#define ll long long
#define oo 1e18
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
ll k;

void readfile(){
    freopen("SQUARE.INP","r",stdin);
    freopen("SQUARE.OUT","w",stdout);
    cin >> k;
}
void xuli(){
    if(k==0){
        cout << k;
        return;
    }
    ll absK=abs(k), res=oo;
    for(int i=1;i<=sqrt(absK);i++){
        if(absK%i!=0) continue;
        ll b=k/i;
        if((i+b)%2==0) res=min(res,abs((i+b)/2));
    }
    if(res==oo) cout << "none";
    else cout << res;
}
int main(){
    FastIO
    readfile();
    xuli();
    return 0;
}
