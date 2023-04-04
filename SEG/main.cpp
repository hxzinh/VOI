#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 5e5 + 10;
string s;
int a[NM][2];

void readfile(){
    freopen("SEG.INP", "r", stdin);
    freopen("SEG.OUT", "w", stdout);
    cin >> s;
    int cnt = 0;
    bool ok;
    for(int i = s.length() - 1; i >= 0; i--){
        while(s[i] == s[i - 1]){
            cnt++;
            int temp = (s[i] == '>' ? 1 : 0);
            a[i - 1][temp] = cnt;
            i--;
        }
        int temp = (s[i] == '>' ? 1 : 0);
        a[i - 1][temp] = cnt + 1;
        cnt = 0;
    }
}
void xuli(){
    for(int i = 0; i < s.length(); i++) cout << a[i][1] << " " << a[i][0] << '\n';
    int cnt = 0, res = 0;
    for(int i = 0; i < s.length(); i++){
        int temp = (s[i] == '>' ? 1 : 0);
        if(temp == 0) { /// tang
            while(s[i] == s[i + 1]){
                res += cnt;
                cnt++;
                i++;
            }
            cnt = max(cnt, a[i][1]);
            res += cnt;
        } else { /// giam
            cnt = max(cnt, a[i][1]);
            while(s[i] == s[i + 1]){
                cnt--;
                res += cnt;
                i++;
            }
            res += min(cnt, a[i][0]);
            cnt = min(cnt, a[i][0]);
        }
    }
    cout << res;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
