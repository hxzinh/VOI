#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
string s;
int day, month, year;

int check(int year, int month, int day) {
        if (month < 3) {
            year--;
            month += 12;
        }
        return 365*year + year/4 - year/100 + year/400 + (153*month - 457)/5 + day - 306;
}
void readfile()
{
    freopen("OLYMPICS.INP","r",stdin);
    freopen("OLYMPICS.OUT","w",stdout);
    cin >> s;
    for(int i = 0; i <= 3; i++) year = year * 10 + s[i] - 48;
    for(int i = 5; i <= 6; i++) month = month * 10 + s[i] - 48;
    for(int i = 8; i <= 9; i++) day = day * 10 + s[i] - 48;
    cout << check(2021, 7, 23) - check(year, month, day);
}
int main()
{
    FastIO
    readfile();
    return 0;
}
