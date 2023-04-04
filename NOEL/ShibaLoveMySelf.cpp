//  (´｡• ω •｡`) ♡

//   (\_/)
//   ( •.•)
//   />💝>  5tingggggg

// ≧◔◡◔≦  ≧◉◡◉≦   ≧✯◡✯≦   ≧❂◡❂≦   ≧^◡^≦   ≧°◡°≦
// ✿◕ ‿ ◕✿   ❀◕ ‿ ◕❀   ❁◕ ‿ ◕❁   (◡‿◡✿) (✿◠‿◠)
// Code by: 𝕊𝕙𝕚𝕓𝕒☞♥ⓛⓞⓥⓔ♥𝕄𝕪𝕊𝕖𝕝𝕗


///      `/ydmmdmmmmmmmdd+-`+ydmmmmmmy:.`     `:sdmmmmy/-.  `:sdmmmdhs`  sdmmmms/       `:ydmmmdhy-odddd+:   `:odmmmmmmdhosmddmmmmmdmmmmmd+:
///        .:Mh+mdhhyyys-.-dNMshmhhhhdMMd`  `+ymhshhhhdmMm/.  .:NMMo+:   `:NMMms:         -/mNNs+/   ys+:. .:dmdsyhhhhNdo//soohhdMdsdhhys/.`
///        .:Mh+s/ ``.--` `-hMsss    /MMm/``:hM+sy`   .+mNy:. .:sdMds:`  +symMm/          -:+dNNho.` ss+`  ohNyo:.   `+/:` `.. .:Mds-. `.-`
///        .:Mh+s/ ys/`   `-hMsss   ohMmy` `ymN/::    `:mNso/ .-/yNMdo` `oydNMm/          -:/osNNN+- ss+` `dNdyo      `        .:Mds-.
///      `+dMMNmMMMMd+`  `.+dMNmdmNM++o-.  .dNM+:.    `-mNhs+ .-/++Nmh/+ssssmMm/          -:/++:yNds:ss+``:dNso+               .:Mds-.
///      `+syMh+dhss+-`  -/ymMso++oymy-`   `ymM+:.    `:mNhs+ .-/++shMooh+/+mMm/          -:/++ :oMmyhy+``:mNyo+      `..      .:Mds-.
///       .-:Mh+s/        `-hMsyh..`mmd.    -hMy+:    -yNNh/. .-/++.oMmds--+mMm/          -:/++ ``dmNdy+` `dMNs/``    :+s.`    .:Mds-.
///        -+Mdss/        `:hMyys   ydMho`   -/mdh...oyNmdo.  :++++ :hdh+..smMm/`         /+so/   -sNmh+`  /sMy+/-`  `hys`     -/Mdy:.
///      `:hMMMMhyo`     `-mNMMmy:. /yMNdo/:   -smMMMMNds+  `odMMmy/:-ys-:oMMMmhy-`     ./mMMNmo:` :yNh+`   .ohmmhy/oyyo-     .smMMMy+-
///      `:////////`     `.//////+:`-oMmho+/   .-://///-`   `///////- /: .://////.`     .///////-` .:/:.      .-//////`       .://///:-



///          _ღᒪIᗷᖇᗩᖇYღ_          ///

#include <bits/stdc++.h>

///         ︵✿вιтмαѕк‿✿         ///

#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define cntBIT(i) __builtin_popcount(i)

///         ︵✿αиσтнєя‿✿         ///

#define ALL(v) (v).begin(), (v).end()
#define shiba_MAXINT 1627060511
#define shiba_MAXLL 4027061977505111978
#define pi 3.14
#define ii pair<int, int>
#define il pair<int, long long>
#define li pair<long long, int>
#define ll pair<long long, long long>
#define fi first
#define se second
#define SQR(i) 1LL * (i) * (i)
#define STP(i) fixed << setprecision((i))
#define Shiba_FASTIO ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define Shiba_FILE freopen("NOEL.INP", "r", stdin); freopen("NOEL.OUT", "w", stdout)
#define Shiba_main int main




