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

const int NM = 1e5 + 10;
string s;
int n, q;
int b[NM], cnt[NM];
char a[1005];

struct SegmentTree {
    int n;
    vector<int> sum, lazy;

    SegmentTree(int _n = 0){
        n = _n;
        sum.assign(4 * n + 7, 0);
        lazy.assign(4 * n + 7, -1);
    }

    void build(int i, int l, int r, char x){
        if(l > r) return;
        if(l == r){
            sum[i] = (s[l] == x);
            return;
        }

        int m = (l + r) >> 1;
        build(2 * i, l, m, x);
        build(2 * i + 1, m + 1, r, x);
        int tmp = sum[2 * i] + sum[2 * i + 1];
        sum[i] = sum[2 * i] + sum[2 * i + 1];
    }

    void pushDown(int i, int l, int r){
        if(lazy[i] == -1 || l > r) return;

        int m = (l + r) >> 1;
        sum[2 * i] = (m - l + 1) * lazy[i];
        sum[2 * i + 1] = (r - m) * lazy[i];

        lazy[2 * i] = lazy[i];
        lazy[2 * i + 1] = lazy[i];

        lazy[i] = -1;
    }

    void update(int i, int l, int r, int u, int v, int x){
        if(u > r || v < l || l > r) return;
        if(u <= l && v >= r){
            sum[i] = (r - l + 1) * x;
            lazy[i] = x;
            return;
        }
        pushDown(i, l, r);

        int m = (l + r) >> 1;
        update(2 * i, l, m, u, v, x);
        update(2 * i, m + 1, r, u, v, x);
        sum[i] = sum[2 * i] + sum[2 * i + 1];
    }

    int getSum(int i, int l, int r, int u, int v){
        if(u > r || v < l || l > r) return 0;
        if(u <= l && v >= r) return sum[i];
        pushDown(i, l, r);

        int m = (l + r) >> 1;
        int sumL = getSum(2 * i, l, m, u, v);
        int sumR = getSum(2 * i + 1, m + 1, r, u, v);
        return sumL + sumR;
    }

    void update(int u, int v, int x){
        update(1, 1, n, u, v, x);
    }

    int getSum(int u, int v){
        return getSum(1, 1, n, u, v);
    }
};

bool cmp(const char &A, const char &B){
    return A > B;
}
void sub1(){
    for(int i = 1; i <= n; i++) a[i] = s[i];

    while(q--){
        int u, v, type;
        cin >> u >> v >> type;

        if(type == 1) sort(a + u, a + v + 1);
        else sort(a + u, a + v + 1, greater<char>());
    }

    for(int i = 1; i <= n; i++) cout << a[i];
}
void sub2(){
    char u = s[1];
    for(int i = 1; i <= n; i++) u = max(u, s[i]);
    SegmentTree tree(n);
    tree.build(1, 1, n, u);
    for(int i = 1; i <= n; i++) cout << char(tree.getSum(i, i) + 'a');
    cout << '\n';
    cout << tree.getSum(1, n) << '\n';

    while(q--){
        int x, y, type;
        cin >> x >> y >> type;

        int cur = tree.getSum(x, y);
        if(type == 1){
            tree.update(x, x + cur - 1, 0);
            tree.update(y - cur + 1, y, 1);
        } else {
            tree.update(x, x + cur - 1, 1);
            tree.update(y - cur + 1, y, 0);
        }

        for(int i = 1; i <= n; i++) cout << char(tree.getSum(i, i) + 'a');
        cout << '\n';
    }

    //for(int i = 1; i <= n; i++) cout << char(tree.getSum(i, i) + 'a');
}
int32_t main()
{
    FastIO
    freopen("SORTSTR.INP", "r", stdin);
    freopen("SORTSTR.OUT", "w", stdout);
    cin >> n >> q;
    cin >> s;
    s = '#' + s;

    sub2();
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
