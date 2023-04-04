#include <bits/stdc++.h>
#define ll int
#define oo 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=110;
int s[NM],n;
vector <int> fa[NM];

void readfile(){
    freopen("cc.inp","r",stdin);
    freopen("cc.out","w",stdout);
    cin >> n;
    for(int i=1;i<n;i++){
        ll u,v;
        cin >> u >> v;
        fa[u].push_back(v); fa[v].push_back(u);
    }
    for(int i=1;i<=n;i++) s[i]=fa[i].size();
    sort(s+1,s+n+1);
    cout << s[n];
}
int main()
{
    FastIO
    readfile();
    return 0;
}
