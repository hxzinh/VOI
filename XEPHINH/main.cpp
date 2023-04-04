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

const int NM = 4e5 + 10;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int T;
int f[NM];
char a[10];
map<string, int> Id;

struct Matrix {
    string u;
    int x, y, cost;

    Matrix(string _u = "", int _x = 0, int _y = 0, int _cost = 0){
        u = _u;
        x = _x; y = _y; cost = _cost;
    }
};

bool inMatrix(int x, int y){
    return (x >= 0 && y >= 0 && x < 3 && y < 3);
}
void bfs(){
    memset(f, INF, sizeof f);
    queue<Matrix> q;
    string uu = "012345678";
    q.push({uu, 0, 0, 0});
    f[Id[uu]] = 0;

    while(q.size()){
        string str = q.front().u;
        int x = q.front().x, y = q.front().y, cost = q.front().cost;
        q.pop();

        int curId = x * 3 + y;
        if(f[Id[str]] != cost) continue;

        for(int i = 0; i < 4; i++){
            int u = x + dx[i];
            int v = y + dy[i];
            if(inMatrix(u, v)){
                int newId = u * 3 + v;
                string newStr = str;
                swap(newStr[curId], newStr[newId]);
                if(minimize(f[Id[newStr]], f[Id[str]] + 1)) q.push({newStr, u, v, cost + 1});
            }
        }
    }
}
void xuli(){
    int id = 0;
    for(int i = 0; i < 9; i++) a[i] = char(i + '0');
    do {
        string tmp = "";
        for(int i = 0; i < 9; i++) tmp += a[i];
        Id[tmp] = id;
        id++;

    } while(next_permutation(a, a + 9));

    bfs();

    while(T--){
        string tmp = "";
        for(int i = 0; i < 9; i++){
            char u; cin >> u;
            tmp += u;
        }

        auto it = Id[tmp];
        cout << (f[it] < INF ? f[it] : -1) << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("XEPHINH.INP", "r", stdin);
    freopen("XEPHINH.OUT", "w", stdout);
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
