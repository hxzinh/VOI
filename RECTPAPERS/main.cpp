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

int q;
ii s[10];

void readfile(){
    freopen("RECTPAPERS.INP", "r", stdin);
    freopen("RECTPAPERS.OUT", "w", stdout);
    cin >> q;
}
ii check(ii a, ii b, ii c){
    if(a.fi < b.fi) swap(a, b);
    if(a.fi < c.fi) swap(a, c);
    if(b.fi < c.fi) swap(b, c);
    if(a.fi == b.fi && a.fi == c.fi) return make_pair(a.fi, a.se + b.se + c.se);
    if(a.fi == b.fi + c.fi && b.se == c.se) return make_pair(a.fi, a.se + b.se);
    return make_pair(-1, -1);
}
void xuli(){
    vector<ii> mimax;
    while(q--){
        int x, y, u, v, l, r;
        cin >> x >> y >> u >> v >> l >> r;
        int cnt = 0;
        mimax.clear();
        s[1] = check({x, y}, {u, v}, {l, r});
        s[2] = check({y, x}, {u, v}, {l, r});
        s[3] = check({x, y}, {v, u}, {l, r});
        s[4] = check({x, y}, {u, v}, {r, l});
        s[5] = check({y, x}, {v, u}, {l, r});
        s[6] = check({x, y}, {v, u}, {r, l});
        s[7] = check({y, x}, {u, v}, {r, l});
        s[8] = check({y, x}, {v, u}, {r, l});
        for(int i = 1; i <= 8; i++){
            int mi = min(s[i].fi, s[i].se);
            int ma = max(s[i].fi, s[i].se);
            if(mi == -1 || ma == -1) continue;
            bool ok = true;
            for(ii u : mimax){
                if(mi == u.fi || ma == u.se){
                    ok = false;
                    break;
                }
            }
            if(ok){
                cnt++;
                mimax.push_back({mi, ma});
            }
        }
        cout << cnt << '\n';
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
