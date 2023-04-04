#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int t;
int a[NM], g[100005];

void sub1(){
    g[1] = 0;
    for(int i = 1; i <= NM; i++){
        for(int j = 2; j < 10; j++) if(i * j < NM) {
            g[i] |= !g[(i + j - 1) / j];
        }
    }

    for(int i = 1; i <= t; i++){
        if(g[a[i]]) cout << "La premiere joueuse gagne." << '\n';
        else cout << "La deuxieme joueuse gagne." << '\n';
    }

}
int divide(int x){
    if(x <= 9) return 1;
    int t = (x % 9 == 0 ? x / 9 - 1 : x / 9);
    return 1 + divide(t);
}
void sub2(){
    for(int i = 1; i <= t; i++){
        int cnt = 0;
        while(a[i] > 0){
            cnt++;
            if(a[i] % 9 == 0){

            }
        }
    }
}
int main()
{
    FastIO
    freopen("MULGAME.INP", "r", stdin);
    freopen("MULGAME.OUT", "w", stdout);
    cin >> t;
    for(int i = 1; i <= t; i++) cin >> a[i];

    sub2();
    return 0;
}
