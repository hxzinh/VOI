#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e3 + 10;
int n, T, d;
int a[NM], b[NM];
int f[NM][105];

int dp(int x, int time){
    if(x > n || time >= T) return 0;
    int &res = f[x][time];
    if(res != -1) return res;
    for(int i = 1; i <= d; i++) if(time + b[x] <= T)
        maximize(res, a[x] + dp(x + i, time + b[x]));
    return res;
}
void xuli(){
    memset(f, -1, sizeof(f));
    cout << dp(1, 0) << '\n';

    memset(f, -1, sizeof(f));
    for(int i = 1; i <= n; i++) f[i][0] = 0;

    pii ans;
    for(int i = 1; i <= n; i++){
        for(int time = 0; time <= T; time++) if(f[i][time] > -1) {
            for(int j = 1; j <= d; j++){
                if(maximize(f[i + j][time + b[i]], f[i][time] + a[i]))
                    ans = {f[i + j][time + b[i]], time + b[i]};
            }
        }
    }

    int res = -INF;
    for(int i = 1; i <= n; i++)
        for(int time = 0; time <= T; time++) if(f[i][time] < INF)
             if(maximize(res, f[i][time])) ans = {i, time};
    cout << res << '\n';

    stack<int> st;
    for(int i = n; i > 0; i--){
        if(f[i][ans.se] == res){
            st.push(i);
            ans.se -= b[i];
            res -= a[i];
        }
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}
void readfile(){
    freopen("WAREHOUSE.INP", "r", stdin);
    freopen("WAREHOUSE.OUT", "w", stdout);
    cin >> n >> T >> d;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
