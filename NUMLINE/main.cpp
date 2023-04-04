#include <bits/stdc++.h>
#define ll long long
#define INF 1e8
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 5e4 + 10;
int T, n;
int a[NM], inc[NM], de[NM], t[NM];
vector<int> val, pos[NM];

void readfile(){
    freopen("DAYSO.INP", "r", stdin);
    freopen("DAYSO.OUT", "w", stdout);
    cin >> T;
}
void xuli(){
    while(T--){
        cin >> n;

        val.clear();
        for(int i = 1; i <= n; i++) pos[i].clear();
        for(int i = 1; i <= n; i++) inc[i] = de[i] = 1;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            val.push_back(a[i]);
        }

        sort(ALL(val));
        val.resize(unique(ALL(val)) - val.begin());
        for(int i = 1; i <= n; i++)
            t[i] = lower_bound(ALL(val), a[i]) - val.begin() + 1;
        for(int i = 1; i <= n; i++) pos[t[i]].push_back(i);

        for(int i = 1; i <= n; i++){
            for(int u : pos[t[i] + 1]){
                if(u > i && a[i] + 1 == a[u])
                    maximize(inc[u], inc[i] + 1);
            }
        }
        for(int i = n; i >= 1; i--){
            for(int u : pos[t[i] + 1]){
                if(u < i && a[i] + 1 == a[u])
                    maximize(de[u], de[i] + 1);
            }
        }

        int res = INF;
        for(int i = 1; i <= n; i++) if(inc[i] > 1 && de[i] > 1) {
            minimize(res, n - (2 * (min(inc[i], de[i])) - 1));
        }
        cout << (res < INF ? res : -1) << '\n';
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
