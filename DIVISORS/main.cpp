#include <bits/stdc++.h>
#define ll long long
#define oo 1e18
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e6+10;
ll n,t,ans=oo;
ll s[NM],k[NM];
bool cx[NM];
vector <int> a[NM];

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
    freopen("divisors.inp","r",stdin);
    freopen("divisors.out","w",stdout);
    Read(n); Read(t);
    for(int i=1;i<=t;i++){
        s[i]=oo; k[i]=oo;
    }
    memset(cx,true,sizeof(cx));
    for(int i=2;i<=sqrt(t);i++){
        if(cx[i]){
            for(int j=i*i;j<=t;j+=i) cx[j]=false;
        }
    }
    for(int i=2;i<NM/2;i++){
        for(int j=2*i;j<NM;j+=i){
            a[j].push_back(i);
        }
    }
}
ll dp(ll x){
    if(x>t || cx[x]) return oo;
    if(x==t) return 0;
    ll &res=s[x];
    if(s[x]!=oo) return s[x];
    for(int i=0;i<a[x].size();i++){
        ll u=a[x][i];
        res=min(res,1+dp(x+u));
    }
    return res;
}
void xuli(){
    if(cx[t] || cx[n]){
        cout << -1;
        return;
    }
    s[n]=0;
    for(int i=n;i<t;i++){
        if(s[i]<oo)
        for(int j=0;j<a[i].size();j++){
            ll u=a[i][j];
            if(u+i<2*i) s[u+i]=min(s[u+i],s[i]+1);
        }
    }
    ans=s[t];
    ///ans=min(ans,dp(n));
    if(ans==oo) cout << -1;
    else Write(ans);
}
int main(){
    FastIO
    readfile();
    xuli();
    return 0;
}
