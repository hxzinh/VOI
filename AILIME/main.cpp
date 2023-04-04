#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e5 + 10;
const int NUMBLOCK = 450;
int n, q;
ll a[NM], c[NM];
int cnt[NM], ans[NM];
map<ll, int> mp;

struct Data {
    int l, r, w, type, id;
} query[NM];

void sub1() {
    for(int k = 1; k <= q; k++) {
        int type = query[k].type, u = query[k].l, v = query[k].r, w = query[k].w, id = query[k].id;

        if(type == 1) {
            for(int i = 1; i <= abs(v - u + 1); i++) {
                int cur = u + i - 1;
                if(cur > n) cur -= n;
                a[cur] += w;
            }
        } else {
            int res = 0;
            mp.clear();
            for(int i = 1; i <= abs(v - u + 1); i++) {
                int cur = (u + i - 1);
                if(cur > n) cur -= n;
                mp[a[i]]++;
                if(mp[a[i]] > abs(v - u + 1) / 2) {
                    res = a[i];
                    break;
                }
            }
            if(res) cout << res << '\n';
            else cout << "IMPOSSIBLE" << '\n';
        }
    }
}
bool cmp(const Data A, const Data B) {
    return (A.l / NUMBLOCK == B.l / NUMBLOCK) ? A.r < B.r : A.l < B.l;
}
void sub2() {
    vector<int> vec;
    for(int i = 1; i <= n; i++) vec.push_back(a[i]);
    sort(ALL(vec));
    vec.resize(unique(ALL(vec)) - vec.begin());
    for(int i = 1; i <= n; i++) {
        int newColor = lower_bound(ALL(vec), a[i]) - vec.begin() + 1;
        c[newColor] = a[i];
        a[i] = newColor;
    }

    sort(query + 1, query + q + 1, cmp);

    /**
    for(int k = 1; k <= q; k++) {
        int type = query[k].type, u = query[k].l, v = query[k].r, w = query[k].w, id = query[k].id;
        cout << type << " " << u << " " << v << " " << id << '\n';
    }
    **/

    int res = 0;
    for(int i = query[1].l; i <= query[1].r; i++) {
        cnt[a[i]]++;
        if(cnt[a[i]] > (query[1].r - query[1].l + 1) / 2) res = a[i];
    }
    ans[query[1].id] = res;

    for(int i = 2; i <= q; i++) {
        int preL = query[i - 1].l, preR = query[i - 1].r;
        int u = query[i].l, v = query[i].r;

        for(int j = preL; j < u; j++) {
            cnt[a[j]]--;
            if(cnt[res] <= (v - u + 1) / 2) res = 0;
        }
        for(int j = preR; j > v; j--) {
            cnt[a[j]]--;
            if(cnt[res] <= (v - u + 1) / 2) res = 0;
        }

        for(int j = u; j < preL; j++) {
            cnt[a[j]]++;
            if(cnt[a[j]] > (v - u + 1) / 2) res = a[j];
        }
        for(int j = v; j > preR; j--) {
            cnt[a[j]]++;
            if(cnt[a[j]] > (v - u + 1) / 2) res = a[j];
        }

        ans[query[i].id] = res;
    }

    for(int i = 1; i <= q; i++) {
        if(ans[i]) cout << c[ans[i]] << '\n';
        else cout << "IMPOSSIBLE" << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("AILIME.INP", "r", stdin);
    freopen("AILIME.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];

    bool ok = true;
    for(int i = 1; i <= q; i++) {
        int type, u, v, w = 0;
        cin >> type >> u >> v;
        if(type == 1) cin >> w;

        if(type == 1) ok = false;

        query[i] = {u, v, w, type, i};
    }

    if(ok) sub2();
    else sub1();
    return 0;
}

/* Author: hxzinh */

/*
-----code ko bug-----code ko bug-----code ko bug--------------

          _.-/`)
         // / / )
      .=// / / / )
     //`/ / / / /
    // /     ` /
   ||         /
    \\       /
     ))    .'
    //    /
         /
*/
