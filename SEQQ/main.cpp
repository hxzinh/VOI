#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define ALL(x) (x).begin(), (x).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e5 + 10;
int n;
int a[NM], s[NM], t[NM];

void readfile(){
    freopen("SEQ.INP", "r", stdin);
    freopen("SEQ.OUT", "w", stdout);
    cin >> n;
    s[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
}
void xuli(){
    vector<int> pos[NM];
    vector<int> val;
    for(int i = 1; i <= n; i++) val.push_back(a[i]);
    sort(ALL(val));
    val.resize(unique(ALL(val)) - val.begin());
    for(int i = 1; i <= n; i++) t[i] = lower_bound(ALL(val), a[i]) - val.begin() + 1;
    for(int i = 1; i <= n; i++) cout << t[i] << " ";

    for(int i = 1; i <= n; i++) pos[t[i]].push_back(i);
    int ans = -INF;
    for(int i = 1; i <= n; i++){
        pos[t[i]].erase(pos[i], 1);
        for(int u : pos[t[i]]) ans = max(ans, s[u] - s[t[i]]);
    }
    cout << ans;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
