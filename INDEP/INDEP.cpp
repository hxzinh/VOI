#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
string a;

struct Data {
    int gNo, gI, gO, gIO;

    Data(int _gNo = 0, int _gI = 0, int _gO = 0, int _gIO = 0){
        gNo = _gNo; gI = _gI; gO = _gO; gIO = _gIO;
    }
};

void readfile(){
    cin >> a;
}
Data changeS(Data u, Data v){
    int gNo = max(u.gNo + v.gNo, u.gO + v.gI - 1);
    int gI = max(u.gI + v.gNo, u.gIO + v.gI - 1);
    int gO = max(u.gNo + v.gO, u.gO + v.gIO - 1);
    int gIO = max(u.gI + v.gO, u.gIO + v.gIO - 1);
    return Data(gNo, gI, gO, gIO);
}
Data changeP(Data u, Data v){
    int gNo = u.gNo + v.gNo;
    int gI = u.gI + v.gI - 1;
    int gO = u.gO + v.gO - 1;
    int gIO = u.gIO + v.gIO - 2;
    return Data(gNo, gI, gO, gIO);
}
void xuli(){
    stack<Data> st;

    int n = a.length() - 1;
    for(int i = n; i >= 0; i--){
        char k = a[i];
        if(k == 'g') st.push(Data(0, 1, 1, -INF));
        if(k == 'S'){
            Data x = st.top(); st.pop();
            Data y = st.top(); st.pop();
            st.push(changeS(x, y));
        }
        if(k == 'P'){
            Data x = st.top(); st.pop();
            Data y = st.top(); st.pop();
            st.push(changeP(x, y));
        }
    }

    Data u = st.top();
    ///cout << u.gNo << " " << u.gI << " " << u.gO << " " << u.gIO;
    int res = max({u.gNo, u.gI, u.gO, u.gIO});
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
