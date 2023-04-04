#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n;
int f[NM];

struct Data {
    int inR, outR, h;
} a[NM];

bool cmp(const Data &A, const Data &B){
    return (A.outR == B.outR ? A.inR > B.inR : A.outR > B.outR);
}
void xuli(){
    sort(a + 1, a + n + 1, cmp);

    stack<pii> st;
    for(int i = 1; i <= n; i++){
        if(st.size()){
            while(st.top().fi >= a[i].outR){
                st.pop();
                if(!st.size()) break;
            }
            if(st.size()){
                int u = st.top().se;
                maximize(f[i], f[u] + a[i].h);
            }
        }
        maximize(f[i], a[i].h);
        //maximize(f[i], f[i - 1]);
        st.push({a[i].inR, i});
    }

    int res = -1;
    for(int i = 1; i <= n; i++) maximize(res, f[i]);
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("HANOIFAC.INP", "r", stdin);
    freopen("HANOIFAC.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].inR >> a[i].outR >> a[i].h;

    xuli();
    return 0;
}

/* Author: hxzinh */
