#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define ALL(x) (x).begin(), (x).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 6e5 + 10;
int n, q;
int a[NM];
///------------------------sub12------------------------
int dem[500][500], m[500][500];
///------------------------sub3-------------------------
int tam[NM];
///------------------------full-------------------------
vector<int> pos[NM];
vector<int> val;
int numCnt[25][NM];

void readfile(){
    freopen("DOMINATING.INP", "r", stdin);
    freopen("DOMINATING.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}
void sub12(){
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++) dem[i][j] = 0;
    for(int i = 1; i <= n; i++) val.push_back(a[i]);
    sort(ALL(val));
    val.resize(unique(ALL(val)) - val.begin());
    for(int i = 1; i <= n; i++) a[i] = lower_bound(ALL(val), a[i]) - val.begin() + 1;
    for(int i = 1; i <= val.size(); i++){
        for(int j = 1; j <= n; j++){
            dem[i][j] = dem[i][j - 1] + (i == a[j]);
        }
    }
    for(int l = 1; l <= n; l++){
        for(int r = l; r <= n; r++){
            m[l][r] = -1;
            for(int i = l; i <= r; i++){
                int u = a[i];
                if(2 * (dem[u][r] - dem[u][l - 1]) > r - l + 1){
                    m[l][r] = u;
                    break;
                }
            }
        }
    }

    for(int i = 1; i <= q; i++){
        int u, v; cin >> u >> v;
        if(m[u][v] < 0) cout << -1 << " ";
        else cout << val[m[u][v] - 1] << " ";
    }
}
int findCandidate(int a[], int s){
    int pos = 1, cnt = 1;
    for(int i = 2; i <= s; i++){
        if(a[pos] == a[i]) cnt++;
        else cnt--;
        if(cnt == 0){
            pos = i;
            cnt = 1;
        }
    }
    return a[pos];
}
bool isMajority(int a[], int s, int cand){
    int cnt = 0;
    for(int i = 1; i <= s; i++) if(a[i] == cand) cnt++;
    if(cnt > s / 2) return true;
    else return false;
}
void prinMajority(int a[], int s){
    int cand = findCandidate(a, s);
    if(isMajority(a, s, cand)) cout << cand << " ";
    else cout << -1 << " ";
}
void sub3(){
    for(int sub = 1; sub <= q; sub++){
        memset(tam, 0, (n + 1) * sizeof(int));
        int u, v; cin >> u >> v;
        for(int i = u; i <= v; i++) tam[i - u + 1] = a[i];
        int s = v - u + 1;
        prinMajority(tam, s);
    }
}
int getCnt(int u, int l, int r){
    if(pos[u].empty()) return 0;
    int head = lower_bound(ALL(pos[u]), l) - pos[u].begin();
    int last = upper_bound(ALL(pos[u]), r) - pos[u].begin();
    return last - head;
}
int query(int l, int r){
    int tmp = 0;
    for(int i = 0; i < 20; i++){
        if(2 * (numCnt[i][r] - numCnt[i][l - 1]) > r - l + 1)
            tmp |= MASK(i);
    }
    return (tmp <= val.size() && 2 * getCnt(tmp, l, r) > r - l + 1) ? val[tmp - 1] : -1;
}
void full(){
    for(int i = 1; i <= n; i++) val.push_back(a[i]);
    sort(ALL(val));
    val.resize(unique(ALL(val)) - val.begin());
    for(int i = 1; i <= n; i++) a[i] = lower_bound(ALL(val), a[i]) - val.begin() + 1;
    for(int i = 1; i <= n; i++) pos[a[i]].push_back(i);

    for(int i = 0; i < 20; i++){
        for(int j = 1; j <= n; j++){
            numCnt[i][j] = numCnt[i][j - 1] + BIT(i, a[j]);
        }
    }

    for(int i = 1; i <= q; i++){
        int l, r; cin >> l >> r;
        cout << query(l, r) << " ";
    }
}
int32_t main()
{
    FastIO
    readfile();
    if(n <= 400){sub12(); return 0;}
    if(n <= 5000) {sub3(); return 0;}
    else full();
    ///full();
    return 0;
}
