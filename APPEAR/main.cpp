#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 2e5 + 10;
int n;
string s, a[NM];

void readfile(){
    cin >> s;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void xuli(){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            string tmp = a[i] + a[j];
            if(tmp.length() < s.length()) continue;
            string res = "";
            for(int u = 0; u < s.length(); u++) res += tmp[u];
            if(res == s) cnt++;
            for(int u = s.length(); u < tmp.length(); u++){
                res.erase(0, 1);
                res = res + tmp[u];
                if(res == s) cnt++;
            }
        }
    }
    cout << cnt;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