using namespace std; ///                                                                 ▓▓▓▓   ▓▓▓▓▓▓▓▓▓▓▓   ▓​▓▓▓
///                                                                                    ▓▓▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓​▒▒▒▓▓
template<class T> T Abs(const T &x) { return (x < 0 ? -x : x); } ///                   ▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓​▓▒▒▓▓
template<class X, class Y> ///                                                          ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓​▓▓▓▓
bool minimize(X &x, const Y &y) { ///                                                     ▓▓▓▓▓███▓▓▓▓▓▓▓███▓▓▓​▓▓
    X eps = 1e-9; ///                                                                    ▓▓▓▓▓▓███▓▓▓▓▓▓▓███▓▓▓​▓▓▓
    if (x > y + eps) { ///                                                               ▓▓▓▓▓▓▓▓▒▒▒███▒▒▒▓▓▓▓▓​▓▓▓
        x = y; ///                                                                       ▓▓▓▓▓▓▓▒▒▒▒███▒▒▒▒▓▓▓▓​▓▓▓
        return true; ///                                                                  ▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓​▓▓
    } else return false; ///                                                                ▓▓▓▓▓▓▒▒▒▒▒▒▒▓▓▓▓▓▓
} ///                                                                                     ▓▓▓░░░░░▓▓▓▓▓▓▓░░░░░▓​▓▓
template<class X, class Y> ///                                                        ▓▓▓▓░░░░░░░░░░░▓░░░░░░░░░​░░▓▓▓▓
bool maximize(X &x, const Y &y) { ///                                                ▓▓▓▓▓░░░░░╔══╦╦╦═╦═╦╦╦═╗░░​░░▓▓▓▓▓
    X eps = 1e-9; ///                                                                ▓▓▓▓▓▓░░░░╚╗╔╣╩║╬║║║═╣═╣░░​░▓▓▓▓▓▓
    if (x + eps < y) { ///                                                           ▓▓▓▓▓▓▓░░░░║║║╦║║║║║║�═║░░​▓▓▓▓▓▓▓
        x = y; ///                                                                   ▓▓▓▓▓▓▓░░░░╚╝╚╩╩╩╩╩╩╩╩═╝░░​▓▓▓▓▓▓▓
        return true; ///                                                              ▓▓▓▓▓▓░░░░░░▄██▄██▄░░░░░░▓​▓▓▓▓▓
    } else return false; ///                                                            ▓▓▓▓░░░░░░███████░░░░░░▓​▓▓▓
} ///                                                                                     ▓▓█▓░░░░███████░░░░▓█​▓▓
///                                                                                    ▓▓▓▓▓▓▓▓▓░░░█████░░░▓▓▓▓​▓▓▓▓▓
template <typename T> ///                                                             ▓▓▒▒▒▒▒▒▓▓▓░░░███░░░▓▓▓▒▒​▒▒▒▒▓▓
inline void Read(T& x) { ///                                                         ▓▓▒▒▒▒▒▒▒▒▒▓▓▓░░▀░░▓▓▓▒▒▒▒​▒▒▒▒▒▓▓
    bool Neg = false; ///                                                            ▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓░▓▓▓▓▒▒▒​▒▒▒▒▒▒▒▓▓
    char c; ///                                                                      ▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▒▒▒▒▒​▒▒​▒▒▒▓▓
    for (c = getchar(); c < '0' || c > '9'; c = getchar()) ///                       ▓▓▓▒▒▒▒▒▒▒▒▓▓▓     ▓▓▓▒▒▒▒​▒▒​▒▒▓▓▓
        if (c == '-') Neg = !Neg; ///                                                 ▓▓▓▓▓▓▓▓▓▓▓▓       ▓▓▓▓▓▓​▓▓▓▓▓▓
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}
template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

#define MAX 2020

int numGift, limit, gift[MAX], id[MAX];
vector <int> a, F, val[MAX];

void Shiba_Read()
{
    cin >> numGift >> limit;
    numGift *= 2;
    for (int i = 1; i <= numGift; ++i)
    {
        cin >> gift[i];
        id[gift[i]] = i;
    }
}

void Shiba_Project2()
{
    for (int i = 1; i <= numGift; ++i) for (int j = -limit; j <= limit; ++j)
    if (j != 0 && gift[i] + j >= 0 && gift[i] + j <= numGift && id[gift[i] + j] > i) val[i].push_back(id[gift[i] + j]);

    for (int i = 1; i <= numGift; ++i) sort(ALL(val[i]), greater<int>());

    int ans = 0;
    for (int t = 1; t < numGift; ++t)
    {
        for (int j = 1; j <= t; ++j) for (int k : val[j]) if (k > t) a.push_back(k);

        if (a.size() == 0) continue;

        F.push_back(0);
        F.push_back(a[0]);

        for (int i = 1; i < a.size(); ++i)
        {
            int idx = lower_bound(ALL(F), a[i]) - F.begin();
            if (idx == F.size()) F.push_back(a[i]);
            minimize(F[idx], a[i]);
            maximize(ans, idx);
        }

        a.clear(); F.clear();
    }

    cout << ans;
}

int L[202][202];

void Shiba_Project1()
{
    int ans = 0;

    for (int k = 1; k < numGift; ++k)
    {
        memset(L, 0, sizeof L);

        for (int i = 1; i <= k; ++i)
        for (int j = k + 1; j <= numGift; ++j)
        {
            maximize(L[i][j], L[i - 1][j - 1] + (abs(gift[i] - gift[j]) <= limit));
            maximize(L[i][j], L[i][j - 1]);
            maximize(L[i][j], L[i - 1][j]);
        }

        maximize(ans, L[k][numGift]);
    }

    cout << ans;
}

void Shiba_Process()
{
    if (numGift <= 200) Shiba_Project1();
    else Shiba_Project2();
}

Shiba_main()
{
    Shiba_FASTIO;
    Shiba_FILE;
    Shiba_Read();
    Shiba_Process();
    return 0;
}

