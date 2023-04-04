#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define endl "\n"
#define ll long long
#define ft first
#define sc second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
#define REPD(i,n) for (int i = 👎 - 1; i >= 0; i--)
#define BIT(mask,i) (((mask) >> (i)) & 1LL)
#define MASK(i) (1LL << (i))
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};
template<class X,class Y>
    bool minimize(X &x,const Y &y) {
        if (x>y)
        {
            x=y;
            return 1;
        }
        return 0;
    }
template<class X,class Y>
    bool maximize(X &x,const Y &y) {
        if (x<=y) {
            x=y;
        return 1;
        }
        return 0;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
int n,c[100005],d[100005];
ll t[100005];
struct kaka{
        int ft,sc,th;
};
bool cmp(const kaka &g, const kaka &h)
{
    return g.sc > h.sc;
}
bool cmd(const kaka &g, const kaka &h)
{
    return g.ft < h.ft;
}
vector<kaka> a,b;
int main()
{
    FastIO;
    //freopen("CLIMBE.inp","r",stdin);
    //freopen("CLIMBE.out","w",stdout);
    cin >> n;
    FOR(i,1,n) cin >> c[i];
    FOR(i,1,n) cin >> d[i];
    FOR(i,1,n)
    {
        int x = c[i], y = d[i];
        if (x < y)
            a.pb({x,y,i});
        else b.pb({x,y,i});
    }
    sort(all(a),cmd);
    sort(all(b),cmp);
    ll sum = 0;
    int d = 0;
    REP(i,a.size())
    {
        sum += a[i].ft;
        t[d] = (d > 0) ? max(t[d-1],sum) : sum;
        t[d++] += a[i].sc;
    }
    REP(i,b.size())
    {
        sum += b[i].ft;
        t[d] = (d > 0) ? max(t[d-1],sum) : sum;
        t[d++] += b[i].sc;
    }
    cout << t[n-1] << endl;
    for (kaka x : a)
        cout << x.th << " ";
    for (kaka x : b)
        cout << x.th << " ";
    return 0;
}
