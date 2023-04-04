#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 3e6 + 10;
const int MOD = 1e9 + 7;
const int BASE = 256;
string s, t;
int pw[NM], HashS[NM], HashT[NM];
char ans[NM];

void sub1(){
    int pos = s.find(t);
    while(pos >= 0 && pos < s.size()){
        s.erase(pos, t.length());
        pos = s.find(t);
    }
    cout << (s == "" ? "miss you baby" : s);
}
int getHashS(int l, int r){
    return 1LL * (HashS[r] - HashS[l - 1] + MOD) * pw[NM - r] % MOD;
}
void prepare(){
    pw[0] = 1;
    s = ' ' + s;
    t = ' ' + t;
    for(int i = 1; i < NM; i++) pw[i] = (pw[i - 1] * BASE) % MOD;
    for(int i = 1; i < s.size(); i++) HashS[i] = (HashS[i - 1] + 1LL * s[i] * pw[i]) % MOD;
    for(int i = 1; i < t.size(); i++) HashT[i] = (HashT[i - 1] + 1LL * t[i] * pw[i]) % MOD;
}
void xuli(){
    prepare();
    int len = t.size() - 1;
    int T = 1LL * (HashT[len] - HashT[0] + MOD) * pw[NM - len] % MOD;

    int cnt = 0;
    for(int i = 1; i < s.size(); i++){
        cnt++;
        ans[cnt] = s[i];
        HashS[cnt] = (HashS[cnt - 1] + 1LL * s[i] * pw[cnt]) % MOD;
        int curHash;
        if(cnt >= len){
            curHash = getHashS(cnt - len + 1, cnt);
            if(curHash == T) cnt -= len;
        }
    }
    for(int i = 1; i <= cnt; i++) cout << ans[i];
    if(!cnt) cout << "miss you baby";
}
int32_t main()
{
    FastIO
    freopen("DELNYC.INP", "r", stdin);
    freopen("DELNYC.OUT", "w", stdout);
    cin >> s >> t;

    xuli();
    return 0;
}
