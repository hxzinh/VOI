#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e5 + 10;
int n;
int maxL = 0, posMax = -1, sum = 0;
int a[NM], h[NM];
bool ok[NM];
vector<int> check;

struct FenwickTree{
    int n;
    vector<int> v;

    FenwickTree(int _n = 0){
        n = _n;
        v.assign(n + 7, 0);
    }

    void update(int x){
        for(; x >= 1; x -= x & -x) v[x]++;
    }

    int getRes(int x) const {
        int res = 0;
        for(; x <= n; x += x & -x) res += v[x];
        return res;
    }
};
FenwickTree tree;

void readfile(){
    freopen("PSWAP.INP", "r", stdin);
    freopen("PSWAP.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        h[i] = abs(a[i] - i);
        if(abs(h[i]) > maxL){
            check.clear();
            check.push_back(i);
            maxL = abs(h[i]);
        } else if(abs(h[i]) == maxL) check.push_back(i);
    }
    memset(ok, false, sizeof(ok));
}
void sub1(){
    if(a[1] == 1){
        if(a[2] == 2) cout << 0;
        else cout << 1;
        return;
    }
    if(a[1] == 2){
        if(a[2] == 3) cout << 2;
        else cout << 1;
        return;
    }
    if(a[1] == 3){
        if(a[2] == 1) cout << 2;
        else cout << 1;
        return;
    }
}
void xuli(){
    int ChangePos = 0, res = 1, k = 0;
    for(int i = 1; i <= n; i++) sum += h[i];

    int Change = 0, posChange = -1, curSum = sum;
    for(int pos : check){
        int newSum = sum;
        for(int i = 1; i <= n; i++){
            if(a[i] == a[pos]) continue;
            newSum = sum - h[pos] -  h[i] + abs(a[i] - pos) + abs(a[pos] - i);
            if(newSum < curSum){
                Change = i;
                posChange = pos;
                curSum = newSum;
            }
        }
    }
    swap(a[Change], a[posChange]);
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << '\n';

    tree = FenwickTree(n);
    for(int i = 1; i <= n; i++){
        res += tree.getRes(a[i] + 1);
        tree.update(a[i]);
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    if(n == 3) sub1();
    else xuli();
    return 0;
}

