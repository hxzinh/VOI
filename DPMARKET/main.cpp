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

const int NM = 1e6 + 10;
int n, m;
int a[NM], f[NM];
ii c[NM];
bool cx[NM];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cx[a[i]] = true;
    }
    for(int i = 1; i <= m; i++){
        cin >> c[i].fi;
        c[i].se = i;
    }
}
void xuli(){
    sort(a + 1, a + n + 1);
    for(int i = m - 1; i > 0; i--){
        if(minimize(c[i].fi, c[i + 1].fi)) c[i].se = c[i + 1].se;
    }

    for(int i = 1; i <= m; i++) f[i] = c[i].fi;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if(minimize(f[a[i]], f[a[j - 1]] + c[a[i] - a[j] + 1].fi)){
                int tmp = a[j] + c[a[i] - a[j] + 1].se - 1;
                int k = i + 1;
                while(a[k] <= tmp && k <= n) {minimize(f[a[k]], f[a[i]]); k++;};
            }
        }
    }
    cout << f[a[n]];
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
