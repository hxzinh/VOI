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

const int NM = 4e3 + 10;
int n;
ii p[NM], dot[NM * NM / 2];

struct Data {
    ii a, b;
    double val;
};

void readfile(){
    freopen("EUCLID.INP", "r", stdin);
    freopen("EUCLID.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> p[i].fi >> p[i].se;
}
long long getDist(int x, int y){
    return (p[x].fi - p[y].fi) * (p[x].fi - p[y].fi) + (p[x].se - p[y].se) * (p[x].se - p[y].se);
}
bool cmp(const ii A, const ii B){
    return getDist(A.fi, A.se) > getDist(B.fi, B.se);
}
void xuli(){
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++) dot[++cnt] = {i, j};

    sort(dot + 1, dot + cnt + 1, cmp);

    for(int i = 1; i <= n; i++){
        ll ans = -1;
        for(int j = 1; j <= cnt; j++){
            long long x = dot[j].fi, y = dot[j].se;
            if(x == i || y == i) continue;
            ll dist = getDist(x, y);
            if(ans < 0) ans = dist;
            else if(ans > dist) {
                cout << fixed << setprecision(11) << sqrt(double(dist)) << '\n';
                break;
            }
        }
    }
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
