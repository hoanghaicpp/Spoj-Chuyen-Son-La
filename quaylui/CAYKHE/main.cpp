#include <bits/stdc++.h>
#define nmax 45
#define mmax 10003
using namespace std;

int n, m, w[nmax], v[nmax], vBest = 0, f[nmax][mmax];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    for (int j = 0; j <= m; j++)
        f[0][j] = 0;
    for (int i = 0; i <= n; i++)
        f[i][0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            f[i][j] = f[i - 1][j];
            if (j >= w[i]){
                f[i][j] = max(f[i][j], f[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << f[n][m];
}
