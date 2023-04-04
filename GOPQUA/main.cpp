#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define ii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e5 + 10;
int n, q, Mod;
int a[NM];
bool ok;
///---------------------------------------sub12--------------------------------
int cnt[15][NM], c[15];
///---------------------------------------sub3-------------------------
int b[NM], val[1000005], dem[2005][2005];
///---------------------------------------full----------------------------------
int g[1000005], ans[NM];
struct Data {
    int l, r, pos;
};
Data k[NM];

void readfle(){
    freopen("GOPQUA.INP", "r", stdin);
    freopen("GOPQUA.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void sub12(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 10; j++) cnt[j][i] = cnt[j][i - 1];
        cnt[a[i]][i]++;
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        int res = 0;
        for(int i = 1; i <= 10; i++){
            int tmp1 = cnt[i][r] - cnt[i][l - 1];
            res += i * tmp1 * tmp1;
        }
        cout << res << '\n';
    }
}
void sub3(){
    vector<int> t;
    for(int i = 1; i <= n; i++) t.push_back(a[i]);
    sort(ALL(t));
    t.resize(unique(ALL(t)) - t.begin());
    for(int i = 1; i <= n; i++) b[i] = lower_bound(ALL(t), a[i]) - t.begin() + 1;
    for(int i = 1; i <= n; i++) val[b[i]] = a[i];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) dem[j][i] = dem[j][i - 1];
        dem[b[i]][i]++;
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        int res = 0;
        for(int i = 1; i <= n; i++){
            int tmp1 = dem[i][r] - dem[i][l - 1];
            res += val[i] * tmp1 * tmp1;
        }
        cout << res << '\n';
    }
}
bool cmp(Data A, Data B){
    return A.l / Mod < B.l / Mod || (A.l / Mod == B.l / Mod && A.r < B.r);
}
void full(){
    for(int i = 1; i <= q; i++){
        cin >> k[i].l >> k[i].r;
        k[i].pos = i;
    }
    Mod = sqrt(n);
    sort(k + 1, k + q + 1, cmp);
    int res = 0;
    int l = 0, r = 0;
    for(int i = 1; i <= q; i++){
        for(int j = l; j < k[i].l; j++) res -= 1LL * (2 * g[a[j]] - 1) * a[j], g[a[j]]--;
        for(int j = r + 1; j <= k[i].r; j++) res += 1LL * (2 * g[a[j]] + 1) * a[j], g[a[j]]++;
        for(int j = k[i].r + 1; j <= r; j++) res -= 1LL * (2 * g[a[j]] - 1) * a[j], g[a[j]]--;
        for(int j = k[i].l; j < l; j++) res += 1LL * (2 * g[a[j]] + 1) * a[j], g[a[j]]++;
        l = k[i].l;
        r = k[i].r;
        ans[k[i].pos] = res;
    }
    for(int i = 1; i <= q; i++) cout << ans[i] << '\n';
}
int32_t main()
{
    FastIO
    readfle();
    /**
    for(int i = 1; i <= n; i++) if(a[i] > 10) {
        ok = true;
        break;
    }
    if(ok) sub3();
    else sub12();
        **/
    full();
    return 0;
}
