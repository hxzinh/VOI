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
int n, q;
int pref[NM];
string s;

struct SegmentTree {
    vector<int> lazy, val;
    set<int> close;
    int n;

    void build(int i, int l, int r){
        if(l == r){
             val[i] = pref[l];
             return;
        }
        int m = (l + r) >> 1;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);
        val[i] = min(val[2 * i], val[2 * i + 1]);
    }

    SegmentTree(int _n = 0){
        n = _n;
        val.assign(4 * n + 7, 0);
        lazy.assign(4 * n + 7, 0);

        for(int i = 1; i <= n; i++) if(s[i] == ')') close.insert(i);

        for(int i = 1; i <= n; i++){
            pref[i] = pref[i - 1];
            if(s[i] == '(') pref[i]++;
            else pref[i]--;
        }

        build(1, 1, n);
    }

    int getClose(){
        return *close.begin();
    }

    void down(int i){
        if(lazy[i] == 0) return;
        val[2 * i] += lazy[i];
        val[2 * i + 1] += lazy[i];

        lazy[2 * i] += lazy[i];
        lazy[2 * i + 1] += lazy[i];

        lazy[i] = 0;
        return;
    }

    void update(int i, int l, int r, int u, int v, int d){
        if(u > r || v < l) return;
        if(u <= l && v >= r){
            val[i] += d;
            lazy[i] += d;
            return;
        }
        down(i);

        int m = (l + r) >> 1;
        update(2 * i, l, m, u, v, d);
        update(2 * i + 1, m + 1, r, u, v, d);
        val[i] = min(val[2 * i], val[2 * i + 1]);
    }

    int getOpen(int i, int l, int r){
        if(l == r){
            if(val[i] >= 2) return l;
            else return n + 1;
        }
        down(i);
        int m = (l + r) >> 1;
        int t = val[2 * i + 1];
        int k = val[2 * i];
        if(val[2 * i + 1] < 2) return getOpen(2 * i + 1, m + 1, r);
        else return min(m + 1, getOpen(2 * i, l, m));
    }

    void flipp(int x){
        s[x] = '(' + ')' - s[x];
        if(s[x] == ')'){
            close.insert(x);
            update(1, 1, n, x, n, -2);
        } else {
            close.erase(x);
            update(1, 1, n, x, n, 2);
        }
    }
};

void readfile(){
    freopen("BRACKET.INP", "r", stdin);
    freopen("BRACKET.OUT", "w", stdout);
    cin >> n >> q;
    cin >> s;
}
int getAns1(){
    queue<int> t;
    queue<int> k;
    for(int i = s.length() - 1; i >= 0; i--){
        if(s[i] == '('){
            if(t.empty()) k.push(i);
            else t.pop();
        }
        else if(s[i] == ')') t.push(i);
    }
    if(t.size() > 1) return t.back();
    if(k.size() > 1) return k.front();
}
void sub1(){
    while(q--){
        int u; cin >> u;
        s[u - 1] = s[u - 1] == ')' ? '(' : ')';
        int res = getAns1();
        cout << res + 1 << " ";
        s[res] = s[res] == ')' ? '(' : ')';
    }
}
void full(){
    s = " " + s;
    SegmentTree tree(n);
    while(q--){
        int u; cin >> u;
        tree.flipp(u);

        int res = -1;
        if(s[u] == ')') res = tree.getClose();
        else res = tree.getOpen(1, 1, n);

        tree.flipp(res);
        cout << res << " ";
    }
}
int main()
{
    FastIO
    readfile();
    full();
    return 0;
}
