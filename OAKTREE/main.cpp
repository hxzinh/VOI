#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define ii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 3e5 + 10;
int n, m;
ii a[NM], b[NM];

void readfile(){
    freopen("OAKTREE.INP", "r", stdin);
    freopen("OAKTREE.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
        b[i] = a[i];
    }
    cin >> m;
}
bool cmp(const ii &A, const ii &B){
    return A.se < B.se;
}
int checkH(int x, int h, int k){
    int l = 1, r = n, last = 0, head = -1;
    while(l <= r){
        int m = (l + r) >> 1;
        if(a[m].fi == x){
            if(a[m].se <= k){
                l = m + 1;
                head = m;
            } else r = m - 1;
        } else
        if(a[m].fi < x) r = m - 1;
        else l = m + 1;
    }

    l = 1, r = n;
    while(l <= r){
        int m = (l + r) >> 1;
        if(a[m].fi == x){
            if(a[m].se <= k){
                last = m;
                l = m + 1;
            } else r = m - 1;
        } else
        if(a[m].fi < x) l = m + 1;
        else r = m - 1;
    }
    return head - last + 1;
}
void xuli(){
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) cout << a[i].fi << " " << a[i].se << '\n';
    for(int i = 1; i <= m; i++){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        cout << checkH(x, y, v) << '\n';
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
