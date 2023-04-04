#include <bits/stdc++.h>
#define ll long long
#define int long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, m;
string s = "";

struct SegmentTree {
    int n;
    vector<int> val, lazy;

    SegmentTree (int _n = 0){
        n = _n;
        val.assign(4 * n + 7, 0);
        lazy.assign(4 * n + 7, 0);
    }

    void pushDown(int i){
        if(!lazy[i]) return;

        lazy[2 * i] += lazy[i]; val[2 * i] += lazy[i];
        lazy[2 * i + 1] += lazy[i]; val[2 * i + 1] += lazy[i];

        lazy[i] = 0;
        return;
    }

    void update(int i, int l, int r, int u, int c){
        if(u < l || u > r) return;
        if(u == l && l == r){
            val[u] += c;
            lazy[u] += c;
            return;
        }
        pushDown(i);

        int m = (l + r) >> 1;
        update(2 * i, l, m, u, c);
        update(2 * i + 1, m + 1, r, u, c);
        val[i] = val[2 * i] + val[2 * i + 1];
        return;
    }

    int getSum(int i, int l, int r, int u, int v){
        if(u > r || v < l) return 0;
        if(u <= l && v >= r) return val[i];

        pushDown(i);

        int m = (l + r) >> 1;
        int sumL = getSum(2 * i, l, m, u, v);
        int sumR = getSum(2 * i + 1, m + 1, r, u, v);
        return sumL + sumR;
    }

    void update(int u, int c){
        update(1, 1, n, u, c);
    }

    int getSum(int u, int v){
        return getSum(1, 1, n, u, v);
    }
};

void sub1(){
    for(int i = 1; i <= m; i++){
        int u; char c;
        cin >> u >> c;
        s[u] = c;

        int cnt = 1;
        if(c == '('){
            for(int j = u + 1; j <= m; j++){
                if(s[j] == '(') cnt++;
                if(s[j] == ')' && !(--cnt)){
                    cout << j << '\n';
                    break;
                }
            }
        } else if(c == ')') {
            for(int j = u - 1; j > 0; j--){
                if(s[j] == ')') cnt++;
                if(s[j] == '(' && !(--cnt)){
                    cout << j << '\n';
                    break;
                }
            }
        }
        if(c == '(' || c == ')') if(cnt) cout << -1 << '\n';
    }
}
void full(){
    SegmentTree tree(n + 1);

    for(int i = 1; i <= n; i++) tree.update(i, i);

    cout << tree.getSum(1, n);
}
int32_t main()
{
    FastIO
    freopen("IDE.INP", "r", stdin);
    freopen("IDE.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) s = s + 'a';
    s = '#' + s;

    full();
    return 0;
}
