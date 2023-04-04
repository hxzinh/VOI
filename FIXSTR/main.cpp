#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

/**
//PRAGMA
#pragma GCC target("popcnt")
**/

/**
//ordered_set
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pii,
             null_type,
             less<pii>,
             rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;
**/

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int n, q;
string s, ans[NM];

struct Data {
    int numOpen, numClose, numDiff;

    Data(int _numOpen = 0, int _numClose = 0, int _numDiff = 0) {
        numDiff = _numDiff; numOpen = _numOpen; numClose = _numClose;
    }
};

struct SegmentTree {
    int n;
    vector<Data> sum;

    SegmentTree(int _n = 0) {
        n = _n;
        sum.assign(4 * n + 7, Data(0, 0, 0));
    }

    void modify(int i) {
        sum[i].numOpen = sum[2 * i + 1].numOpen;
        sum[i].numClose = sum[2 * i].numClose;

        if(sum[2 * i].numOpen > sum[2 * i + 1].numClose) sum[i].numOpen += sum[2 * i].numOpen - sum[2 * i + 1].numClose;
        else sum[i].numClose += sum[2 * i + 1].numClose - sum[2 * i].numOpen;

        sum[i].numDiff = sum[i].numOpen + sum[i].numClose;
    }

    void build(int i, int l, int r) {
        if(l == r) {
            if(s[l] == '(') sum[i].numOpen++;
            else sum[i].numClose++;
            sum[i].numDiff = 1;
            return;
        }

        int m = (l + r) >> 1;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);

        modify(i);
    }

    void update(int i, int l, int r, int u, int x) {
        if(l > r || u > r || u < l) return;
        if(u == l && l == r) {
            if(x == 1) {
                sum[i].numOpen = 0;
                sum[i].numClose = 1;
            }
            else {
                sum[i].numOpen = 1;
                sum[i].numClose = 0;
            }
            sum[i].numDiff = 1;
            return;
        }

        int m = (l + r) >> 1;
        update(2 * i, l, m, u, x);
        update(2 * i + 1, m + 1, r, u, x);

        modify(i);
    }

    Data getAns(int i, int l, int r, int u, int v) {
        if(u > r || v < l || l > r) return Data(0, 0, 0);
        if(u <= l && v >= r) return sum[i];

        int m = (l + r) >> 1;
        Data sumL = getAns(2 * i, l, m, u, v);
        Data sumR = getAns(2 * i + 1, m + 1, r, u, v);

        int curOpen = max(0, sumL.numOpen - sumR.numClose) + sumR.numOpen;
        int curClose = max(0, sumR.numClose - sumL.numOpen) + sumL.numClose;

        return Data(curOpen, curClose, curOpen + curClose);
    }

    void update(int u, int x) {
        update(1, 1, n, u, x);
    }

    Data getAns(int u, int v) {
        return getAns(1, 1, n, u, v);
    }
};

void sub1() {
    ans[0] = s;
    for(int i = 1; i <= q; i++) {
        char t;
        int u, v;
        cin >> t >> u;
        if(t == 'C') {
            s[u] = (s[u] == '(') ? ')' : '(';
            ans[i] = s;
        } else
        if(t == 'U') {
            s = ans[u - 1];
            ans[i] = s;
        }
        else {
            cin >> v;
            int cntOpen = 0, res = 0;
            for(int j = u; j <= v; j++) {
                if(s[j] == '(') cntOpen++;
                else {
                    if(cntOpen) cntOpen--;
                    else res++;
                }
            }
            res += cntOpen;

            ans[i] = s;

            cout << res << '\n';
        }
    }
}
void sub2() {
    SegmentTree tree(n);
    tree.build(1, 1, n);

    Data cur = tree.getAns(1, 5);
    cout << cur.numOpen << " " << cur.numClose << " " << cur.numDiff << '\n';

    for(int i = 1; i <= q; i++) {
        char t;
        int u, v;
        cin >> t >> u;
        if(t == 'C') {
            if(s[u] == '(') {
                tree.update(u, 1);
                s[u] = ')';
            }
            else {
                tree.update(u, 0);
                s[u] = '(';
            }


        }
        else {
            cin >> v;
            Data res = tree.getAns(u, v);
            cout << res.numDiff << '\n';
        }
    }
}
int32_t main()
{
    FastIO
    freopen("FIXSTR.INP", "r", stdin);
    freopen("FIXSTR.OUT", "w", stdout);
    cin >> s;
    n = s.size();
    s = "#" + s;
    cin >> q;

    sub2
    ();
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
