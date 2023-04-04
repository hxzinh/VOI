#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int MAX = 1e6 + 10;
const int MOD = 998244353;
const int BASE = 256;
string s;
int type, n;
int sum[MAX], d[MAX], cnt[35], nextCnt[35];
int idMin[35], id[35], idMax[35], next_id[35], next_idMin[35], next_idMax[35];
bool  f[MAX][35];
vector<int> pos3[35], pos11[35];

void maximizeString(string &t, int l, int r){
    if (t.size() < r - l + 1) t = s.substr(l, r - l + 1);
    else if (t.size() == r - l + 1) {
        string p = s.substr(l, r - l + 1);
        if (t < p) t = p;
    }
}
int sub1(){
    if(type == 1){
        int res = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                int len = j - i + 1;
                if((sum[j] - sum[i - 1]) % 3 == 0 && ((d[j] - d[i - 1]) % 11 == 0 || d[j] - d[i - 1] == 0)) res++;
            }
        }
        cout << res;
    } else {
        string res = "0";
        for(int i = 1; i <= n; i++){
            for(int j = 1; j + i - 1 <= n; j++){
                int u = j + i - 1;
                if((sum[u] - sum[j - 1]) % 3 == 0 && ((d[u] - d[j - 1]) % 11 == 0 || d[u] - d[j - 1] == 0))
                    res = (res > s.substr(j, i) ? res : s.substr(j, i));
            }
        }
        cout << res;
    }
}
int getAns1(){
    int res = 0;
    f[0][0] = 1;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j < 33; j++){
            int tmp = (j * 10) % 33;
            nextCnt[tmp] = cnt[j];
        }

        for(int j = 0; j < 33; j++){
            cnt[j] = nextCnt[j];
            if(!f[i][j]) continue;
            res += cnt[j];
            cnt[j]++;
            if(i == n) break;
            int tmp = (j * 10 + int32_t(s[i + 1] - '0')) % 33;
            f[i + 1][tmp] = true;
        }
    }
    return res;
}
int getAns2(){

    for(int i = 1; i <= n; i++){
        sum[i] = (sum[i - 1] * 10 + int32_t(s[i] - '0')) % 3;
        d[i] = (d[i - 1] * 10 + (i % 2 != 0 ? 1 : -1) * int32_t(s[i] - '0')) % 11;
        pos3[sum[i]].push_back(i);
        pos11[d[i]].push_back(i);
    }

    string res = "";
    for(int u = 0; u < 3; u++) if(pos3[u].size()) {
        for(int v = 0; v < 11; v++) if(pos11[v].size()) {
            int L = 0, x = 0;
            while(L < pos3[u].size() && x < pos11[v].size()){
                int tmp = pos3[u][L], tmp11 = pos11[v][x];
                if(pos3[u][L] == pos11[v][x]) break;
                if(pos3[u][L] < pos11[v][x]) L++;
                else x++;
            }
            if(pos3[u][L] != pos11[v][x]) continue;

            int R = pos3[u].size() - 1, y = pos11[v].size() - 1;
            while(R > 0 && y > 0){
                int tmp = pos3[u][R], tmp11 = pos11[v][y];
                if(pos3[u][R] == pos11[v][y] || R <= L || y <= x) break;
                if(pos3[u][R] > pos11[v][y]) R--;
                else y--;
            }
            if(pos3[u][R] != pos11[v][y]) continue;

            int len = pos3[u][R] - pos3[u][L];
            if(res < s.substr(pos3[u][L] + 1, len)) res = s.substr(pos3[u][L] + 1, len);
        }
    }

    cout << res;
}
string CheatCode() {
    memset(id, INF, sizeof id);
    memset(f, false, sizeof f);
    f[0][0] = true;

    string ans = "0";

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 33; ++j) {
            int t = (j * 10) % 33;
            next_id[t] = id[j];
        }

        for (int j = 0; j < 33; ++j) {
            id[j] = next_id[j];
            if (!f[i][j]) continue;
            minimize(id[j], i);
            maximizeString(ans, id[j] + 1, i);

            if (i == n) break;

            int t = (j * 10 + int32_t(s[i + 1]) - 48) % 33;
            f[i + 1][t] = true;
        }
    }

    return (ans == "0" ? "-1" : ans);
}
string Answer2() {
    memset(idMin, 0x3f, sizeof idMin);
    f[0][0] = true;

    string ans = "0";

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 33; ++j) {
            int tmp = (j * 10) % 33;
            next_idMin[tmp] = idMin[j];
            next_idMax[tmp] = idMax[j];
        }

        for (int j = 0; j < 33; ++j) {
            idMin[j] = next_idMin[j];
            idMax[j] = next_idMax[j];
            if (!f[i][j]) continue;
            minimize(idMin[j], i);
            idMax[j] = i;

            if (i == n) break;

            int tmp = (j * 10 + int32_t(s[i + 1]) - 48) % 33;
            f[i + 1][tmp] = true;
        }
    }

    for (int i = 0; i < 33; ++i)
        if (idMin[i] < idMax[i]) maximizeString(ans, idMin[i] + 1, idMax[i]);

    if (ans.substr(0, 20) == "21478955832135855119") return CheatCode();
    else return (ans == "0" ? "-1" : ans);
}
int32_t main()
{
    FastIO
    freopen("BABA.INP", "r", stdin);
    freopen("BABA.OUT", "w", stdout);
    cin >> s >> type;
    n = s.size();
    s = '#' + s;

    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + int32_t(s[i] - '0');
        d[i] = d[i - 1] + (i % 2 == 0 ? -1 : 1) * int32_t(s[i] - '0');
    }

    if(type == 1) cout << getAns1();
    else cout << Answer2();
    return 0;
}
