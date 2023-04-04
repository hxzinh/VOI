#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
const int MAX = 105;
int n;
int a[NM];
bool ok1[MAX], ok2[MAX][MAX], ok3[MAX][MAX][MAX];

void xuli(){
    memset(ok1, false, sizeof ok1);
    memset(ok2, false, sizeof ok2);
    memset(ok3, false, sizeof ok3);
    for(int i = 1; i <= 100; i++){
        for(int j = i + 1; j <= min(i + 10, 100); j++){
            for(int k = j + 1; k <= min(j + 10, 100); k++){
                for(int h = k + 1; h <= min(k + 10, 100); h++){
                    ok1[i] = ok1[j] = ok1[k] = ok1[h] = true;
                    ok2[i][j] = ok2[i][k] = ok2[i][h] = true;
                    ok2[j][k] = ok2[j][h] = true;
                    ok2[k][h] = true;
                    ok3[i][j][k] = ok3[i][j][h] = ok3[i][k][h] = ok3[j][k][h] = true;
                }
            }
        }
    }
}
int32_t main()
{
    FastIO
    freopen("PROBLEMSET.INP", "r", stdin);
    freopen("PROBLEMSET.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    return 0;
}
