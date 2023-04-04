#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 105;
int n;
int res = -1;
int a[NM];
string s[NM];

vector<string> name[1005];

void readfile(){
    freopen("7-DWARFS.INP", "r", stdin);
    freopen("7-DWARFS.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s[i] >> a[i];
        name[a[i]].push_back(s[i]);
    }
}
bool tmp(string u, string b){
    return u < b;
}
void xuli(){
    for(int i = 1; i <= 1000; i++)
         if(name[i].size() == 7){res = i; break;}
    sort(ALL(name[res]), tmp);
    for(string u : name[res]) cout << u << " ";
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
