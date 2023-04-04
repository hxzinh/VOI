#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define mp make_pair
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

const int NM = 1e3 + 10;
int T, sum, p, maxSum = -1, maxPsum = -1;
ll result = 0;
bool ok[1000][10000];
pii query[NM];
map<pii, string> ans;

struct Data {
    string u;
    int curSum, pSum;
};

void init() {
    for(int i = 0; i <= sum; i++)
        for(int j = 0; j <= p; j++) ok[i][j] = false;
}
void sub2() {
    queue<Data> q;
    for(int i = 1; i < 10; i++) {
        ok[i][i * i] = true;
        ans[mp(i, i * i)] = string(1, i + '0');
        q.push({string(1, i + '0'), i, i * i});
    }

    while(q.size()) {
        string u = q.front().u;
        int curSum = q.front().curSum, pSum = q.front().pSum;
        q.pop();

        //cout << u << " " << curSum << " " << pSum << '\n';
        ans[mp(curSum, pSum)] = u;
        if(curSum > maxSum || pSum > maxPsum || u.size() >= 100) continue;

        for(int i = 1; i < 10; i++) {
            int newSum = curSum + i, newPsum = pSum + i * i;
            if(newSum > maxSum || newPsum > maxPsum || ok[newSum][newPsum]) continue;
            ok[newSum][newPsum] = true;
            q.push({u + char(i + '0'), newSum, newPsum});
        }
    }

    for(int i = 1; i <= T; i++) {
        sum = query[i].fi, p = query[i].se;

        if(sum > 900 || p > 8100) {
            cout << "No solution" << '\n';
            continue;
        }

        string u = ans[mp(sum, p)];
        if(u.size()) cout << u << '\n';
        else cout << "No solution" << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("SPNUM.INP", "r", stdin);
    freopen("SPNUM.OUT", "w", stdout);
    cin >> T;
    for(int i = 1; i <= T; i++) {
        int u, v; cin >> u >> v;
        query[i] = mp(u, v);
        if(u <= 900) maximize(maxSum, u);
        if(v <= 8100) maximize(maxPsum, v);
    }

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
