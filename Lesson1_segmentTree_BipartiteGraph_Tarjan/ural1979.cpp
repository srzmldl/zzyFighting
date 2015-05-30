#include <bits/stdc++.h>
#define MAXN 112

using namespace std;

int a[MAXN][MAXN];

int main()
{
    //  freopen("ural1979.in", "r", stdin);
    int n;
    cin >> n;
    int tot = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            a[i][j] = ++tot;
            a[3 * n - 1 - i][j] = 6 * n * n + 1 - tot;
            a[i + n][j] = ++tot;
            a[i + n][3 * n - 1 - j] = 6 * n * n + 1 - tot;
            a[i + n][j + n] = ++tot;
            a[i + n][4 * n - 1 - j] = 6 * n * n + 1 - tot;
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cout << a[i][j] << " \n"[j == n - 1];
    for (int i = n; i < 2 * n; ++i)
        for (int j = 0; j < 4 * n; ++j)
            cout << a[i][j] << " \n"[j == 4 * n - 1];
    for (int i = 2 * n; i < 3 * n; ++i)
        for (int j = 0; j < n; ++j)
            cout << a[i][j] << " \n"[j == n - 1];
    return 0;
}
