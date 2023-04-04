#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
const int MOD = 123456789;
int T, n, k;
int a[NM];
vector<int> val, pos, neg;

void readfile(){
    freopen("PRODUCT.INP", "r", stdin);
    freopen("PRODUCT.OUT", "w", stdout);
    cin >> T;
}
void xuli(){
    while(T--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> a[i];

        sort(a + 1, a + n + 1);

        int head = 1, last = n, res = 1, cnt = 0;
        if(k % 2 == 0){
            while(cnt < k){
                if(a[head] * a[head + 1] >= a[last] * a[last - 1] && head < last){
                    res = (res * (a[head] * a[head + 1] % MOD)) % MOD;
                    head += 2;
                } else {
                    res = (res * (a[last] * a[last - 1] % MOD)) % MOD;
                    last -= 2;
                }
                cnt += 2;
            }
        } else {
            bool ok = false;
            for(int i = 1; i <= n; i++) if(a[i] >= 0) ok = true;
            if(ok){
                res = res * a[last];
                last--;
                cnt++;
                while(cnt < k){
                    if(a[head] * a[head + 1] >= a[last] * a[last - 1] && head < last){
                        res = (res * (a[head] * a[head + 1] % MOD)) % MOD;
                        head += 2;
                    } else {
                        res = (res * (a[last] * a[last - 1] % MOD)) % MOD;
                        last -= 2;
                    }
                    cnt += 2;
                }
            } else {
                for(int i = n - k + 1; i <= n; i++) res = (res * a[i]) % MOD;
            }
        }
        cout << (res >= 0 ? res : MOD + res) << '\n';
    }
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
