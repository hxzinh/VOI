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
int n;
int a[NM];
double s[NM];

void sub12(){
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    double res = INF;
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j < n; j++){
            double tmp = s[n] - s[j] + s[j - i];
            if(res > tmp / ((n - i) * 1.00)) res = tmp / ((n - i) * 1.00);
        }
    }
    cout << setprecision(3) << fixed << res;
}
int main()
{
    FastIO
    freopen("RAID.INP", "r", stdin);
    freopen("RAID.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    sub12();
    return 0;
}
