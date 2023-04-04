#include <bits/stdc++.h>
#define ll long long
#define INF 1e8
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 5e4 + 10;
int T, n;
int a[NM], f[NM], s[NM];

void readfile(){
    freopen("DAYSO.INP", "r", stdin);
    freopen("DAYSO.OUT", "w", stdout);
    cin >> T;
}
bool check(){

}
void xuli(){
    while(T--){
        cin >> n;
        memset(s, 0, (n + 1) * sizeof(int));
        memset(f, 0, (n + 1) * sizeof(int));
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        ///----------------------------roi rac hoa-------------------------
        vector<int> val;
        for(int i = 1; i <= n; i++) val.push_back(a[i]);
        sort(ALL(val));
        val.resize(unique(ALL(val)) - val.begin());
        for(int i = 1; i <= n; i++)
            a[i] = lower_bound(ALL(val), a[i]) - val.begin() + 1;
        ///----------------------------------------------------------------

        int g = (1 + n) / 2;
        int u = -INF, v = -INF;
        for(int i = 1; i <= g; i++) f[a[i]] = 1;
        for(int i = g; i <= n; i++) s[a[i]] = 1;
        for(int i = 1; i <= g; i++){
            f[a[i] + 1] = max(f[a[i] + 1], f[a[i]] + 1);
            maximize(u, f[a[i]]);
        }
        for(int i = g; i <= n; i++){
            s[a[i] - 1] = max(s[a[i] - 1], s[a[i]] + 1);
            maximize(v, s[a[i]]);
        }
        int res = min(u, v);
        int ans = n - (res * 2 - 1);
        cout << (ans < n - 1 ? ans : -1) << '\n';
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
