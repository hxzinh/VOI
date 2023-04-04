    #include <bits/stdc++.h>
    #define ll long long
    #define oo 1e18
    #define FatsIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    using namespace std;
    const int NM=1e5+10;
    ll n,k,maxx=-oo;
    ll a[NM];

    void readfile(){
        freopen("WIRES.INP","r",stdin);
        freopen("WIRES.OUT","w",stdout);
        cin >> n >> k;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            maxx=max(a[i],maxx);
        }
    }
    bool check(ll x){
        ll dem=0;
        for(int i=1;i<=n;i++){
            dem+=a[i]/x;
        }
        if(dem>=k) return true;
        else return false;
    }
    void xuli(){
        ll d=1,c=maxx,g,res=-oo;
        while(d<=c){
            g=((d+c)%2==0 ? (d+c)/2 : (d+c)/2+1);
            if(check(g)){
                res=g;
                d=g+1;
            }
            else c=g-1;
        }
        if(res!=-oo) cout << 0;
        else cout << res;
    }
    int main(){
        FatsIO
        readfile();
        xuli();
        return 0;
    }
