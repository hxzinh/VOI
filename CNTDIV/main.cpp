#include <bits/stdc++.h>
#define ll long long
#define oo 1e18
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e6+10;
ll q;
int minPrime[NM];
int dem[NM];
bool cx[NM];

void prime(){
    minPrime[1]=1;
    for(int i=2;i<=sqrt(1e6+3);i++){
        if(minPrime[i]==0){
            for(int j=i*i;j<=NM;j+=i){
                minPrime[j]=i;
            }
        }
    }
    for(int i=2;i<=NM;i++)
        if(minPrime[i]==0) minPrime[i]=i;
}
vector <int> phantich(int n){
    vector <int> res;
    while(n!=1){
        res.push_back(minPrime[n]);
        n=n/minPrime[n];
    }
    return res;
}
void xuli(){
    cin >> q;
    for(int lan=1;lan<=q;lan++){
        ll n,res=1,cnt=1,cntt=1; cin >> n;
        vector <int> a,k;
        for(int i=0;i<=2;i++){
            vector <int> t=phantich(n+i);
            for(int j=0;j<t.size();j++){
                a.push_back(t[j]);
                if(!cx[t[j]]){
                    k.push_back(t[j]);
                    cx[t[j]]=true;
                }
            }
        }
        for(int i=0;i<a.size();i++) dem[a[i]]++;
        for(int i=0;i<k.size();i++){
            cnt=cnt*(dem[k[i]]+1);
            cntt=cntt*(dem[k[i]]*2+1);
            dem[k[i]]=0;
            cx[k[i]]=false;
        }
        res=cntt/2-cnt+1;
        cout << res;
        cout << '\n';
    }
}
int32_t main(){
    FastIO
    freopen("CNTDIV.INP","r",stdin);
    freopen("CNTDIV.OUT","w",stdout);
    prime();
    xuli();
    return 0;
}
