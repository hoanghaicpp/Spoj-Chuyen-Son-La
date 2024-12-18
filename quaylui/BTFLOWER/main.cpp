#include <bits/stdc++.h>
using namespace std;

int bestSum = INT_MIN;
int m, n, a[22][22];
pair<int, int> bestWay[50], way[50];
void Try(int i, int j, int sum)
{
    way[i + j - 1] = make_pair(i, j);
    if (i == m && j == n)
    {
        if (sum > bestSum)
        {
            bestSum = sum;
            memcpy(bestWay, way, sizeof way);
        }
        return;
    }
    if (i < m && a[i + 1][j] != -1) Try(i + 1, j, sum + a[i + 1][j]);
    if (j < n && a[i][j + 1] != -1) Try(i, j + 1, sum + a[i][j + 1]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    Try(1, 1, 0);
    if (bestSum != INT_MIN)
    {
        cout << bestSum << "\n";
        for (int i = 1; i <= m + n - 1; i++)
            cout << bestWay[i].first << ' ' << bestWay[i].second << "\n";
    }
    else cout << -1;
}
