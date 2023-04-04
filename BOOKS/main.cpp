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
int n, q;
int a[NM], cnt[NM], query[NM];
stack<int> st;

void xuli() {
    for(int i = n; i > 0; i--) if(!cnt[i]) {
        st.push(i);
    }

    for(int i = 1; i <= q; i++) {
        --cnt[query[i]];
        if(!cnt[query[i]]) st.push(query[i]);
    }

    while(st.size()) {
        cout << st.top() << '\n';
        st.pop();
    }
}
int32_t main()
{
    FastIO
    freopen("BOOKS.INP", "r", stdin);
    freopen("BOOKS.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= q; i++) {
        cin >> query[i];
        cnt[query[i]]++;
    }

    xuli();
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
