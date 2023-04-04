#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e3 + 10;
int n;
int res = -1, ans = 0;
int a[NM];
string k;
vector<int> d;
bool cx[NM];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n;
    cin >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    memset(cx, true, sizeof(cx));
    for(int i = 0; i < k.length(); i++) d.push_back(k[i] - '0');
}
bool check(){
    for(int i = 0; i < d.size(); i++) if(cx[i]) return false;
    return true;
}
void backtrack(){
    if(check()){
        maximize(res, ans);
        return;
    }
    for(int i = 0; i < d.size(); i++) if(cx[i]) {
        int cnt = 0;
        for(int j = i; j < d.size(); j++) if(cx[j]) {
            if(d[i] != d[j]) break;
            cx[j] = false;
            ans += a[++cnt];
            for(int u : d) if(cx[u]) cout << u;
            cout << '\n';
            backtrack();
            ans -= a[cnt];
        }
        for(int j = i; j <= i + cnt; j++){
            if(d[i] != d[j]) break;
            cnt--;
            cx[j] = true;
        }
    }
}
void sub1(){
    backtrack();
    cout << res;
}
int main()
{
    FastIO
    readfile();
    sub1();
    return 0;
}
