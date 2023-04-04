#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 5e5 + 10;
int k, t;
string n;
bool cx[NM];

struct SegmentTree {
    int n;
    vector<int> maxx;

    SegmentTree(int _n = 0){
        n = _n;
        maxx.assign(4 * n + 7, -1);
    }

    void update(int i, int l, int r, int x, int d){
        if(x < l || x > r) return;
        if(x == l && x == r){
            maxx[i] = d;
            return;
        }
        maxx[i] = max(maxx[i], d);
        int m = (l + r) >> 1;
        update(2 * i, l, m, x, d);
        update(2 * i + 1, m + 1, r, x, d);
        return;
    }

    int getMax(int i, int l, int r, int u, int v){
        if(v < l || u > r || u > v || l > r) return 0;
        if(l >= u && r <= v) return maxx[i];
        int m = (l + r) >> 1;
        int maxL = getMax(2 * i, l, m, u, v);
        int maxR = getMax(2 * i + 1, m + 1, r, u, v);
        return max(maxL, maxR);
    }

    void update(int x, int d){
        update(1, 1, n, x, d);
    }

    int getMax(int u, int v){
        return getMax(1, 1, n, u, v);
    }
};
SegmentTree tree;

void readfile(){
    freopen("DELNUM.INP", "r", stdin);
    freopen("DELNUM.OUT", "w", stdout);
    cin >> n >> k;
    memset(cx, true, sizeof(cx));
}
void xuli(){
    int h = n.size();
    tree = SegmentTree(h + 1);

    for(int i = 0; i < n.length(); i++){
        tree.update(i + 1, int(n[i] - 48));
    }
    int cnt = k;
    for(int i = 0; i < n.length(); i++){
        if(cnt <= 0) break;
        if(i + cnt >= n.length()){
            cx[i] = false;
            cnt--;
            continue;
        }
        int maxium = tree.getMax(i + 1, i + cnt + 1);
        if(int(n[i] - 48) < maxium){
            cx[i] = false;
            cnt--;
        }
    }
    for(int i = 0; i < n.length(); i++)
        if(cx[i]) cout << n[i];
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
