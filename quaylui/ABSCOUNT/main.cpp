#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
char x[30];

void Try(int i)
{
    for (char j = 'A'; j <= 'B'; j++){
        if (j == 'A' && x[i - 1] == 'A' && i > 1) continue;
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
