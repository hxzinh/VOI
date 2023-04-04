#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int NM = 1e6 + 10;
int f[NM], k, n, sz, cnt, t;
char a[NM];
string S;

void backtrack(int u) {
    if(u > n) {
        if(f[0] % 2 == 0 || f[1] % 2 == 0) {
            int s1 = a[1] == S[0], id = 0;
            for(int i = 2 ; i < n ; i++) {
                s1 +=(a[i] == S[0]);
                if(!k || s1 % 2 == 0 ||(i - s1) % 2 == 0) {
                    id++;
                    if(id >= k) {
                        cnt++;
                        if(cnt == t) {
                            for(int i = 1; i <= n; ++i) cout << a[i];
                            exit(0);
                        }
                        return;
                    }
                }
            }
        }
        return;
    }

    a[u] = S[0];
    f[0]++;
    backtrack(u + 1);
    f[0]--;
    f[1]++;
    a[u] = S[1];
    backtrack(u + 1);
    f[1]++;
    return;
}
void Dfs(int u) {
    if(u > n) {
        int s = 0;
        for(int i = 0 ; i < sz ; i++) s+= f[i] % 2;
        if(s <= 1) {
            cnt++;
            if(cnt == t) {
                for(int i = 1; i <= n; i++) cout << a[i];
                exit(0);
            }
        }
        return;
    }

    for(int i = 0 ; i < sz ; i++) {
        f[i]--;
        a[u] = S[i];
        Dfs(u + 1);
        f[i]--;
    }
    return;
}


int main()
{
	FastIO
	freopen("PALIN.INP", "r", stdin);
	freopen("PALIN.OUT", "w", stdout);
    cin >> n >> k >> S;
    sz = S.length();
    cin >> t;

    sort(ALL(S));
    if(sz == 1) return cout<<S,0;

    if(sz <= 10 && sz == 2) backtrack(1);
    else Dfs(1);
	return 0;
}
