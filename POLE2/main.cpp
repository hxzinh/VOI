#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 4e3 + 10;
int n, d;
int result = 0, Hmax = 0;
int h[NM], cost[NM], f[NM][2 * NM];

void backtrack(int x, int preH, int sum){
    if(x > n){
        minimize(result, sum);
        return;
    }
    if(h[x] - preH > d) return;
    for(int newH = h[x]; newH <= preH + d; newH++){
        int newSum = sum + abs(newH - preH) * cost[x - 1] + (newH - h[x]) * (newH - h[x]);
        backtrack(x + 1, newH, newSum);
    }
    return;
}
void sub1(){
    for(int i = 1; i <= n; i++) result += abs(h[i] - h[i + 1]) * cost[i];
    backtrack(1, 0, 0);
    cout << result;
}
int main()
{
    FastIO
    freopen("POLE2.INP", "r", stdin);
    freopen("POLE2.OUT", "w", stdout);
    cin >> n >> d;
    for(int i = 1; i < n; i++) cin >> cost[i];
    for(int i = 1; i <= n; i++) cin >> h[i];

    sub1();
    return 0;
}
