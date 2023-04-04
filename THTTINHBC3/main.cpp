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
int n, k;
ll a[NM], b[NM];
vector<int> pos, neg;

void xuli(){
    sort(ALL(pos), greater<int>());
    sort(ALL(neg), greater<int>());

    int numPos = 0, numNeg = 0, pp = pos.size(), nn = neg.size();
    for(int i = 0; i < min(3 * k, pp); i++) a[++numPos] = pos[i];
    for(int i = 0; i < min(2 * k, nn); i++) b[++numNeg] = neg[i];

    int idPos = 1, idNeg = 1, cnt = 0;
    ll res = 0;
    while(cnt < k){
        if(numNeg - idNeg + 1 >= 2 && numPos - idPos + 1 > 0)
            if(1LL * b[idNeg] * b[idNeg + 1] * a[idPos] >= 1LL * a[idPos] * a[idPos + 1] * a[idPos + 2]){
                res += b[idNeg] * b[idNeg + 1] * a[idPos];
                idNeg += 2;
                idPos++;
                cnt++;
            } else {
                res += a[idPos] * a[idPos + 1] * a[idPos + 2];
                idPos += 3;
                cnt++;
            }
        else if(numPos - idPos + 1 >= 3) {
            res += a[idPos] * a[idPos + 1] * a[idPos + 2];
            idPos += 3;
            cnt++;
        } else {
            res += a[idPos] * a[idPos + 1] * b[idNeg];
            cnt++;
            idPos += 2;
            idNeg++;
        }
    }

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        ll u; cin >> u;
        if(u >= 0) pos.push_back(u);
        else neg.push_back(-u);
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
