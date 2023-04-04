#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int MAX = 2e3 + 10;
int n, k;
int a[MAX], s[MAX][MAX];
bool cx[MAX];
vector<int> p;

struct Data {
    int sum, u, v;

    bool inline operator < (const Data &A) const {
        return (sum == A.sum ? (u == A.u ? v > A.v : u < A.u) : sum > A.sum);
    }
};
vector<Data> val;

void xuli(){
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            if(i != j) val.push_back({a[i] + a[j], i, j});

    sort(ALL(val));
    p.push_back(0);
    for(int i = 1; i < val.size(); i++) if(val[i].sum != val[i - 1].sum) p.push_back(i);
    //for(auto x : val) cout << x.sum << " " << x.u << " " << x.v << '\n';

    int res = 0, i = 0;
    for(int pos = 0; pos < p.size(); pos++){
        int i = p[pos];
        memset(cx, true, (n + 1) * sizeof(bool));
        int sum = val[i].sum, cnt = 0;
        for(int j = i; j < val.size(); j++){
            if(sum - val[j].sum > k) break;
            if(cx[val[j].u] && cx[val[j].v]){
                cnt++;
                cx[val[j].u] = false;
                cx[val[j].v] = false;
            } else continue;
        }
        maximize(res, cnt);
    }
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("PAIR.INP", "r", stdin);
    freopen("PAIR.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    xuli();
    return 0;
}
