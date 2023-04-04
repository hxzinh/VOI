#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int k;

void readfile(){
    freopen("GAME.INP", "r", stdin);
    freopen("GAME.OUT", "w", stdout);
    cin >> k;
}
void xuli(){
    int fi = 1, last = 1, h = 1;
    while(last < k){
        last += ++h;
        fi = last - h + 1;
    }
    char u, v;
    int res = k;
    while(cin >> u >> v){
        if(u == 'E' && v == 'T'){
            int cur = k + 1;
            if(cur > last) continue;
            k = cur;
            res += k;
        }
        if(u == 'W' && v == 'T'){
            int cur = k - 1;
            if(cur < fi) continue;
            k = cur;
            res += k;
        }
        if(u == 'S' && v == 'E'){
            h++;
            last += h;
            fi += h - 1;
            k = k + h;
            res += k;
        }
        if(u == 'S' && v == 'W'){
            h++;
            last += h;
            fi += h - 1;
            k = k + h - 1;
            res += k;
        }
        if(u == 'N' && v == 'E'){
            int newH = h - 1;
            int newLast = last - h;
            int cur = k - newH;
            if(cur > newLast || newH < 1) continue;
            k = cur;
            h = newH;
            last = newLast;
            fi -= h;
            res += k;
        }
        if(u == 'N' && v == 'W'){
            int newH = h - 1;
            int newFi = fi - newH;
            int cur = k - h;
            if(cur < newFi || newH < 1) continue;
            k = cur;
            last -= h;
            h = newH;
            fi = newFi;
            res += k;
        }
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
