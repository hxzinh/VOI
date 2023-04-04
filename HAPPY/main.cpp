#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1LL)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 3e3 + 10;
int n, k;
string s;
int res = 0;

void readfile(){
    freopen("HAPPY.INP", "r", stdin);
    freopen("HAPPY.OUT", "w", stdout);
    cin >> n >> k;
    cin >> s;
}
void backtrack(int mask, int cnt){
    if(cnt > k) return;
    if(cnt == k){
        int ans = 1;
        for(int i = 0; i < s.length(); i++)
            if(BIT(i, mask)){
                ans *= ('z' - s[i]);
                for(int i = 1; i < k; i++) ans *= ('z' - 'a');
            }
        res += ans;
        return;
    }
    for(int i = 0; i < s.length(); i++){
        int newMask = mask | MASK(s.length() - i - 1);
        int u = abs(i - s.size());
        backtrack(newMask, cnt + abs(i - s.length()));
    }
}
void backtrack(int mask, int preMask, int cnt){
    if(cnt > k) return;
    if(cnt == k){
        int ans = 1;
    }
    for(int i = preMask + 1; i < s.size(); i++){
        int newMask = mask | MASK(i);
        backtrack(newMask, i, cnt + (s.size() - preMask));
    }
}
void sub12(){
    backtrack(0, 0);
    cout << res;
}
void sub4(){
    int res = 1;
    for(int i = 0; i < s.length(); i++){
        res *= (s[i] - 'a' + 1);
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    if(k == 0) sub12();
    else cout << 0;
    return 0;
}
