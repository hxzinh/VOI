#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e4 + 10;
int n;
int f[NM], ans[NM];
bool cx[NM], ok[NM];
map<string, int> m;
map<string, bool> chek;

struct Data {
    string pass;
    int pos;
};
Data a[NM];
string s[NM];

void readfile(){
    freopen("PASSWORD.INP", "r", stdin);
    freopen("PASSWORD.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        a[i].pos = i;
        a[i].pass = s[i];
    }
}
void sub1(){
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++) if(i != j) {
            if(a[i].pass.find(a[j].pass) != -1) cnt++;
        }
        cout << cnt << '\n';
    }
}
bool cmp(const Data &A, const Data &B){
    return (A.pass.length() == B.pass.length() ? A.pass > B.pass : A.pass.length() > B.pass.length());
}
int dp(int x){
    if(x > n) return 0;
    int &res = f[x];
    cx[x] = false;
    if(res != 0) return res;
    for(int i = x + 1; i <= n; i++) if(cx[i] && ok[i]) {
        if(a[x].pass.find(a[i].pass) != -1) res += dp(i) + 1;
    }
    return res;
}
void sub2(){
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++){
        string tam = "" + s[i];
        m[tam]++;
    }
    for(int i = 1; i <= n; i++){
        int res = 0;
        for(int j = 0; j < s[i].length(); j++){
            string tamm = "";
            tamm += s[i][j];
            if(!chek[tamm]) res += m[tamm], chek[tamm] = true;

            for(int v = j + 1; v < s[i].length(); v++){
                tamm += s[i][v];
                if(!chek[tamm]) res += m[tamm], chek[tamm] = true;
            }
        }
        for(int j = 0; j < s[i].length(); j++){
            string tamm = "";
            tamm += s[i][j];
            chek[tamm] = false;
            for(int v = j + 1; v < s[i].length(); v++){
                tamm += s[i][v];
                chek[tamm] = false;
            }
        }
        cout << res - 1 << '\n';
    }
}
int32_t main()
{
    FastIO
    readfile();
    if(n <= 1000) sub1();
    else sub2();
    return 0;
}
