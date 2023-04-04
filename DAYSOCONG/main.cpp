#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int n;
bool cx[100000005];
vector<int> ds;

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n;
    memset(cx, true, sizeof(cx));
}
void sub1(){
    int cnt = 0;
    ds.push_back(0);
    cx[0] = false;
    while(cnt < n){
        int tam = ds[cnt];
        for(int i = 0; i < ds.size(); i++) cx[2 * tam - ds[i]] = false;
        while(!cx[tam]) tam++;
        ds.push_back(tam);
        cnt++;
    }
    cout << ds[cnt];
}
void sub2(){
    int res = 0, cnt = 0;
    while(n != 0){
        if(n % 2 != 0){
            res += pow(3, cnt);
            n = (n - 1) / 2;
        } else n /= 2;
        cnt++;
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    sub2();
    return 0;
}
