#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int MOD = 1e9 + 9;
const int NM = 3e5 + 10;
int n;
int cnt[30], f[NM];
string  a;
///---------------------------sub12---------------------------------
int maxCnt;
bool ok[7005][7005];
///---------------------------sub3----------------------------------
int s[NM], sumF[2 * NM];
///---------------------------sub4----------------------------------
int getCnt[30][NM];
vector<int> pos[26];

struct FenwickTree{
    vector<int> v;
    int n;

    FenwickTree(int _n = 0){
        n = _n;
        v.assign(n + 7, 0);
    }

    void update(int x, int d){
        for(; x <= n; x += x & -x) add(v[x], d);
    }

    int getNum(int x) const {
        int res = 0;
        for(; x <= n; x &= x - 1) add(res, v[x]);
        return res;
    }
};
FenwickTree tree[26];

void subt(int &a, int b){
    a -= b;
    if(a < 0) a += MOD;
}
void add(int &a, int b){
    a = (a % MOD + b % MOD) % MOD;
    return;
}
void maximize(int &a, int b){
    if(a < b){a = b; return;}
    else return;
}
void readfile(){
    freopen("TOURGUIDE.INP", "r", stdin);
    freopen("TOURGUIDE.OUT", "w", stdout);
    cin >> a;
    n = a.length();
}
void sub12(){
    for(int l = 1; l <= n; l++){
        memset(cnt, 0, sizeof(cnt));
        maxCnt = 0;
        for(int r = l; r <= n; r++){
            maximize(maxCnt, ++cnt[a[r - 1] - 'a']);
            ok[l][r] = 2 * maxCnt <= r - l + 1;
        }
    }

    f[0] = 1;
    for(int i = 0; i < n; i++) if(f[i] > 0){
        for(int j =1; j <= n; j++) {
            if(ok[i + 1][j]) add(f[j], f[i]);
        }
    }
    cout << f[n];
}
void sub3(){
    for(int i = 1; i <= n; i++){
        s[i] = s[i - 1] + (a[i - 1] == 'a' ? -1 : 1);
    }

    f[0] = 1;
    sumF[s[0] + NM] = 1;
    for(int i = 1; i <= n; i++){
        f[i] = sumF[s[i] + NM];
        add(sumF[s[i] + NM], f[i]);
    }
    cout << f[n];
}
void sub4(){
    for(int i = 0; i < 26; i++)
        for(int j = 1; j <= n; j++) getCnt[i][j] = cnt[i][j - 1] + (a[j] == i + 'a');

}
int main()
{
    FastIO
    readfile();
    if(n <= 7000) sub12();
    else sub3();
    return 0;
}
