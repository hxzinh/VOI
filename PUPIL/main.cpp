#include <bits/stdc++.h>
#define int long long
#define ll long long
#define oo INFINITY
#define MASK(x) (1LL << (x))
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 4e5 + 10;
const int LOG = 19;
int numStore, limit, start, posSchool;
int T[NM]; /// so tra sua mua o qua i
int m[NM][LOG + 1]; /// so nho nhat trong doan l....r
int lg[NM];

struct Data{
    int pos, cost, index;

    bool inline operator < (Data &A) const {
        return pos < A.pos;
    }

};
Data a[NM];

void readfile(){
    freopen("PUPIL.INP","r",stdin);
    freopen("PUPIL.OUT","w",stdout);
    cin >> posSchool >> limit >> numStore >> start;
    for(int i = 1; i <= numStore; i++){
        cin >> a[i].pos >> a[i].cost;
        a[i].index = i;
    }
}
void RMQ(){
    for(int i = 1; i <= numStore; i++) m[i][0] = i;
    for(int j = 1; j <= LOG; j++){
        for(int i = 1; i <= numStore - MASK(j) + 1; i++){
            int pos1 = m[i][j - 1];
            int pos2 = m[i + MASK(j - 1)][j - 1];
            if(a[pos1].cost < a[pos2].cost){
                m[i][j] =pos1;
            } else m[i][j] = pos2;
        }
    }
    for(int i = 1; i <= numStore; i++){
        while(MASK(lg[i]) <= i) lg[i]++;
        lg[i]--;
    }
}
int getMin(int l,int r){
    int k = lg[r - l + 1];
    int pos1 = m[l][k], pos2 = m[r - MASK(k) + 1][k];
    if(a[pos1].cost < a[pos2].cost) return pos1;
    else return pos2;
}
pair<ll, int> dp(int l,int r,int start){
    if(l == r) return make_pair(0, start);
    if(r - l == 1) return make_pair(0, start - (a[r].pos - a[l].pos));
    int m = getMin(l + 1, r - 1);
    pair<ll, int> before = dp(l, m, start);
    int need = min(limit, a[r].pos - a[m].pos);
    int buy = max(0 * 1LL, need - before.second);
    T[a[m].index] = buy;
    pair<ll, int> after = dp(m, r, before.second + buy);
    return make_pair(before.first + buy * a[m].cost + after.first, after.second);
}
void xuli(){
    sort(a + 1, a + numStore + 1);
    RMQ();
    a[0].pos = 0; a[0].cost = 0;
    a[numStore + 1].pos = posSchool; a[numStore + 1].cost = 0;
    for(int i = 1; i <= numStore + 1; i++){
        if(a[i].pos - a[i - 1].pos > limit){cout << -1; return;}
    }
    if(start < a[1].pos - a[0].pos) {cout << -1; return;}
    cout << dp(0, numStore + 1, start).first << '\n';
    for(int i = 1; i <= numStore; i++) cout << T[i] << " ";
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
