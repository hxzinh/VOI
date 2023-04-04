#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
const int MAX = 100000;
const int MOD = 1e9 + 7;
const int BASE = 256;
int n, m, k;
string s;
string a[10005];
int pw[NM], h[NM], ha[NM];
map<string, int> mp, cntString, cnted;

int getHash(int l, int r) {
	return 1LL * (h[r] - h[l - 1] + MOD) * pw[MAX - r] % MOD;
}
bool Equal(int u, int v, int l) {
	return getHash(u, u + l - 1) == getHash(v, v + l - 1);
}

void sub1() {
    k = n;
    s += s; n += n;
    int res = INF;
    for(int i = 1; i <= k; i++) {
        int ans = 0;
        for(int j = 1; j <= m; j++) {
            for(int x = 0; x < a[j].size(); x++) {
                for(int y = 1; y + x - 1 <= a[j].size(); y++) {
                    string tmp = a[j].substr(x, y);

                    for(int u = i; u <= i + k - 1; u++) {
                        if(u + y - 1 > i + k - 1) break;
                        string cur = s.substr(u, y);
                        if(tmp == cur) {
                            maximize(ans, y);
                            break;
                        }
                    }
                }
            }
        }
        minimize(res, ans);
    }
    cout << res;
}
bool check(int x) {
    for(int i = 1; i <= k; i++) {
        int ans = 0;
        for(int j = 1; j <= m; j++) {
            for(int u = 0; u < a[j].size(); u++) {
                if(u + x - 1 >= a[j].size()) break;
                string tmp = a[j].substr(u, x);
                for(int v = i; v + x - 1 <= i + k - 1; v++) {
                    string cur = s.substr(v, x);
                    if(tmp == cur) {
                        ans = 1;
                        break;
                    }
                }
                if(ans) break;
            }
            if(ans) break;
        }
        if(ans == 0) return true;
    }
    return false;
}
void sub2() {
    k = n;
    s += s; n += n;

    int l = 0, r = n, res = INF;
    while(l <= r) {
        int m = (l + r) >> 1;
        if(check(m)) {
            res = m;
            r = m - 1;
        } else l = m + 1;
    }

    cout << res - 1;
}
int main()
{
    FastIO
    freopen("MINSTR.INP", "r", stdin);
    freopen("MINSTR.OUT", "w", stdout);
    cin >> n >> m;
    cin >> s;
    s = '#' + s;
    for(int i = 1; i <= m; i++) cin >> a[i];

    //for(int i = 1; i <= m; i++) cout << a[i].size() << '\n';

    if(n <= 100) sub1();
    else sub2();
    return 0;
}
