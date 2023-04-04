#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n;
int res = 0;
int a[NM], d[2];
char s[NM];
string t[2005][2005];
map<string, int> cnt[2005];

void readfile(){
    freopen("RSEQ.INP", "r", stdin);
    freopen("RSEQ.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = a[i] + '0';
    }
}
void sub12(){
    for(int i = 1; i <= n; i++) t[i][0] = "";
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            t[i][j - i + 1] = t[i][j - i] + s[j];
            ///cout << t[i][j - i + 1] << " ";
        }
    }
    int last = -1, head = -1, len = -1;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            cnt[j - i + 1][t[i][j - i + 1]]++;
            if(maximize(res, cnt[j - i + 1][t[i][j - i + 1]])){
                head = i;
                last = j;
                len = j - i + 1;
            } else if(res == cnt[j - i + 1][t[i][j - i + 1]]){
                if(len <= j - i + 1){
                    head = i;
                    last = j;
                    len = j - i + 1;
                }
            }
        }
    }
    cout << head << " " << last;
}
void sub3(){
    int head = -1, last = -1;
    for(int i = 1; i <= n; i++){
        d[a[i]]++;
        if(maximize(res, d[a[i]])) last = i;
    }
    cout << last << " " << last;
}
int main()
{
    FastIO
    readfile();
    if(n <= 2000){
        sub12();
        return 0;
    }
    bool ok = true;
    for(int i = 1; i <= n; i++){
        if(a[i] > 1){
            ok = false;
            break;
        }
    }
    if(ok) sub3();
    else sub12();
    return 0;
}
