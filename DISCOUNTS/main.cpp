#include <bits/stdc++.h>
#define ll int
#define f(x) float(x)
#define oo 1e9+100
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=3e5+10;
ll n,k,T;
bool ok[NM];
struct Data{
    ll cost,pos;
};
vector <Data> ts,tx,buy[NM];

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
    freopen("discounts.inp","r",stdin);
    freopen("discounts.out","w",stdout);
    Read(T);
    Read(n); Read(k);
    for(int i=1;i<=n;i++){
        ll u,v;
        Read(u); Read(v);
        if(v==1) tx.push_back({u,i});
        else ts.push_back({u,i});
    }
    memset(ok,false,sizeof(ok));
}
bool cmp(const Data &A,const Data &B){
    return A.cost < B.cost;
}
priority_queue <int> pq[NM];
void xuli(){
    sort(ts.begin(),ts.end(),cmp);
    sort(tx.begin(),tx.end(),cmp);
    double res=0;
    ll dem=0;
    if(n<k){
        for(int i=0;i<tx.size();i++){
            buy[++dem].push_back({tx[i].cost,tx[i].pos});
            res+=f(tx[i].cost)/f(2);
        }
        for(int i=0;i<ts.size();i++){
            buy[++dem].push_back({ts[i].cost,tx[i].pos});
            res+=ts[i].cost;
        }
    }
    else
    {
        ll minn=oo; bool cx=false;
        for(int i=tx.size()-1;i>=0;i--){
            if(dem==k-1){
                dem++;
                ok[dem]=true;
                for(int j=i;j>=0;j--){
                    cx=true;
                    ll u=tx[j].cost;
                    buy[dem].push_back({tx[j].cost,tx[j].pos});
                }
                break;
            }
            buy[++dem].push_back({tx[i].cost,tx[i].pos});
            ok[dem]=true;
            ///res+=f(tx[i].cost)/f(2);
        }
        for(int i=ts.size()-1;i>=0;i--){
            ll u=ts[i].cost;
            if(!cx){
                buy[++dem].push_back({u,ts[i].pos});
                if(dem==k) cx=true;
            }
            else buy[dem].push_back({u,ts[i].pos});
        }
        sort(buy[dem].begin(),buy[dem].end(),cmp);
        for(int i=1;i<=k;i++){
            if(ok[i]) res+=f(buy[i][0].cost)/f(2);
            else res+=buy[i][0].cost;
            for(int u=1;u<buy[i].size();u++){
                res+=buy[i][u].cost;
            }
        }
    }
    cout << fixed << setprecision(1) << res << '\n';
    for(int i=1;i<=k;i++){
        cout << buy[i].size() << " ";
        for(int u=0;u<buy[i].size();u++) cout << buy[i][u].pos << " ";
        cout << '\n';
    }
}
int main(){
    FastIO
    readfile();
    xuli();
    return 0;
}
