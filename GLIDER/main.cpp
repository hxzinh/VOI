#include <bits/stdc++.h>
#define ll long long
#define oo 1e18
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ii pair<int,int>

using namespace std;
const int NM=3e5+10;
ll n,h;
ii a[NM];
///------------------------------------------------------///
struct Data{
    ll plus,h;
};
Data pos[NM];

void readfile(){
    freopen("GLIDER.INP","r",stdin);
    freopen("GLIDER.OUT","w",stdout);
    cin >> n >> h;
    pos[1].h=0; pos[0].plus=0;
    for(int i=1;i<=n;i++){
        cin >> a[i].first >> a[i].second;
        ll u=a[i].first, v=a[i].second;
        pos[i].plus=v-u+pos[i-1].plus;
        if(i!=1) pos[i].h=u-a[i-1].second+pos[i-1].h;
    }
}
bool check(ll d,ll c){
    if(pos[c].h-pos[d].h<=h) return true;
    else return false;
}
void xuli(){
    ll res=-oo;
    for(int i=n;i>=1;i--){
        /**
        for(int j=1;j<=i;j++){
            if(pos[i].h-pos[j].h<=h){
                ll t=pos[i].plus-pos[j-1].plus+h;
                res=max(res,t);
                break;
            }
        }
        **/
       ll d=i,c=n,g;
       while(d<=c){
           g=(d+c)/2;
           if(check(i,g)){
                ll tam=pos[g].plus-pos[i-1].plus+h;
                res=max(res,tam);
                d=g+1;
           }
           else c=g-1;
       }
    }
    cout << res;
}
int main(){
    FastIO
    readfile();
    xuli();
    return 0;
}
