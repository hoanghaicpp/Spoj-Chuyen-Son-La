#include <bits/stdc++.h>
using namespace std;

int n, x[30], cnt = 0;

void Try(int i)
{
    for (int j = 0; j <= 1; j++){
        if (j == 0 && x[i - 1] == 0 && i > 1) continue;
        x[i] = j;
        if (i == n) cnt++;
        else Try(i + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    Try(1);
    cout << cnt;
}
