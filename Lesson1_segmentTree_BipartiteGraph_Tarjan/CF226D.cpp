#include <bits/stdc++.h>
#define MAXN 112

using namespace std;
typedef int arrayN[MAXN];

int n, m, a[MAXN][MAXN];
arrayN colNum, rowNum, visCol, visRow;

void prtAns(int arr[], int N)
{
    int tot = 0;
    for (int i = 1; i <= N; ++i)
        if (arr[i])
            tot++;
    cout << tot << ' ';
    for (int i = 1; i <= N; ++i)
        if (arr[i])
            cout << i << ' ';
    cout << endl;
}
int main()
{
    //freopen("cf226d.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    memset(colNum, 0, sizeof(colNum));
    memset(rowNum, 0, sizeof(rowNum));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
            colNum[j] += a[i][j];
            rowNum[i] += a[i][j];
        }
    for (;;)
    {
        int flag = 1;
        for (int i = 0; i < n && flag; ++i)
            if (rowNum[i] < 0)
            {
                for (int j = 0; j < m; ++j)
                {
                    a[i][j] *= -1;
                    rowNum[i] += 2 * a[i][j];
                    colNum[j] += 2 * a[i][j];
                }
                visRow[i + 1] = 1 - visRow[i + 1];
                flag = 0;
            }

        for (int j = 0; j < m && flag; ++j)
            if (colNum[j] < 0)
            {
                visCol[j + 1] = 1 - visCol[j + 1];
                for (int i = 0; i < n; ++i)
                {
                    a[i][j] *= -1;
                    rowNum[i] += 2 * a[i][j];
                    colNum[j] += 2 * a[i][j];
                }
                flag = 0;
            }
        if (flag) break;
    }

    prtAns(visRow, n);
    prtAns(visCol, m);
    return 0;
}
