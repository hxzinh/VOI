#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define ii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int n, u, v;
int ans = 1, res = 0;
ii p[NM], s[NM];
bool cx[NM], ok[NM][105];

void readfile(){
    freopen("UOCTHT.INP", "r", stdin);
    freopen("UOCTHT.0UT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i].fi >> p[i].se;
    p[0].fi = 1, p[0].se = 1;
}
void backtrack(int x, int val){
    if(x > n || val > v) return;
    int tmp = 1;
    for(int i = 1; i <= p[x].se; i++){
        tmp *= p[x].fi;
        int newVal = val * tmp;
        if(newVal <= v){
            if(newVal >= u) res++;
            backtrack(x + 1, newVal);
        } else break;
    }
    backtrack(x + 1, val);
}
void sub12(){
    for(int i = 1; i <= 3; i++){
        cin >> u >> v;

        res = 0;
        backtrack(1, 1);
        cout << res << '\n';
    }
}
int32_t main()
{
    FastIO
    readfile();
    sub12();
    return 0;
}
