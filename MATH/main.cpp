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

const int NM = 5;
int n, q, a, b, c;
ii k[NM];
bool check = false;

void backtrack(ll u, ll v, int x){
    if((u + v) % c == 0){
        check = true;
        return;
    }
    if(x > n) return;
    int t1 = 1, t2 = 1;
    for(int i = 0; i <= k[x].se; i++){
        if(i != 0) t1 = t1 * k[x].fi % c;
        int newU = 1LL * u * t1 % c;
        for(int j = 0; j <= k[x].se - i; j++){
            if(j != 0) t2 = t2 * k[x].fi % c;
            int newV = 1LL * v * t2 % c;
            backtrack(newU % c, newV % c, x + 1);
            if(check) return;
        }
        t2 = 1;
    }
}
void xuli(){
    check = false;
    backtrack(a % c, b % c, 1);
    if(check) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> q;
    while(q--){
        cin >> a >> b >> c >> n;
        for(int i = 1; i <= n; i++){
            cin >> k[i].fi >> k[i].se;
        }
        xuli();
    }
}
int32_t main()
{
    FastIO
    readfile();
    return 0;
}



