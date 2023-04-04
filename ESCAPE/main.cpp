#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e4 + 10;
int T, n, h;
int bonus = 0;
int high[NM];
pii a[NM];

struct Data {
    int high, up;

    bool inline operator < (const Data &A) const {
        return high < A.high;
    }
};

bool cmp(const pii &A, const pii &B){
    return A.se < B.se;
}
void xuli(){
    sort(a + 1, a + n + 1, cmp);
    priority_queue<Data> pq;

    high[n + 1] = 0;
    for(int i = n; i > 0; i--) high[i] = high[i + 1] + a[i].fi;

    for(int i = 1; i <= n; i++){
        pq.push({a[i].fi, a[i].se});
        if(a[i].se + high[i + 1] < h){
            h -= pq.top().high;
            pq.pop();
        }
    }

    cout << pq.size() << '\n';
}
void readfile(){
    freopen("ESCAPE.INP", "r", stdin);
    freopen("ESCAPE.OUT", "w", stdout);
    cin >> T;
    while(T--){
        cin >> n >> h;
        for(int i = 1; i <= n; i++) cin >> a[i].fi;
        for(int i = 1; i <= n; i++) cin >> a[i].se;
        xuli();
    }
}
int32_t main()
{
    FastIO
    readfile();
    return 0;
}
