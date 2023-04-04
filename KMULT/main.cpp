#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e4 + 10;
int n, k;
int ans = 0;
int a[NM];
vector<char> trace, t;

void readfile(){
    freopen("KMULT.INP", "r", stdin);
    freopen("KMULT.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void backtrack(int x, int sum){
    if(x > n){
        if(sum % k == 0){
            ans = 1;
            cout << ans << '\n';
            for(char u : trace) cout << u;
            exit(0);
        }
        return;
    }
    trace.push_back('+');
    backtrack(x + 1, sum + a[x]);
    trace.pop_back();
    trace.push_back('-');
    backtrack(x + 1, sum - a[x]);
    trace.pop_back();
    return;
}
void sub1(){
    backtrack(2, a[1]);
    if(!ans) cout << ans;
}
void sub2(){

}
int main()
{
    FastIO
    readfile();
    sub1();
    return 0;
}
