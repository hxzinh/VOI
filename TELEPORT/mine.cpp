#include<bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define N 505
typedef long long ll;

int readInt() {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while(true) {
		if(ch == '-') break;
		if(ch >= '0' && ch <= '9') break;
		ch = getchar();
	}

	if(ch == '-') minus = true; else result = ch - '0';
	while(true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result * 10 + (ch - '0');
	}

	if(minus)
		return -result;
	else
		return result;
}

int res[N][N];
int sumr[N][N], sumb[N][N], preRow[N], preCol[N], sufRow[N], sufCol[N], row, col, p;
char ch[N][N];

int sumArea(int sum[][N], int x, int y, int u, int v) {
    return sum[u][v] - sum[u][y - 1] - sum[x - 1][v] + sum[x - 1][y - 1];
}

void process() {
    cin >> row >> col >> p;
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {
            cin >> ch[i][j];
            sumr[i][j] = sumr[i - 1][j] + sumr[i][j - 1] - sumr[i - 1][j - 1] + (ch[i][j] == 'r');
            sumb[i][j] = sumb[i - 1][j] + sumb[i][j - 1] - sumb[i - 1][j - 1] + (ch[i][j] == 'b');
        }
    }

    for (int i = 0; i < p; ++i)
        preRow[i] = preCol[i] = 1e9+7;

    for (int i = p; i <= row; ++i) {
        preRow[i] = preRow[i - 1];
        for (int j = 1; j + p - 1 <= col; ++j) {
            int z = sumArea(sumr, i - p + 1, j, i, j + p - 1);
            z += sumb[row][col] - sumArea(sumb, i - p + 1, j, i, j + p - 1);
            preRow[i] = min(preRow[i], z);
        }
    }

    for (int i = row - p + 2; i <= row + 1; ++i)
        sufRow[i] = 1e9+7;

    for (int i = row - p + 1; i > 0; --i) {
        sufRow[i] = sufRow[i + 1];
        for (int j = 1; j + p - 1 <= col; ++j) {
            int z =  sumArea(sumr, i, j, i + p - 1, j + p - 1);
            z += sumb[row][col] - sumArea(sumb, i, j, i + p - 1, j + p - 1);
            sufRow[i] = min(sufRow[i], z);
        }
    }

    for (int j = p; j <= col; ++j) {
        preCol[j] = preCol[j - 1];
        for (int i = 1; i + p - 1 <= row; ++i) {
            int z = sumArea(sumr, i, j - p + 1, i + p - 1, j);
            z += sumb[row][col] - sumArea(sumb, i, j - p + 1, i + p - 1, j);
            preCol[j] = min(preCol[j], z);
        }
    }

    for (int i = col - p + 2; i <= col + 1; ++i)
        sufCol[i] = 1e9+7;

    for (int j = col - p + 1; j > 0; --j) {
        sufCol[j] = sufCol[j + 1];
        for (int i = 1; i + p - 1 <= row; ++i) {
            int z = sumArea(sumr, i, j, i + p - 1, j + p - 1);
            z += sumb[row][col] - sumArea(sumb, i, j, i + p - 1, j + p - 1);
            sufCol[j] = min(sufCol[j], z);
        }
    }

    for (int i = 1; i + p - 1 <= row; ++i) {
        for (int j = 1; j + p - 1 <= col; ++j) {
            res[i][j] = 1e9+7;
        }
    }

    for (int i = 1; i + p - 1 <= row; ++i) {
        for (int j = 1; j + p - 1 <= col; ++j) {
            int x1(i), y1(j), u1(i + p - 1), v1(j + p - 1);

            int ans = sumArea(sumr, x1, y1, u1, v1) - sumArea(sumb, x1, y1, u1, v1);
            ans += min({preRow[i - 1], sufRow[i + p], preCol[j - 1], sufCol[j + p]});

            res[i][j] = min(res[i][j], ans);
            for (int k = i; k <= min(row - p + 1, u1); ++k) {
                for (int l = max(j - p + 1, 1); l <= min(col - p + 1, v1); ++l) {
                    int x2(k), y2(l), u2(k + p - 1), v2(l + p - 1);
                    int val = sumb[row][col] - sumArea(sumb, x1, y1, u1, v1) - sumArea(sumb, x2, y2, u2, v2);
                    val += sumArea(sumr, x1, y1, u1, v1) + sumArea(sumr, x2, y2, u2, v2);

                    int xc = max(x1, x2), yc = max(y1, y2), uc = min(u1, u2), vc = min(v1, v2);
                    val += 2 * sumArea(sumb, xc, yc, uc, vc) - 2 * sumArea(sumr, xc, yc, uc, vc);
                    res[i][j] = min(res[i][j], val);
                    res[k][l] = min(res[k][l], val);
                }
            }

            cout << res[i][j] << ' ';
        }

        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("bidoimau.inp", "r", stdin);
    freopen("bidoimau.out", "w", stdout);

    process();
    return 0;
}
