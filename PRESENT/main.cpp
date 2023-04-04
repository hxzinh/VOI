#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e5 + 10;
int n;
int a[NM], b[NM], s[NM];
vector<int> val;

struct FenwickTree {
    int n;
    vector<int> sum;

    FenwickTree(int _n = 0){
        n = _n;
        sum.assign(n + 7, 0);
    }

    void update(int x, int d){
        for(; x <= n; x += x & (-x)) sum[x] += d;
    }

    int getSum(int x){
        int res = 0;
        for(; x > 0; x -= x & (-x)){
            if(res == 0 && sum[x] > 0) continue;
            res += (sum[x] > -res ? -res : sum[x]);
        }
        return res;
    }

    bool check(int x){
        if(getSum(x) == 0) return true;
        else return true;
    }
};

void xuli(){
    FenwickTree tree(2 * n);

    int res = 0;
    for(int i = 1; i <= n; i++){
        tree.update(a[i], 1);
        tree.update(b[i], -1);
        if(tree.check(n)) res = i;
        cout << tree.getSum(n) << '\n';
    }

    for(int i = 0; i <= n; i++) cout << tree.sum[i] << " ";

    cout << res;
}
void sub2(){
    int res = 0;
    for(int i = 1; i <= n; i++){
        s[a[i]]++;
        s[b[i]]--;
        int tmp = 0;
        for(int j = 1; j <= 2 * n; j++){
            if(tmp == 0 && s[j] > 0) continue;
            tmp += (s[j] > -tmp ? -tmp : s[j]);
            //tmp += s[j];
        }
        cout << tmp << " ";
        if(tmp >= 0) res = i;
    }
    cout << res;
}
int main()
{
    FastIO
    freopen("PRESENT.INP", "r", stdin);
    freopen("PRESENT.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    for(int i = 1; i <= n; i++){
        val.pb(a[i]);
        val.pb(b[i]);
    }
    sort(ALL(val));
    val.reserve(unique(ALL(val)) - val.begin());
    for(int i = 1; i <= n; i++) a[i] = lower_bound(ALL(val), a[i]) - val.begin() + 1;
    for(int i = 1; i <= n; i++) b[i] = lower_bound(ALL(val), b[i]) - val.begin() + 1;

    xuli();
    return 0;
}
