#include <bits/stdc++.h>
#define int long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e5 + 10;
int n, k;
int a[NM], b[NM];
vector<int> sum;

void readfile(){
    freopen("KTHSUM.INP", "r", stdin);
    freopen("KTHSUM.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
}
void sub1(){
    vector<int> s;
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            s.push_back(a[i] + b[j]);
        }
    sort(s.begin(), s.end());
    for(int u : s) {
        cout << u << " ";
        if(++cnt == k) break;
    }
}
int32_t main()
{
    FastIO
    readfile();
    sub1();
    return 0;
}
