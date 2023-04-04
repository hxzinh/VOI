#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) << (i) & 1)
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e5 + 10;
const int MOD[] = {(int)1e9 + 7, (int)1e9 + 2277};
const int NMOD = 1;
const int BASE = 722;
int n, k;
int maxLen = 0;
int pw[NMOD][NM];
string s[55];

struct Hash {
    int val[NMOD];

    Hash(){
        memset(val, 0, sizeof(val));
    }

    Hash(char c){
        for(int i = 0; i < NMOD; i++) val[i] = c;
    }

    Hash operator + (const Hash &h){
        Hash res;
        for(int i = 0; i < NMOD; i++){
            res.val[i] = val[i] + h.val[i];
            if(res.val[i] >= MOD[i]) res.val[i] -= MOD[i];
        }
        return res;
    }

    Hash operator - (const Hash &h){
        Hash res;
        for(int i = 0; i < NMOD; i++){
            res.val[i] = val[i] - h.val[i];
            if(res.val[i] < MOD[i]) res.val[i] += MOD[i];
        }
        return res;
    }

    Hash operator * (int k) const {
        Hash res;
        for(int i = 0; i < NMOD; i++){
            res.val[i] = 1LL * val[i] * pw[i][k] % MOD[i];
        }
        return res;
    }

    bool operator < (const Hash &h) const {
        for(int i = 0; i < NMOD; i++) if(val[i] != h.val[i])
            return val[i] < h.val[i];
        return false;
    }
};
Hash hashes[55][NM];

Hash getHash(int i, int l, int r){
    return (hashes[l][r] - hashes[i][l - 1]) * (r - l + 1);
}
bool check(int x){
    map<Hash, long long> mp;
    bool ok[NMOD];
    for(int i = 1; i <= n; i++){
        int wordLen = s[i].size();
        map<int, int> cx[NMOD];
        for(int j = 1; j + x - 1 <= wordLen; j++){
            mp[getHash(i, j, j + x - 1)] |= MASK(i);
        }
    }

    for(auto u : mp) if(__builtin_popcount(u.se) >= k) return true;
    return false;
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
    cout << res;
}
int main()
{
    FastIO
    freopen("THUYVAN.INP", "r", stdin);
    freopen("THUYVAN.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        maximize(maxLen, s[i].size());
        s[i] = ' ' + s[i];
    }

    for(int t = 0; t < NMOD; t++){
        pw[t][0] = 1;
        for(int i = 1; i <= maxLen; i++) pw[t][i] = 1LL * pw[t][i - 1] * BASE % MOD[t];
    }

    for(int i = 1; i <= n; i++){
        int len = s[i].size();
        for(int j = 1; j <= len; j++){
            hashes[i][j] = hashes[i][j - 1] + Hash(s[i][j]) * j;
        }
    }

    xuli();
    return 0;
}
