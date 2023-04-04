#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int n;
int a[100005];
vector<int> t;

int main()
{
    FastIO
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        t.push_back(a[i]);
    }
    sort(t.begin(), t.end());

    for(int i = 1; i <= n; i++){
        auto it = upper_bound(t.begin(), t.end(), a[i]);
        if(it != t.end()) cout << *it << " ";
        else cout << "_" << " ";
    }
    return 0;
}
