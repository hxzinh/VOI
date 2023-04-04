#include <bits/stdc++.h>
#define int long long
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

const int NM = 1e4 + 10;
int T;
vector<int> a[11];
int val[NM], id[NM];


void sub1(){
    for(int i = 1; i <= 1000; i++){
        for(int j = 0; j < 10; j++) if(BIT(i, j)) a[j].push_back(i);
    }

    while(T--){
        for(int i = 0; i < 10; i++){
            cout << a[i].size() << " ";
            for(int u : a[i]) cout << u << " ";
            cout << endl;
        }

        string s;
        int res = 0;
        cin >> s;
        for(int i = 0; i < s.size(); i++) if(s[i] == '+') res += MASK(i);
        cout << res << endl;
    }
}
void solve(){
    int cnt = 0, n = 10;
    vector<int> grayCode;
    for(int i = 0; i <= 1000; i++){
        int cur = i^(i>>1);
        val[cur] = i;
        for(int j = 0; j < 10; j++) if(BIT(cur, j)) a[j].push_back(i);
    }

    while(T--){
        for(int i = 0; i < 10; i++){
            cout << a[i].size() << " ";
            for(int u : a[i]) cout << u<< " ";
            cout << endl;
        }

        int res = 0;
        string s; cin >> s;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '+') res |= MASK(i);
        }
        cout << val[res] << endl;
    }
}
int32_t main()
{
    FastIO
    freopen("COVID.INP", "r", stdin);
    freopen("COVID.OUT", "w", stdout);
    cin >> T;

    //sub1();
    solve();
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
