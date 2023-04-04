#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

/**
//PRAGMA
#pragma GCC target("popcnt")
**/

/**
//ordered_set
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pii,
             null_type,
             less<pii>,
             rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;
**/

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
const int MOD = 1e9 + 9;
int n;
int a[NM];
ll s[NM];

void add(ll &a, ll b) {
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}

struct FenwickTree {
    int n;
    vector<ll> sum;

    FenwickTree(int _n = 0) {
        n = _n;
        sum.assign(n + 7, 0);
    }

    void update(int u, ll x) {
        for(; u <= n; u += u & -u) add(sum[u], x);
    }

    ll getCnt(int u) {
        ll res = 0;
        for(; u > 0; u -= u & -u) add(res, sum[u]);
        return res;
    }
};


// Structure of the node
struct Node {

    ll value;
    struct Node *L, *R;
};

// Structure to get the newly formed
// node
struct Node* getnode()
{
    struct Node* temp = new struct Node;
    temp->value = 0;
    temp->L = NULL;
    temp->R = NULL;
    return temp;
}

// Creating the Root node
struct Node* root;

// Function to perform the point update
// on the dynamic segment tree
void UpdateHelper(struct Node* curr, ll index,
                  ll L, ll R, ll val)
{

    if (L > index || R < index)
        return;
    if (L == R && L == index)
    {

        // Update the value of the node
        // to the given value
        curr->value += val;
        return;
    }
    ll mid = L - (L - R) / 2;
    ll sum1 = 0, sum2 = 0;

    if (index <= mid) {
        if (curr->L == NULL)
            curr->L = getnode();
        UpdateHelper(curr->L, index, L, mid, val);
    }

    else {
        if (curr->R == NULL)
            curr->R = getnode();
        UpdateHelper(curr->R, index, mid + 1, R, val);
    }
    if (curr->L)
        sum1 = curr->L->value;
    if (curr->R)
        sum2 = curr->R->value;
    curr->value = (sum1 + sum2) % MOD;
    return;
}
ll queryHelper(struct Node* curr, ll a,
               ll b, ll L, ll R)
{
    if (curr == NULL)
        return 0;
    if (L > b || R < a)
        return 0;
    if (L >= a && R <= b)
        return curr->value;

    ll mid = L - (L - R) / 2;
    return (queryHelper(curr->L, a, b, L, mid)
           + queryHelper(curr->R, a, b, mid + 1, R)) % MOD;
}
ll query(long long L, long long R)
{
    return queryHelper(root, L, R, -1e18, 1e18);
}
void update(long long index, int value)
{
    UpdateHelper(root, index, -1e18, 1e18, value);
}


void xuli() {
    vector<int> vec;
    vec.push_back(-INF);
    for(int i = 1; i <= n; i++) vec.push_back(s[i]);
    sort(ALL(vec));
    vec.resize(unique(ALL(vec)) - vec.begin());

    /**
    for(int u : vec) cout << u << " ";
    cout << '\n';
    **/

    FenwickTree tree(vec.size());
    tree.update(lower_bound(ALL(vec), 0) - vec.begin() + 1, 1);
    for(int i = 1; i <= n; i++) {
        int u = lower_bound(ALL(vec), s[i]) - vec.begin() + 1;
        ll cnt = tree.getCnt(u);
        tree.update(u, cnt);

        if(i == n) cout << cnt;
    }
}
int32_t main()
{
    FastIO
    freopen("HPROTEST.INP", "r", stdin);
    freopen("HPROTEST.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    if(s[n] < 0) {
        cout << 0;
        return 0;
    }

    xuli();
    return 0;
}

/* Author: hxzinh */

/*
-----code ko bug-----code ko bug-----code ko bug--------------

          _.-/`)
         // / / )
      .=// / / / )
     //`/ / / / /
    // /     ` /
   ||         /
    \\       /
     ))    .'
    //    /
         /
*/
