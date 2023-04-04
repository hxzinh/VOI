#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int n, x;
int a[100005], cnt[200005];

int main()
{
    FastIO
    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }

    for(int i = 1; i <= n; i++){
        if(cnt[a[i] + x]){
            cout << 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
