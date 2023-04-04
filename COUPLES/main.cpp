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
int n, m, T;
ii b[NM], g[NM];
bool cx[NM];

void readfile(){
    freopen("COUPLES.INP", "r", stdin);
    freopen("COUPLES.OUT", "w", stdout);
    cin >> T;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> b[i].fi;
        b[i].se = i;
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> g[i].fi;
        g[i].se = i;
    }
}
bool cmp(const ii &A, const ii &B){
    return A.fi > B.fi;
}
bool tmp(const ii &A, const ii &B){
    return A.fi < B.fi;
}
void xuli(){
    sort(b + 1, b + n + 1, tmp);
    sort(g + 1, g + m + 1, cmp);
    memset(cx, true, sizeof(cx));

    int res = 0;
    vector<pair<int, int>> trace;
    for(int i = 1; i <= n; i++){
        int j = i + 1;
        int sta = (b[i].fi > 0);
        if(b[i].fi < 0 && g[i].fi < 0) continue;
        if(b[i].fi > 0 && g[i].fi > 0) continue;
        while(abs(b[i].fi) == abs(g[i].fi) && j <= m){
            if(b[i].fi < 0 && g[i].fi < 0) break;
            if(b[i].fi > 0 && g[i].fi > 0) break;
            swap(g[i], g[j]);
        }
        res++;
        trace.push_back({b[i].se, g[i].se});
    }
    cout << res << '\n';
    for(ii u : trace) cout << u.fi << " " << u.se << '\n';
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
