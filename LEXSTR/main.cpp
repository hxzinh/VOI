#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e3 + 10;
int n;
string s;
map<char, int> cnt, d;
queue<char> q;

void xuli(){
    for(int i = 1; i <= n; i++) if(s[i] != '?') {
        if(cnt[s[i]] > d[s[i]]){
            cout << -1;
            return;
        }
    }

    for(char i = 'a'; i <= 'z'; i++){
        d[i] -= cnt[i];
        if(d[i] > 0) q.push(i);
    }

    for(int i = 1; i <= n; i++) if(s[i] == '?') {
        char u = q.front();
        d[u]--;
        s[i] = u;
        if(!d[u]) q.pop();
    }

    cout << s.substr(1, n);
}
int main()
{
    FastIO
    freopen("LEXSTR.INP", "r", stdin);
    freopen("LEXSTR.OUT", "w", stdout);
    cin >> n >> s;
    s = '#' + s;
    for(int i = 1; i <= n; i++) cnt[s[i]]++;
    for(char i = 'a'; i <= 'z'; i++){
        int u; cin >> u;
        d[i] = u;
    }

    xuli();
    return 0;
}
