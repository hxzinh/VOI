#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 2e5 + 10;
int n, m;
vector<int> a[NM];

void readfile(){
    freopen("DAG.INP", "r", stdin);
    freopen("DAG.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
    }
}
void xuli(){

}
int main()
{
    FastIO
    cout << "Hello world!" << endl;
    return 0;
}
