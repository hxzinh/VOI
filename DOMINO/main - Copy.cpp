}
template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

#define MAX 1010

int row, col, limit;
long long a[MAX][4], F[MAX][2 * MAX][MASK(4)];
vector <int> L[MASK(4)], Q[MASK(4)], D[MASK(4)];

void Shiba_Read()
{
    cin >> row >> col >> limit;
    for (int i = 1; i <= row; ++i) for (int j = 0; j < col; ++j)
        cin >> a[i][j];
}

void Shiba_Process()
{
    for (int i = 0; i < MASK(col); ++i)
    for (int j = 0; j < col; ++j)
    if (BIT(i, j)) L[i].push_back(j);

    for (int i = 0; i < MASK(col); ++i)
    for (int j = 0; j < MASK(col); ++j)
    if (!(i & j)) D[i].push_back(j);

    for (int i = 0; i < MASK(col); ++i)
    for (int j = 0; j < col - 1; ++j)
    if (!BIT(i, j) && !BIT(i, j + 1)) Q[i].push_back(j);

    for (int i = 0; i <= row; ++i)
    for (int k = 0; k <= limit; ++k)
    for (int mask = 0; mask < MASK(col); ++mask)
        F[i][k][mask] = -shiba_MAXLL;

    F[1][0][0] = 0;

    for (int i = 1; i <= row; ++i)
    for (int k = 0; k <= limit; ++k)
    for (int mask = 0; mask < MASK(col); ++mask) if (F[i][k][mask] > -shiba_MAXLL)
    {
        for (int new_mask : D[mask])
        {
            long long s = 0;
            for (int nil : L[new_mask]) s += a[i][nil] + a[i + 1][nil];
            maximize(F[i + 1][k + cntBIT(new_mask)][new_mask], F[i][k][mask] + s);
        }

        for (int x : Q[mask])
            maximize(F[i][k + 1][mask | MASK(x) | MASK(x + 1)], F[i][k][mask] + a[i][x] + a[i][x + 1]);
        maximize(F[i + 1][k][0], F[i][k][mask]);
    }

    int res = -shiba_MAXLL;
    for (int i = 1; i <= row; ++i) for (int mask = 0; mask < MASK(col); ++mask)
        maximize(res, F[i][limit][mask]);
    cout << res;
}

Shiba_main()
{
    Shiba_FASTIO;
    Shiba_FILE;
    Shiba_Read();
    Shiba_Process();
    return 0;
}