#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) << (i) & 1)
#define pii pair<int, int>
#define fi first
#define se second
#define __builtin_popcount __builtin_popcountll
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int MAX = 2e5 + 1;
const int NMOD = 2;
const int MOD[] = { (int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277 };
const int BASE = 257;

int n, k;
int maxLen = 0;
int pw[NMOD][MAX];
string s[51];

struct Hash {
    ll value[NMOD];

    Hash() {
        memset(value, 0, sizeof value);
    }

    Hash(char c) {
        for (int i = 0; i < NMOD; i++) value[i] = c;
    }

    Hash operator + (const Hash &h) const {
        Hash res;
        for (int i = 0; i < NMOD; i++) {
            res.value[i] = value[i] + h.value[i];
            if (res.value[i] > MOD[i]) res.value[i] -= MOD[i];
        }
        return res;
    }

    Hash operator - (const Hash &h) const {
        Hash res;
        for (int i = 0; i < NMOD; i++) {
            res.value[i] = value[i] - h.value[i];
            if (res.value[i] < 0) res.value[i] += MOD[i];
        }
        return res;
    }

    Hash operator * (const int &k) const {
        Hash res;
        for (int i = 0; i < NMOD; i++)
            res.value[i] = (1LL * value[i] * pw[i][k]) % MOD[i];
        return res;
    }

    bool operator < (const Hash &h) const {
        for (int i = 0; i < NMOD; i++) if (value[i] != h.value[i])
            return value[i] < h.value[i];
        return false;
    }
};
Hash hashes[51][MAX];
map<Hash, ll> mp;

void prepare() {
    for (int i = 0; i < NMOD; i++) pw[i][0] = 1;

    for (int i = 1; i < MAX; i++)
        for (int j = 0; j < NMOD; j++)
            pw[j][i] = (1LL * pw[j][i - 1] * BASE) % MOD[j];

    for (int i = 1; i <= n; i++) {
        int len = (int)s[i].size() - 1;
        for (int j = 1; j <= len; j++)
            hashes[i][j] = (hashes[i][j - 1] + Hash(s[i][j]) * j);
    }
}

Hash getHash(int i, int l, int r) {
    return (hashes[i][r] - hashes[i][l - 1]) * (MAX - l);
}

bool check(int x) {
    mp.clear();
    for (int i = 1; i <= n; i++) {
        int len = (int)s[i].size() - 1;
        for (int j = 1; j + x - 1 <= len; j++)
            mp[getHash(i, j, j + x - 1)] |= MASK(i);
    }

    for (auto u : mp) if (__builtin_popcountll(u.se) >= k) return true;
    return false;
}
void trace(int x){
    map<string, ll> cnt;

    string res = "";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j + x - 1 < s[i].size(); j++){
            cnt[s[i].substr(j, x)] |= MASK(i);
            if(__builtin_popcount(cnt[s[i].substr(j, x)]) >= k){
                res = s[i].substr(j, x);
                break;
            }
        }
    }
    cout << res;
}
void xuli(){
    int l = 1, r = maxLen, res = 0;
    while(l <= r){
        int m = (l + r) >> 1;
        if(check(m)){
            res = m;
            l = m + 1;
        } else r = m - 1;
    }
    trace(res);
}
int32_t main()
{
    FastIO
    freopen("THUYVAN.INP", "r", stdin);
    freopen("THUYVAN.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        maximize(maxLen, s[i].size());
        s[i] = " " + s[i];
    }

    prepare();
    xuli();
    return 0;
}
