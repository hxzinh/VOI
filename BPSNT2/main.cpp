#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM =1e6 + 10;
int n, m;
bool isPrime[NM];
vector<int> res;

int main()
{
    FastIO
    cin >> n >> m;

    for(int i = 2; i * i <= m; i++) if(!isPrime[i]) {
        for(int j = i * i; j <= m; j += i) isPrime[i] = true;
        for(int j = i * i; j <= m; j += i * i) if(j >= n) res.push_back(j);
    }
    sort(res.begin(), res.end());
    res.resize(unique(res.begin(), res.end()) - res.begin());

    for(int u : res){
        bool ok = true;
        int tmp = u;
        for(int i = 2; i * i <= u; i++) if(u % i == 0) {
            int cnt = 0;
            while(u % i == 0){
                cnt++;
                u /= i;
            }
            if(cnt < 2){
                ok = false;
                break;
            }
        }
        if(u > 1) ok = false;
        if(ok) cout << tmp << " ";
    }
    return 0;
}
