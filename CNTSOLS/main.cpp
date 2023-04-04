#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int n, m, U, T, d;

void readfile(){
    freopen("CNTSOLS.INP", "r", stdin);
    freopen("CNTSOLS.OUT", "w", stdout);
    cin >> T;
    cin >> U >> d >> m >> n;
}
void getAns(int x, int d){
    if(d == 0) return 1;
    int tmp = getAns(x, d / 2);
    tmp = (tmp * tmp) % n;
    if(d % 2 == 0) tmp = (tmp * x) % n;
    return tmp;
}
void xuli(){
    cout << getAns(U, d);
}
int main()
{
    FastIO
    readfile();
    while(T--){
        cin >> U >> d >> m >> n;
        xuli();
    }
    return 0;
}
