#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1LL)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, q;
int a[NM];

struct TrieNode {
    int par, cnt;
    int isEnd;
    int child[3];

    TrieNode(int _par = 0, int _cnt = 0, int _isEnd = 0){
        par = _par;
        cnt = _cnt;
        isEnd = _isEnd;
        child[0] = child[1] = child[2] = -1;
    }
};

struct Trie {
    vector<TrieNode> val;

    Trie(){
        val.push_back(TrieNode(-1));
    }

    void update(int x){
        int node = 0;
        for(int i = 31; i >= 0; i--){
            int v = BIT(x, i);
            if(val[node].child[v] < 0){
                val.push_back(TrieNode(node));
                val[node].child[v] = val.size() - 1;
            }
            node = val[node].child[v];
            val[node].cnt++;
        }
    }

    int getTrie(int x, int k){
        int node = 0, res = 0;

        for(int i = 31; i >= 0; i--){
            int v = BIT(x, i);
            if(val[node].child[1 - v] < 0){
                res = res * 2;
                node = val[node].child[v];
            } else {
                int u = val[node].child[1 - v];
                if(k - val[u].cnt > 0){
                    k -= val[u].cnt;
                    res = res * 2;
                    node = val[node].child[v];
                } else {
                    res = res * 2 + 1;
                    node = u;
                }
            }
        }
        return res;
    }
};

void sub1(){
    while(q--){
        string u;
        int k;
        cin >> u >> k;
        if(u == "XOR") for(int i = 1; i <= n; i++) a[i] ^= k;
        if(u == "FIND"){
            sort(a + 1, a + n + 1);
            cout << a[n - k + 1] << '\n';
        }
    }
}
void xuli(){
    Trie tree;
    for(int i = 1; i <= n; i++)
        tree.update(a[i]);

    int sum = 0;
    while(q--){
        string u;
        int k;
        cin >> u >> k;
        if(u == "XOR") sum ^= k;
        else cout << tree.getTrie(sum, k) << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("VOXOR.INP", "r", stdin);
    freopen("VOXOR.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n ; i++) cin >> a[i];

    xuli();
    return 0;
}
