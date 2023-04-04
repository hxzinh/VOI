#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e6 + 10;
int n;

struct Pages{
    int cnt, index;

    bool inline operator < (const Pages &a) const {
        return index > a.index;
    }
};
Pages a[NM], s[NM];
priority_queue<Pages> odd, even;


void readfile(){
    freopen("THESIS.INP", "r", stdin);
    freopen("THESIS.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        char u; cin >> u;
        if(u == 'T') a[i].cnt = 0;
        else a[i].cnt = 1;
        a[i].index = i;
        if(a[i].cnt % 2 != 0) odd.push({a[i].cnt, a[i].index});
        else even.push({a[i].cnt, a[i].index});
    }
}
void xuli(){
    int i = 0;
    while(!even.empty() || !odd.empty()){
        int u, pos;
        if(++i % 2 == 0){
            u = odd.top().cnt;
            pos = odd.top().index;
            odd.pop();
        } else {
            u = even.top().cnt;
            pos = even.top().index;
            even.pop();
        }
        s[i].cnt = u; s[i].index = pos;
    }

    ll res = 0;
    for(int i = 1; i <= n; i++) res += abs(s[i].index - a[i].index);
    res /= 2;
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
