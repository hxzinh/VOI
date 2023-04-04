#include <bits/stdc++.h>
#define ll long long
#define oo 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=3e5+10;
ll n,m;
ll a[NM],b[NM];
ll sumA[NM],sumB[NM];

void readfile(){
    freopen("copy.inp","r",stdin);
    freopen("copy.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=m;i++){
        cin >> b[i];
    }
}
long long product(ll a,ll b){
    if(a == 0 || b == 0) return 0;
    return oo / a < b ? oo : a*b;
}
void xuli(){
    ll res=oo;
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    for(int i=1;i<=n;i++) sumA[i] = sumA[i-1] + a[i];
    for(int i=1;i<=m;i++) sumB[i] = sumB[i-1] + b[i];
    for(int i=1;i<=n;i++){
        res=min(res,product(sumB[m],i)+sumA[n-i]);
    }
    for(int i=1;i<=m;i++){
        res=min(res, product(sumA[n],i)+sumB[m-i]);
    }
    cout << res;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
