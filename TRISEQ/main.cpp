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

const int NM = 4e6 + 10;
int n, t;
int cnt = 0;
int pos[NM];
vector<int> res[NM], c;

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n >> t;
    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        c.push_back(u);
    }
}
bool check(vector<int> ans){
    for(int i = 0; i < ans.size(); i++)
        for(int j = i + 1; j < ans.size(); j++)
            for(int z = j + 1; z < ans.size(); z++)
                if(ans[i] + ans[j] > ans[z] && ans[i] + ans[z] > ans[j] && ans[j] + ans[z] > ans[i]) continue;
                else return false;
    return true;
}
void backtrack(vector<int> &ans,int x){
    if(x > n){
        if(check(ans)){
            cnt++;
            res[cnt] = ans;
        }
        return;
    }
    for(int i = 1; i <= n; i++){
        ans.push_back(i);
        backtrack(ans, x + 1);
        ans.pop_back();
    }
}
bool isTrue(int x){
    for(int i = 0; i < n; i++){
        if(c[i] == res[x][i]) continue;
        if(res[x][i] > c[i]) return false;
        else return true;
    }
}
void xuli(){
    vector<int> ans;
    backtrack(ans, 1);

    cout << cnt << '\n';
    for(int u : res[t]) cout << u << ' ';
    cout << '\n';
    int l = 1, r = cnt, pos;
    for(int i = 1; i <= cnt; i++){
        if(res[i] == c){
            cout << i;
            return;
        }
    }
}
int32_t  main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
