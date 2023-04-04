#include <bits/stdc++.h>
#define ll long long
#define oo 1e18
#define MODUL 197
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e6+10;
ll n,k,maxx;
ll s[NM];
struct Data
{
    ll s,day,cost;
    bool operator < (const Data &A){
        return day < A.day;
    }
};
Data a[NM];

///-------------------------------------------------------------------///
template<class T> T Abs(const T &x) { return (x < 0 ? -x : x); }
template<class X, class Y>
bool minimize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x > y + eps) {
        x = y;
        return true;
    } else return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x + eps < y) {
        x = y;
        return true;
    } else return false;
}

template <typename T>
inline void Read(T& x) {
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}
template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}
///----------------------------------------------------------///
void readfile(){
    freopen("FACILITY.INP","r",stdin);
    freopen("FACILITY.OUT","w",stdout);
    Read(n); Read(k);
    for(int i=1;i<=n;i++){
        Read(a[i].s); Read(a[i].day); Read(a[i].cost);
        a[i].day+=a[i].s+k-1;
    }

}
bool cmp(const Data A,const Data B){
    return A.day < B.day;
}
ll searchx(ll d,ll c,ll i){
    ll res=0;
    while(d<=c){
        ll g=(d+c)/2;
        if(a[g].day<a[i].s){
            d=g+1;
            res=max(res,s[g]);
        }
        else c=g-1;
    }
    return res;
}
void xuli(){
    ll res=-oo;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=a[i].cost;
    for(int i=1;i<=n;i++){
        ll u=a[i].day;
        ll lmax=searchx(0,i,i);
        s[i]=max(s[i-1],lmax+a[i].cost);
        res=max(res,s[i]);
    }
    cout << res;
}
int main(){
    FastIO
    readfile();
    xuli();
    return 0;
}
