#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 3e5 + 10;
int n, k;
string s[NM];
pair<string, int> p[NM];
map<string, int> cnt;

struct Data {
    string str;
    int pos, cnt;

    bool inline operator < (const Data &A) const {
        return (cnt == A.cnt ? pos > A.pos : cnt > A.cnt);
    }
};
Data a[NM];

void readfile(){
    freopen("GRATITUDE.INP", "r", stdin);
    freopen("GRATITUDE.OUT", "w", stdout);
    cin >> n >> k;
    getline(cin, s[0]);
    for(int i = 1; i <= 3 * n; i++){
        getline(cin, s[i]);
        p[i].fi = s[i];
        p[i].se = i;
    }
}
bool cmp(pair<string, int> a, pair<string, int> b){
    return a.fi < b.fi;
}
void xuli(){
    sort(p + 1, p + 3 * n + 1);
    int i = 1, dem = 0;
    while(i <= 3 * n){
        int tmp = i;
        dem++;
        a[dem].str = p[i].fi;
        a[dem].pos = p[i].se;
        while(p[tmp].fi == p[i].fi){
            a[dem].cnt++;
            a[dem].pos = p[i].se;
            i++;
        }
    }
    sort(a + 1, a + dem + 1);
    for(int i = 1; i <= k; i++) cout << a[i].str << '\n';
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
