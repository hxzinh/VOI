#include <bits/stdc++.h>
#define int long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e5 + 10;
int n, k;
int h[NM];

struct SegmentTree {
    int n;
    vector<int> maxx, cnt;

    SegmentTree(int _n = 0){
        n = _n;
        maxx.assign(4 * n + 7, -1);
        cnt.assign(4 * n + 7, 0);
    }

    void update(int i, int l, int r, int x, int d){
        if(x < l || x > r) return;
        maxx[i] = max(maxx[i], d);
        cnt[i]++;
        if(x == l && x == r) return;
        int m = (l + r) >> 1;
        update(2 * i, l, m, x, d);
        update(2 * i + 1, m + 1, r, x, d);
        return;
    }

    int getCnt(int i, int l, int r, int x){
        if(x < l || x > r || l < r) return 0;
        if(maxx[i] <= x) return cnt[i];
        int m = (l + r) >> 1;
        int cntL = getCnt(2 * i, l, m, x);
        int cntR = getCnt(2 * i + 1, m + 1, r, x);
        return cntL + cntR;
    }

    int getMax(int i, int l, int r, int u, int v){
        if(v < l || u > r || u > v || l > r) return 0;
        if(l >= u && r <= v) return maxx[i];
        int m = (l + r) >> 1;
        int maxL = getMax(2 * i, l, m, u, v);
        int maxR = getMax(2 * i + 1, m + 1, r, u, v);
        return max(maxL, maxR);
    }

    void update(int x, int d){
        update(1, 1, n, x, d);
    }

    int getMax(int u, int v){
        return getMax(1, 1, n, u, v);
    }
};
SegmentTree tree;

void readfile(){
    freopen("NAUGHTY.INP", "r", stdin);
    freopen("NAUGHTY.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> h[i];
}
void sub1(){
    for(int i = 1; i <= n; i++){
        int ans = 1;
        for(int j = i + 1; j <= n; j++){
            if(h[j] > h[i] + k) break;
            ans++;
        }
        for(int j = i - 1; j >= 1; j--){
            if(h[j] > h[i] + k) break;
            ans++;
        }
        cout << ans << " ";
    }
}
void full(){
    tree = SegmentTree(n);
    for(int i = 1; i <= n; i++)
        tree.update(i, h[i]);

    for(int i = 1; i <= n; i++){
        int ans = 1;
        int l = 1, r = i - 1, head = i + 1, last = n;
        int posL = i, posR = i;
        while(l <= r){
            int m = (l + r) >> 1;
            if(tree.getMax(m, i - 1) <= h[i] + k){
                r = m - 1;
                posL = m;
            } else l = m + 1;
        }
        while(head <= last){
            int m = (last + head) >> 1;
            if(tree.getMax(i + 1, m) <= h[i] + k){
                head = m + 1;
                posR = m;
            } else last = m - 1;
        }
        ans += (i - posL) + (posR - i);
        cout << ans << " ";
    }
}
int32_t main()
{
    FastIO
    readfile();
    if(n <= 1000) sub1();
    else full();
    return 0;
}
