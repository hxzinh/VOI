#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 16;
int T, n;
string s, ex;
int a[NM];

map<string, int> bfs(string start){
    map<string, int> res;
    queue<string> q;
    res[start] = 0;
    q.push(start);

    while(!q.empty()){
        string u = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k <= n; k++){
                    string v = u.substr(0, i) + u.substr(j, k - j) + u.substr(i, j - i) + u.substr(k);
                    if(!res.count(v)){
                        res[v] = res[u] + 1;
                        if(res[v] < 2) q.push(v);
                    }
                }
            }
        }
    }
    return res;
}
int main()
{
    FastIO
    freopen("KITTENS.INP", "r", stdin);
    freopen("KITTENS.OUT", "w", stdout);
    cin >> T;
    while(T--){
        cin >> n;
        s = "";
        for(int i = 0; i < n; i++){
            int u; cin >> u;
            s.push_back(u + '0');
        }

        ex = "";
        for(int i = 1; i <= n; i++){
            ex.push_back(i + '0');
        }

        map<string, int> ans, res;
        res = bfs(s);
        ans = bfs(ex);

        int num = 5;
        for(auto u : res) if(ans.count(u.fi))
            minimize(num, u.se + ans[u.fi]);
        if(num < 5) cout << num << '\n';
        else cout << "5 or more" << '\n';
    }
    return 0;
}
