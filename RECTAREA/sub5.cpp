#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define MAX 100005
#define ALL(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n;

struct Point{
    int x = 0, y = 0, v = 0, sta = 0;

    Point(int _x, int _y, int _v, int _sta){
        x = _x, y = _y, v = _v, sta = _sta;
    }
};
vector<Point> p;


struct SegmentTree {
    int n;
    map<int, int> sum, cnt;

    SegmentTree(int _n = 0){
        n = _n;
        ///sum.assign(4 * n + 7, 0);
        ///cnt.assign(4 * n + 7, 0);
    }

    void update(int i, int l, int r, int u, int v, int d){
        if(r <= u || l >= v) return;
        if(u <= l && r <= v){
            cnt[i] += d;
            if(!cnt[i]) sum[i] = sum[2 * i] + sum[2 * i + 1];
            else sum[i] = r - l;
            return;
        }
        int m = (l + r) >> 1;
        update(2 * i, l, m, u, v, d);
        update(2 * i + 1, m, r, u, v, d);
        //cnt[i] = cnt[2 * i] + cnt[2 * i + 1];
        if(!cnt[i]) sum[i] = sum[2 * i] + sum[2 * i + 1];
        else sum[i] = r - l;
    }

    void update(int u, int v, int d){
        update(1, 0, n, u, v, d);
    }
};

bool cmp(const Point &A, const Point &B){
    return A.x < B.x;
}
void sub4(){
    sort(ALL(p), cmp);

    SegmentTree tree(MAX + 1);
    int res = 0;
    for(int i = 0; i < (p.size() - 1); i++){
        int len = p[i + 1].x - p[i].x;
        tree.update(p[i].y, p[i].v, p[i].sta);
        int s = tree.sum[1];
        res += tree.sum[1] * len;
    }
    cout << res;
}
void readfile(){
    freopen("RECTAREA.INP", "r", stdin);
    freopen("RECTAREA.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        p.push_back(Point(x, y, v, 1));
        p.push_back(Point(u, y, v, -1));
    }
}
int32_t main(){
    FastIO;
    readfile();
    sub4();
    return 0;
}
