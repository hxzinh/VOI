#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 5e5 + 10;
int n;
int a[NM], index[NM];

void readfile(){
    freopen("DELETE.INP", "r", stdin);
    freopen("DELETE.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        index[i] = i;
    }
}
bool cmp(const int &x, const int &y){
    return a[x] < a[y];
}
void xuli(){
    set<int> s;
    sort(index + 1, index + n + 1, cmp);
    for(int i = 0; i <= n + 1; i++) s.insert(i);

    ll res = 0;
    int tmp = 0;
    /*
    for(int i = 1; i <= n; i++){
        int pos = p[i].se;
        res +=  (n - i - 1) *  (p[i].fi - p[i - 1].fi);
        auto it = s.find(pos);
        int pre = *(--it)++;
        int next = *(++it)--;
        res +=  (pre < 1 ||  next > n ? 0 : min(a[pre], a[next]) - p[i].fi);
        s.erase(it);
    } */
    int pre, next;
    for(int i = 1; i <= n - 2; i++){
        int pos = index[i];
        res += (n - i - 1) * (a[pos] - tmp);
        tmp = a[pos];
        auto it = s.find(pos);
        if(it == s.begin()) pre = 0;
        else {
            --it; pre = a[*it];
            ++it;
        }
        ++it;
        if(it == s.end()) next = 0;
        else {
            next = a[*it];
            --it;
        }
        ll ans = pre - tmp;
        if(ans > next - tmp) ans = next - tmp;
        res += max(ans, 0LL);
        s.erase(it);
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
