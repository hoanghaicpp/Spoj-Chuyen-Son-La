#include <bits/stdc++.h>
#define nmax 35
using namespace std;

int n, V, v[nmax], S[nmax];
int best = 0;
void Try(int i, int sum)
{
    if (i > n){
        best = max(best, sum);
        return;
    }
    if (sum > V) return;
    if (sum + S[i] <= best) return;
    Try(i + 1, sum);
    if (sum + v[i] <= V) Try(i + 1, sum + v[i]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    S[n + 1] = 0;
    for (int i = n; i >= 1; i--)
        S[i] = S[i + 1] + v[i];
    Try(1, 0);
    cout << best;
}
