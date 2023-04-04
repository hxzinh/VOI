#include <bits/stdc++.h>
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
string x, y;
int a = 0, b = 0;

void readfile(){
    freopen("DIGITS.INP", "r", stdin);
    freopen("DIGITS.OUT", "w", stdout);
    cin >> x >> y;
}
void xuli(){
    for(int i = 0; i < x.length(); i++){
        int u = int(x[i] - 48);
        if(!BIT(a, u)) a |= MASK(u);
    }
    for(int i = 0; i < y.length(); i++){
        int u = int(y[i] - 48);
        if(!BIT(b, u)) b |= MASK(u);
    }

    if(a == b){
        cout << "friends";
        return;
    }

    int change = 0;
    for(int i = 0; i < x.length() - 1; i++){
        int u = int(x[i + 1] - 48);
        int v = int(x[i] - 48);
        int fi = change, se = change;
        if(!BIT(fi, u - 1)){
            fi |= MASK(u - 1);
            if(!BIT(fi, v + 1)) fi |= MASK(v + 1);
        } else {
            if(!BIT(fi, v + 1)) fi |= MASK(v + 1);
        }

        if(!BIT(se, u + 1)){
            se |= MASK(u + 1);
            if(i == 0 && v - 1 > 0) if(!BIT(se, v - 1)) se |= MASK(v - 1);
            if(i > 0) if(!BIT(se, v - 1)) se |= MASK(v - 1);
        } else {
            if(i == 0 && v - 1 > 0) if(!BIT(se, v - 1)) se |= MASK(v - 1);
            if(i > 0) if(!BIT(se, v - 1)) se |= MASK(v - 1);
        }
        for(int j = i + 2; j < x.length(); j++){
            int newU = int(x[j] - 48);
            if(!BIT(fi, newU)) fi |= MASK(newU);
            if(!BIT(se, newU)) se |= MASK(newU);
        }
        if(fi == b || se == b){
            cout << "almost friends";
            return;
        }
        if(!BIT(change, v)) change |= MASK(v);
    }

    change = 0;
    for(int i = 0; i < y.length() - 1; i++){
        int u = int(y[i + 1] - 48);
        int v = int(y[i] - 48);
        int fi = change, se = change;
        if(!BIT(fi, u - 1)){
            fi |= MASK(u - 1);
            if(!BIT(fi, v + 1)) fi |= MASK(v + 1);
        } else {
            if(!BIT(fi, v + 1)) fi |= MASK(v + 1);
        }

        if(!BIT(se, u + 1)){
            se |= MASK(u + 1);
            if(i == 0 && v - 1 > 0) if(!BIT(se, v - 1)) se |= MASK(v - 1);
            if(i > 0) if(!BIT(se, v - 1)) se |= MASK(v - 1);
        } else {
            if(i == 0 && v - 1 > 0) if(!BIT(se, v - 1)) se |= MASK(v - 1);
            if(i > 0) if(!BIT(se, v - 1)) se |= MASK(v - 1);
        }
        for(int j = i + 2; j < y.length(); j++){
            int newU = int(y[j] - 48);
            if(!BIT(fi, newU)) fi |= MASK(newU);
            if(!BIT(se, newU)) se |= MASK(newU);
        }
        if(fi == a || se == a){
            cout << "almost friends";
            return;
        }
        if(!BIT(change, v)) change |= MASK(v);
    }
    cout << "nothing";
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
