#include <bits/stdc++.h>
using namespace std;

int n, k, d[30], best = 0;

void Try(int i, int cnt_chose, int cnt_pass, int sum)
{
    if (cnt_pass == 2) return;
    if (cnt_chose == k){
        best = max(best, sum);
        return;
    }
    Try(i + 1, cnt_chose + 1, 0, sum + d[i]);
    Try(i + 1, cnt_chose, cnt_pass + 1, sum);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    Try(1, 0, 0, 0);
    cout << best;
}
