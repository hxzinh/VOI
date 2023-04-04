#include <bits/stdc++.h>
#define ll int
#define oo 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=2e6+10;
int sub,n;
int color[NM], cnt = 1;
vector <int> fa[NM],c[NM],ans;
bool cx[NM];

struct Data
{
    ll sizec,num;
};
Data s[NM];

void readfile(){
    freopen("colorful.inp","r",stdin);
    freopen("colorful.out","w",stdout);
    cin >> sub;
    cin >> n;
    for(int i=1;i<n;i++){
        ll u,v; cin >> u >> v;
        fa[u].push_back(v); fa[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
            cin >> color[i];
            if(color[i] == color[i-1]) cnt++;
    }
}
bool check(ll x){
    for(int i=1;i<=n;i++){
        if(i==x) continue;
        for(auto u : fa[i]){
            if(u!=x)
            if(color[i]!=color[u]) return false;
        }
    }
    return true;
}
void xuli(){
    if(cnt == n){
        cout << "YES" << '\n';
        for(int i = 1; i <= n; i++) cout << i << " ";
        return;
    }
    bool cx_i, cx_u;
    ll dem=0;
    for(int i=1;i<=n;i++){
        if(!cx[i])
        for(auto u : fa[i]){
            if(cx[u]) continue;
            if(color[i]!=color[u] && dem==2) {cout << "NO"; return;}
            else if(color[i]!=color[u]){
                cx_i=check(i); cx_u=check(u);
                if(!cx[i]) dem++;
                if(!cx[i]) if(cx_i) {ans.push_back(i); cx[i] = true;}
                if(cx_u) {ans.push_back(u); cx[u] = true;}
                if(!cx_i && !cx_u) {cout << "NO"; return;}
            }
        }
    }
    sort(ans.begin(),ans.end());
    cout << "YES" << '\n';
    for(int u : ans) cout << u << " ";

}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
