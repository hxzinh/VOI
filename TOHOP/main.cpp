#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 55;
int n, k, tam, dem;
long long cnt = 0;
int g[NM], ans[NM];
int m;
vector<int> res[NM], f[NM][NM];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n >> k >> m;
    tam = k;
    dem = m;
}
void backtrack(vector<int> &ans, int x){
    if(cnt >= dem + 1) return;
    if(ans.size() == tam){
        cnt++;
        if(cnt == dem + 1)
            for(int u : ans) cout << u << " ";
        return;
    }
    for(int i = x + 1; i <= n; i++){
        ans.push_back(i);
        backtrack(ans, i);
        ans.pop_back();
    }
}
double chap(int x, int t){
    double s = 1;
    for(int i = 1; i <= x; i++) s *= i;
    for(int i = 1; i <= t; i++) s /= i;
    for(int i = 1; i <= x - t; i++) s /= i;
    return s;
}
void xuli(){
    m++;
    int num = 0, cntt = 0;

    for(int i = 1; i <= n; i++){
        double cur = chap(n - i, k - 1);
        if(k == 1 || n - i + 1 < k) continue;
        if(m <= cur){
            if(cur == 0) num = i - 1;
            else num = i;
            cout << i << " ";
            k--;
            num = i;
        } else m -= cur;
    }
    cout << num + m;

    /**
    for(int i = 1; i <= k; i++){
        for(int j = num + 1; j <= n; j++){
            double cur = chap(n - j, k - i);
            if(m <= cur){
                ans[++cntt] = j;
                num = j;
                if(cntt == k){
                    for(int v = 1; v <= k; v++) cout << ans[v] << " ";
                    return;
                }
                break;
            } else m -= cur;
        }
    }
    **/

}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
