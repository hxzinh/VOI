#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, S, q;
int a[NM], b[NM];

struct SegmentTree {
    int n;
    vector<int> val, lazy;

    SegmentTree(int _n = 0){
        n = _n;
        lazy.assign(n << 2 + 7, 0);
        val.assign(n << 2 + 7, 0);
    }

    void pushDown(int i, int l, int r){

    }

    void update(int i, int l, int r, int x, int d){
        if(l > r || l > x || r < x) return;
        if(l == r && l == x){
            val[i] += x;
            return;
        }
        int m = (l + r) >> 1;
        update(2 * i, l, m, x, d);
        update(2 * i + 1, m + 1, r, x, d);
        val[i] = max(val[2 * i], val[2 * i + 1]);
        return;
    }
};

void sub1(){

}
int main()
{
    FastIO
    freopen("NUMSEQ.INP", "r", stdin);
    freopen("NUMSEQ.OUT", "w", stdout);
    cin >> n >> S;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    cin >> q;

    sub1();
    return 0;
}
