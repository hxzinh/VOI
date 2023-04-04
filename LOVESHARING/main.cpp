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
int Sub, n, q;

struct Data {
    int u, r, tea;
} a[NM];

vector<Data> id[NM];
vector<int> milkId;

bool cmp(const Data A, const Data B) {
    return A.u < B.u;
}
void sub1() {
    while(q--) {
        int res = 0;
        int milkL, milkR;
        cin >> milkL >> milkR;

        milkL = upper_bound(ALL(milkId), milkL) - milkId.begin();
        milkR = upper_bound(ALL(milkId), milkR) - milkId.begin();

        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) if(a[i].tea >= milkL && a[i].tea <= milkR && a[j].tea >= milkL && a[j].tea <= milkR) {
                if(abs(a[i].u - a[j].u) <= min(a[i].r, a[j].r))
                    res++;
            }
        }
        cout<< res << " ";
    }
}
void sub2(){
    vector<Data> curDay;
    while(q--){
        curDay.clear();
        int milkL, milkR;
        cin >> milkL >> milkR;

        milkL = upper_bound(ALL(milkId), milkL) - milkId.begin();
        milkR = upper_bound(ALL(milkId), milkR) - milkId.begin();

        for(int i = milkL; i <= milkR; i++)
            curDay.insert(curDay.end(), ALL(id[i]));
        sort(ALL(curDay), cmp);

        int m = curDay.size(), res = 0;
        for(int i = 0; i < m - 1; i++){
            Data u = curDay[i];
            for(int j = i + 1; j < m; j++) {
                Data v = curDay[j];
                if(abs(u.u - v.u) <= min(u.r, v.r)) res++;
                if(abs(u.u - v.u) > u.r) break;
            }
        }
        cout << res << '\n';
    }
}
void init() {
    milkId.clear();
}
int32_t main()
{
    FastIO
    freopen("LOVESHARING.INP", "r", stdin);
    freopen("LOVESHARING.OUT", "w", stdout);
    cin >> Sub;
    while(Sub--){
        init();
        cin >> n >> q;
        for(int i = 1; i <= n; i++){
            int u, r, tea;
            cin >> u >> r >> tea;
            a[i] = {u, r, tea};
            milkId.push_back(tea);
        }

        sort(ALL(milkId));
        milkId.resize(unique(ALL(milkId)) - milkId.begin());
        for(int i = 1; i <= n; i++) {
            a[i].tea = lower_bound(ALL(milkId), a[i].tea) - milkId.begin() + 1;
            id[a[i].tea].push_back(a[i]);
        }

        sub2();
    }
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
