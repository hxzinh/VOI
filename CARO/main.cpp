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

string s[3];

void xuli() {
    //for(int i = 0; i < 3; i++) cout << s[i] << '\n';

    int cntX = 0, cntO = 0, cntDot = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) {
            if(s[i][j] != '0' && s[i][j] != 'X' && s[i][j] != '.') {
                cout << "invalid";
                return;
            }

            if(s[i][j] == 'X') cntX++;
            if(s[i][j] == '0') cntO++;
            if(s[i][j] == '.') cntDot++;
        }

    for(int i = 0; i < 3; i++) {
        if(s[i] == "XXX") {
            cout << "TL won";
            return;
        }
        if(s[i] == "000") {
            cout << "BD won";
            return;
        }
    }

    for(int i = 0; i < 3; i++) {
        string tmp = "";
        for(int j = 0; j < 3; j++) tmp += s[j][i];

        if(tmp == "XXX") {
            cout << "TL won";
            return;
        }
        if(tmp == "000") {
            cout << "BD won";
            return;
        }
    }

    string caro = "";
    for(int i = 0; i < 3; i++) caro += s[i][i];
    if(caro == "XXX") {
        cout << "TL won";
        return;
    }
    if(caro == "000") {
        cout << "BD won";
        return;
    }

    caro = "";
    for(int i = 2; i >= 0; i--) caro += s[i][i];
    if(caro == "XXX") {
        cout << "TL won";
        return;
    }
    if(caro == "000") {
        cout << "BD won";
        return;
    }

    if(cntO > cntX || (cntDot == 0 && cntO >= cntX) || cntX - cntDot > 1) cout << "invalid";
    else if(cntDot == 0) cout << "draw";
    else if(cntX > cntO) cout << "BD was making a move";
    else cout << "TL was making a move";
}
int32_t main()
{
    FastIO
    freopen("CARO.INP", "r", stdin);
    freopen("CARO.OUT", "w", stdout);
    for(int i = 0; i < 3; i++) cin >> s[i];
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
