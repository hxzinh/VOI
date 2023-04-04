#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define ii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, m;
ii a[NM], r[NM];
vector<ii> t[NM];
stack<ii> trace[NM];

struct Data {
    int in, out, id, ship;

    bool inline operator < (const Data &A) const {
        return out < A.out;
    }
};

struct SegmentTree{
    int n;
    vector<int> val, t;

    SegmentTree(int _n = 0){
        n = _n;
        val.assign(4 * n + 7, -1);
        t.assign(4 * n + 7, INF);
    }

    void update(int i, int l, int r, int x, int d){
        if(x > r || x < l) return;
        if(l == r && l == x){
            val[i] = d;
            t[i] = (d > 0 ? d : INF);
            return;
        }
        int m = (l + r) >> 1;
        update(2 * i, l, m, x, d);
        update(2 * i + 1, m + 1, r, x, d);
        val[i] = max(val[2 * i], val[2 * i + 1]);
        t[i] = min(t[2 * i], t[2 * i + 1]);
        return;
    }

    int getMin(int i, int l, int r, int u, int v){
        if(u > r || v < l || l > r) return INF;
        if(u >= l && v <= r) return t[i];
        int m = (l + r) >> 1;
        int minL = getMin(2 * i, l, m, u, v);
        int minR = getMin(2 * i + 1, m + 1, r, u, v);
        return min(minL, minR);
    }

    int getMax(int i, int l, int r, int u, int v){
        if(u > r || v < l || l > r) return -1;
        if(u >= l && v <= r) return val[i];
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
    freopen("SEAPORTS.INP", "r", stdin);
    freopen("SEAPORTS.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a[i].fi >> a[i].se;
        r[i].fi = i;
        r[i].se = a[i].fi;
    }
}
bool cmp(const ii &A, const ii &B){
    return (A.fi == B.fi ? A.se < B.se : A.fi < B.fi);
}
bool kmp(const ii &A, const ii &B){
    return (A.se == B.se ? A.fi < B.fi : A.se < B.se);
}
void xuli(){
    tree = SegmentTree(n);
    stack<int> st;

    for(int i = 1; i <= n; i++) st.push(i);

    a[m + 1] = make_pair(m, m);
    sort(a + 1, a + m + 1, cmp);
    sort(r + 1, r + m + 1, kmp);

    int cnt = 0;
    for(int i = 1; i <= m + 1; i++){
        while(true){
            int minH = tree.getMin(1, n);
            if(minH <= a[i].fi){
                int u = trace[minH].top().fi;
                trace[minH].pop();
                st.push(u);
                tree.update(u, -1);
                cnt++;
            } else break;
        }
        if(!st.empty()){
            int u = st.top();
            st.pop();
            tree.update(u, a[i].se);
            trace[a[i].se].push({u, i});
            r[i].se = u;
        } else {
            int maxH = tree.getMax(1, n);
            if(a[i].se >= maxH){
                r[i].se = 0;
                continue;
            }
            int top = trace[maxH].top().fi;
            int id = trace[maxH].top().se;
            trace[maxH].pop();
            r[id].se = 0;
            tree.update(top, a[i].se);
            trace[a[i].se].push({top, i});
            r[i].se = top;
        }
    }
    sort(r + 1, r + m + 1, cmp);
    cout << cnt << '\n';
    for(int i = 1; i <= m; i++) cout << r[i].se << " ";
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
