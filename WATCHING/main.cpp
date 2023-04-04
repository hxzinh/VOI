
#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e5+10;
ll n,m,t,k,sa=0,sb=0;
ll a[NM],b[NM];

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

void readfile()
{
    freopen("WATCHING.INP","r",stdin);
    freopen("WATCHING.OUT","w",stdout);
    Read(n); Read(m); Read(t); Read(k);
    for(int i=1;i<=n;i++){
        Read(a[i]);
    }
    for(int j=1;j<=m;j++){
        Read(b[j]);
    }
}
void xuli()
{
    ll posa=0,posb=0;
    bool ok=false,cx=true;
    a[0]=-k; b[0]=-k;
    while(cx){
        if(ok){
            ok=false;
            ll d=posa,c=n,g,tam=posa;
            while(d<=c){
                g=(d+c)/2;
                if(a[g]>b[posb]){
                    posa=g;
                    c=g-1;
                }
                else d=g+1;
            }
            if(tam==posa){
                sa+=t-max(b[posb],a[posa]+k);
                cx=false;
                break;
            }
            sa+=a[posa]-max(b[posb],a[posa-1]+k);
            ///cout << a[posa] << " " << sa << '\n';
        }
        else {
            ok=true;
            ll d=posb,c=m,g,tam=posb;
            while(d<=c){
                g=(d+c)/2;
                if(b[g]>a[posa]){
                    posb=g;
                    c=g-1;
                }
                else d=g+1;
            }
            if(tam==posb){
                sb+=t-max(a[posa],b[posb]+k);
                cx=false;
                break;
            }
            sb+=b[posb]-max(a[posa],b[posb-1]+k);
            ///cout << b[posb] << " " << sb << '\n';
        }
    }
    cout << sa << " " << sb;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
