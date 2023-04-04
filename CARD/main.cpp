#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 125;
string dx[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
string dy[] = {"P", "C", "T", "H"};
int n, T;
map<string, string> mp, id;
map<char, string> save;
char a[10];
string b[10];

struct Data {
    string u;
    int id;
} g[10];

void init(){
    for(int i = 0; i < 5; i++) a[i] = char(i + 'a');

    int u = 0, v = 0, step = 0;
    do {
        if(++step > 52) break;
        string tmp = "";
        for(int i = 0; i < 5; i++) tmp += a[i];
        mp[tmp] = "" + dx[u] + dy[v];
        id["" + dx[u] + dy[v]] = tmp;
        if(++v >= 4){v = 0; u++;}
    } while(next_permutation(a, a + 5));
}
bool cmp(const string A, const string B){
    return A < B;
}
bool cmp2(const Data A, const Data B){
    return A.u < B.u;
}
bool cmpId(const Data A, const Data B){
    return A.id < B.id;
}
void xuli(){
    init();

    while(T--){
        string type, u1, u2, u3, u4, u5, u6;
        cin >> type;
        if(type == "AN"){
            for(int i = 0; i < 6; i++) cin >> b[i];
            sort(b, b + 6, cmp);
            string cur = id[b[5]];
            for(int i = 0; i < cur.size(); i++) cout << b[int(cur[i] - 'a')] << " ";
            cout << endl;
        } else {
            for(int i = 0; i < 5; i++) {
                cin >> b[i];
                g[i] = {b[i], i};
            }
            sort(g, g + 5, cmp2);
            for(int i = 0; i < 5; i++) g[i].u = (i + 'a');
            sort(g, g + 5, cmpId);

            string tmp = "";
            for(int i = 0; i < 5; i++) tmp += g[i].u;
            cout << mp[tmp] << endl;
        }
    }
}
int32_t main()
{
    FastIO
    freopen("CARD.INP", "r", stdin);
    freopen("CARD.OUT", "w", stdout);
    cin >> T;

    xuli();
    return 0;
}

/* Author: hxzinh */

/*
-----code ko bug-----code ko bug-----code ko bug--------------

          _.-/`)
         // / / )
      .=// / / / )
     //`/ / / / /
    // /     ` /
   ||         /
    \\       /
     ))    .'
    //    /
         /
*/
