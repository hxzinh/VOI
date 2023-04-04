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
int n, L, R;
int a[NM], s[NM];

struct SegmentTree {
    int n;
    vector<int> sum;

    SegmentTree(int _n = 0){
        n = _n;
        sum.assign(4 * n + 7, INF);
    }

    void update(int i, int l, int r, int x, int d){
        if(l > r || x > r || x < l) return;
        if(l == r && l == x){
            sum[i] = d;
            return;
        }
        int m = (l + r) >> 1;
        update(2 * i, l, m, x, d);
        update(2 * i + 1, m + 1, r, x, d);
        sum[i] = min(sum[2 * i], sum[2 * i + 1]);
        return;
    }

    int getMin(int i, int l, int r, int u, int v){
        if(l > r || u > r || v < l) return INF;
        if(l >= u && r <= v) return sum[i];
        int m = (l + r) >> 1;
        int minL = getMin(2 * i, l, m, u, v);
        int minR = getMin(2 * i + 1, m + 1, r, u, v);
        return min(minL, minR);
    }

    void update(int x, int d){
        update(1, 1, n, x, d);
    }

    int getMin(int u, int v){
        return getMin(1, 1, n, u, v);
    }
};

void xuli(){
    SegmentTree tree(n);
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    int res = -INF, head = -1, last = -1;
    for(int i = 1; i <= n; i++){
        tree.update(i, s[i]);
        if(i > L){
            int u = max(-1, i - L);
            int v = max(-1, i - R);
            if(u == -1) continue;
            if(v == -1){
                if(maximize(res, s[i] - s[u])) last = i;
            } else {
                if(maximize(res, s[i] - tree.getMin(v, u))) last = i;
            }
        }
    }
    cout << res << '\n';
    cout << last;
}
void readfile(){
    freopen("MAXSUBSEQ.INP", "r", stdin);
    freopen("MAXSUBSEQ.OUT", "w", stdout);
    cin >> n >> L >> R;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
