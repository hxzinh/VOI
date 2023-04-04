#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
#define MASK(x) (1LL << (x))
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 2e3 + 10;
int n;
int a[NM], b[NM], k[NM];
pair<int, int> ranking[NM];

struct Data{
    int score, index;

    bool inline operator < (const Data &a) const{
        return score < a.score;
    }
};
Data pre[NM];

void readfile(){
    freopen("RANKING.INP", "r", stdin);
    freopen("RANKING.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++){
        pre[i].index = i;
        pre[i].score = MASK(a[i]) + MASK(b[i]);
        k[i] = pre[i].score;
    }
}
void xuli(){
    sort(pre + 1, pre + n + 1);
    for(int i = 1; i <= n; i++){
        bool cxL = 1, cxR = 1;
        int head = 1, last = n;
        int best = k[i] + MASK(1), worst = k[i] + MASK(n);
        while(head <= last && (cxL || cxR)){
            if(best <= pre[head].score + MASK(2)) cxL = false;
            else head++;
            if(worst >= pre[last].score + MASK(n - 1)) cxR = false;
            else last--;
        }
        ranking[i].first = pre[head].index;
        ranking[i].second = pre[last].index;
    }
    for(int i = 1; i <= n; i++) cout << pre[i].score << " " << pre[i].index << '\n';
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
