#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

char syll[5] = {'a', 'e', 'i', 'u', 'o'};
string s;
bool cx[10000];

void readfile(){
    freopen("SYLLABLE.INP", "r", stdin);
    freopen("SYLLABLE.OUT", "w", stdout);
    cin >> s;

    for(int i = 0; i < 5; i++) cx[syll[i] - 'a'] = true;
}
void xuli(){
    int cnt = 0;
    string a = "", b = "";
    for(int i = 0; i < s.length(); i++){
        if(cx[s[i] - 'a']) cnt++;
        if(a.length() == 2){
            a.erase(0, 1);
            a += s[i];
        } else a += s[i];
        if(a == "au" || a == "oa" || a == "oo") cnt--;
        if(b.length() == 3) {
            b.erase(0, 1);
            b += s[i];
        } else b += s[i];
        if(b == "iou") cnt--;
        if (i == s.size() - 1 && s[i] == 'e'){
            cnt--;
            if (i > 1 && s[i - 1] == 'l' && (s[i - 2] != 'a' && s[i - 2] != 'e' && s[i - 2] != 'i' && s[i - 2] != 'o' && s[i - 2] != 'u')) cnt++;
        }
    }
    cout << (cnt ? cnt : 1);
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
