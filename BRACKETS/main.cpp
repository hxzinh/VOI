#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 5050;
const int MOD = 998244353;
int n, cost;
int a[NM];
int f[2][2005][105], trace[201][2001][101];
char s[NM];

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void readfile(){
    freopen("BRACKETS.INP", "r", stdin);
    freopen("BRACKETS.OUT", "w", stdout);
    cin >> n >> cost;
    for(int i = 1; i <= n; i++) cin >> s[i];
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void xuli(){
    f[0][0][0] = 1;

    for(int i = 0; i < n; i++){
        int u = i % 2;
        int v = (i + 1) % 2;
        for(int j = 0; j <= cost; j++){
            for(int k = 0; k <= n / 2; k++) if(f[u][j][k]) {
                if(s[i + 1] == '('){
                    if(k > 0 && j + a[i + 1] <= cost){
                        trace[i + 1][j + a[i + 1]][k - 1] = 0;
                        add(f[v][j + a[i + 1]][k - 1], f[u][j][k]);
                    }
                    trace[i + 1][j][k + 1] = 1;
                    add(f[v][j][k + 1], f[u][j][k]);
                } else {
                    if(k > 0){
                        add(f[v][j][k - 1], f[u][j][k]);
                        trace[i + 1][j][k - 1] = 2;
                    }
                    if(j + a[i + 1] <= cost){
                        add(f[v][j + a[i + 1]][k + 1], f[u][j][k]);
                        trace[i + 1][j + a[i + 1]][k + 1] = 3;
                    }
                }
            }
        }
        for(int j = 0; j <= cost; j++)
            for(int k = 0; k <= n / 2; k++) f[u][j][k] = 0;
    }

    stack<char> st;
    int i = n, j, k = 0;
    for(j = 0; j <= cost; j++) if(f[i % 2][j][k]) break;
    while(i > 0){
        int tmp = trace[i][j][k];
        if(tmp == 0){
            st.push(')');
            j -= a[i];
            k++;
        }
        if(tmp == 1){
            st.push('(');
            k--;
        }
        if(tmp == 2){
            st.push(')');
            k++;
        }
        if(tmp == 3){
            st.push('(');
            j -= a[i];
            k--;
        }
        i--;
    }

    int res = 0;
    for(int i = 0; i <= cost; i++) add(res, f[n % 2][i][0]);
    cout << res << '\n';
    while(st.size()){
        cout << st.top();
        st.pop();
    }
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
