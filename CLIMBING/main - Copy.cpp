#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int n, k, h;
int a[NM];

struct SegmentTree {
    int n;
    vector<int> minn, maxx;

    SegmentTree(int _n = 0){
        n = _n;
        minn.assign(4 * n + 7, -1);
        maxx.assign(4 * n + 7, -1);
    }

    void update(int i, int l, int r, int x, int d){
        if(l > x || r < x) return;
        if(l == r && l == x){
            minn[i] = maxx[i] = d;
            return;
        }
        int m = (l + r) >> 1;
        update(2 * i, l, m, x, d);
        update(2 * i + 1, m + 1, r, x, d);
        minn[i] = min(minn[2 * i], minn[2 * i + 1]);
        maxx[i] = max(maxx[2 * i], maxx[2 * i + 1]);
    };

    int getMin(int i, int l, int r, int u, int v){
        if(l > v || r < u) return INF;
        if(u <= l && v >= r){
            return minn[i];
        }
        int m = (l + r) >> 1;
        int minL = getMin(2 * i, l, m, u, v);
        int minR = getMin(2 * i + 1, m + 1, r, u, v);
        return min(minL, minR);
    }

    int getMax(int i, int l, int r, int u, int v){
        if(l > v || r < u) return -1;
        if(u <= l && v >= r){
            return maxx[i];
        }
        int m = (l + r) >> 1;
        int maxL = getMax(2 * i, l, m, u, v);
        int maxR = getMax(2 * i + 1, m + 1, r, u, v);
        return max(maxL, maxR);
    }

    void update(int x, int d){
        update(1, 1, n, x, d);
    }

    int getMin(int u, int v){
        return getMin(1, 1, n, u, v);
    }

    int getMax(int u, int v){
        return getMax(1, 1, n, u, v);
    }
};
SegmentTree tree;

void readfile(){
    cin >> n >> k >> h;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void xuli(){
    tree = SegmentTree(n);
    for(int i = 1; i <= n; i++) tree.update(i, a[i]);

    vector<int> ans;
    for(int i = 1; i <= n - k + 1; i++){
        int minDist = tree.getMin(i, i + k - 1);
        int maxDist = tree.getMax(i, i + k - 1);
        if(maxDist - minDist <= h) ans.push_back(i);
    }
    for(int u : ans) cout << u << '\n';
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
