#include    <bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define __unique(V) (V).resize(unique((V).begin(),(V).end())-(V).begin())
#define cntbit(X)   __builtin_popcount((X))
#define bit(S,i) (((S)>>(i))&1)
#define PI	acos(-1)
#define fi  first
#define se  second
#define LL  long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define eb  emplace_back
#define TASK "pertab"
using namespace std;
const int maxn = 1e3 + 5;
int a[maxn][maxn],b[maxn][maxn],n,m;
struct data{
    int x[3];
    data(){
        memset(x,0,sizeof(x));
    }
    data(int _x,int _y,int _z){
        x[0] = _x; x[1] = _y; x[2] = _z;
    }
    friend data operator + (data A,data B){
        data C;
        for(int i = 0; i < 3; ++i) C.x[i] = (A.x[i] + B.x[i]+ n) % n;
        return C;
    }
    friend data operator * (int k, data A) {
        data C;
        for(int i = 0; i < 3; ++i) C.x[i] = k * A.x[i]% n;
        return C;
    }
    friend bool operator == (data A,data B){
        for(int i = 0; i < 3; ++i) if (A.x[i] != B.x[i]) return 0;
        return 1;
    }
}R,S[3];
string s;
///--------------------------
void    readf(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j){
        cin >> a[i][j];
        a[i][j]--;
    }
    cin >> s;
    R = data(0,0,0);
    S[0] = data(1,0,0);
    S[1] = data(0,1,0);
    S[2] = data(0,0,1);
}
///--------------------------
void    solve(){
    for(int t = 0; t < s.size(); ++t){
        char ch = s[t];
        if (ch == 'R') R = R + data(0,1,0);
        if (ch == 'L') R = R + data(0,-1,0);
        if (ch == 'D') R = R + data(1,0,0);
        if (ch == 'U') R = R + data(-1,0,0);
        if (ch == 'I'){
            swap(R.x[1],R.x[2]);
            for(int i = 0; i < 3; ++i)
                for(int j = 0; j < 3; ++j)
                    if (S[i] == data(0,1,0) && S[j] == data(0,0,1)){
                        swap(S[i],S[j]);
                        goto nxt;
                    }
            nxt : ;
        }
        if (ch == 'C'){
            swap(R.x[0],R.x[2]);
            for(int i = 0; i < 3; ++i)
                for(int j = 0; j < 3; ++j)
                    if (S[i] == data(1,0,0) && S[j] == data(0,0,1)){
                        swap(S[i],S[j]);
                        goto nxt2;
                    }
            nxt2 : ;
        }
    }
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j){
        int k = a[i][j];
        data T = R + i * S[0] + j * S[1] + k * S[2];
        b[T.x[0]][T.x[1]] = T.x[2];
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << b[i][j] + 1 <<' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
///--------------------------
int     main(){
	srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
        freopen("pertab.inp", "r", stdin);
        freopen("pertab.out", "w", stdout);
    readf();
    solve();
}
