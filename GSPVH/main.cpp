#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int d;

void readfile(){
    freopen("GSPVH.INP", "r", stdin);
    freopen("GSPVH.OUT", "w", stdout);
    cin >> d;
    if (d == 1 || d == 11 || d == 7 || d == 22 || d == 20) cout << "Matcha kem cheese them thach tra xanh khong phai cua Hai Tu MTP ma la cua Bobapop";
    else if (d == 4 || d == 25 || d == 23 || d == 15 || d == 2 || d == 29 || d == 12) cout << "Tra sua dua gang them thach suong sao cua MiuTea";
    else if (d == 19 || d == 14 || d == 10 || d == 13 || d == 30 || d == 5 || d == 27 || d == 17) cout << "Chocolate kem cheese them pudding trung cua Bobapop";
    else if (d == 18 || d == 16 || d == 6 || d == 26 || d == 31 || d == 9) cout << "Hong long pha le tuyet cua TocoToco";
    else cout << "Sua tuoi tran chau duong ho cua TocoToco";
}
int main()
{
    FastIO
    readfile();
    return 0;
}
