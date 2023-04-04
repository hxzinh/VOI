#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define pb push_back
#define ALl(x) (x).begin(), (x).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n;
int a[NM], b[NM];
vector<int> s, t;

bool check(int x){
    s.clear(); t.clear();
    for(int i = 1; i <= x; i++){
        s.pb(a[i]);
        t.pb(b[i]);
    }

    sort(ALl(s)); sort(ALl(t));
    for(int i = 0; i < x; i++){
        int u = s[i], v = t[i];
        if(s[i] < t[i]) return false;
    }
    return true;
}
void xuli(){
    int l = 1, r = n, res = 0;
    while(l <= r){
        int m = (l + r) >> 1;
        if(check(m)){
            res = m;
            l = m + 1;
        } else r = m - 1;
    }
    cout << res;
}
int main() {
    FastIO
    freopen("CHUNGDAY.INP", "r", stdin);
    freopen("CHUNGDAY.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    xuli();
    return 0;
}
