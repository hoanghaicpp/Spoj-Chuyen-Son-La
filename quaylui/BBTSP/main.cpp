#include <bits/stdc++.h>
using namespace std;

int n, c[20][20], x[20], T[20], best = INT_MAX, bestWay[20];
bool vistited[20];

void Try(int i)
{
    for (int j = 2; j <= n; j++){
        if (!vistited[j]){
            x[i] = j;
            T[i] = T[i - 1] + c[x[i - 1]][j];
            if (T[i] < best){
                if (i < n){
                    vistited[j] = true;
                    Try(i + 1);
                    vistited[j] = false;
                }
                else{
                    if (T[n] + c[x[n]][1] < best){
                        memcpy(bestWay, x, sizeof x);
                        best = T[n] + c[x[n]][1];
                    }
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    x[1] = 1;
    T[1] = 0;
    memset(vistited, false, sizeof vistited);
    Try(2);
    cout << best << "\n";
    for (int i = 1; i <= n; i++)
        cout << bestWay[i] << ' ';
    cout << 1;
}
