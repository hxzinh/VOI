#include <bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e3 + 10;
int n;
string a[NM];
map<string, int> s;
vector<string> res;

void readfile(){
    freopen("CHECKMA.INP", "r", stdin);
    freopen("CHECKMA.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

}
void backtrack(string ans, int x){
    if(x >= 500) return;
    for(int i = 1; i <= n; i++){
        if(x + a[i].size() > 10) return;
        string newAns = ans + a[i];
        s[newAns]++;
        res.push_back(newAns);
        backtrack(newAns, x + a[i].length());
    }
}
bool tmp(const string &A, const string &B){
    return A.length() == B.length() ? A < B : A.length() < B.length();
}
void xuli(){
    string ans = "";
    backtrack(ans, 0);

    sort(ALL(res), tmp);
    res.resize(unique(ALL(res)) - res.begin());

    bool check = true;
    for(auto u : res) if(s[u] > 1) {
        cout << u;
        return;
    }
    cout << -1;
}
int main(){
    readfile();
    xuli();
    return 0;
}
