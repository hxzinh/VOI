#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e5 + 10;
int n, T, x;
int a[NM];
bool cx[NM];

void readfile(){
    freopen("MEDPYRE.INP", "r", stdin);
    freopen("MEDPYRE.OUT", "w", stdout);
    cin >> n >> x;
}
void xuli(){
    if(x == 2 * n - 1 || x == 1){
        cout << "No";
        return;
    }

    if(n == 1){
        cout << "Yes" << '\n';
        cout << x;
        return;
    }

    if(n == 2){
        cout << "Yes" << '\n';
        cout << x - 1 << '\n' << x << '\n' << x + 1;
        return;
    }

    a[n] = x;
    a[n + 1] = x + 1;
    a[n + 2] = x - 1;
    a[n - 1] = 1;
    cx[x] = cx[x + 1] = cx[x - 1] = cx[1] = true;

    int cnt = 2 * n - 1;
    for(int i = 1; i <= 2 * n - 1; i++) if(a[i] == 0){
        while(cx[cnt]) cnt--;
        a[i] = cnt;
        cnt--;
    }

    cout << "Yes" << '\n';
    for(int i = 1; i <= 2 * n - 1; i++) cout << a[i] << '\n';
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
