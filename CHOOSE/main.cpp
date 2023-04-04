#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e5 + 10;
int n, k, numCnt = 0;
int a[NM], b[NM];

struct Data {
    int posX, posY, sum;

    bool inline operator < (const Data &A) const {
        return sum > A.sum;
    }
};

void readfile(){
    freopen("CHOOSE.INP", "r", stdin);
    freopen("CHOOSE.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int j = 1; j <= n; j++) cin >> b[j];
}
void sub1(){
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) ans.push_back(a[i] + b[j]);
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < k; i++) cout << ans[i] << " ";
}
void sub2(){
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    priority_queue<Data> pq;
    for(int i = 1; i <= n; i++) pq.push({1, i, a[1] + b[i]});

    while(!pq.empty()){
        int sum = pq.top().sum;
        int x = pq.top().posX;
        int y = pq.top().posY;
        pq.pop();
        cout << sum << " ";
        if(++numCnt >= k) break;
        if(x + 1 <= n) pq.push({x + 1, y, a[x + 1] + b[y]});
    }
}
int32_t main()
{
    FastIO
    readfile();
    sub2();
    return 0;
}
