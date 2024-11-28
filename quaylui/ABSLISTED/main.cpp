#include <bits/stdc++.h>
using namespace std;

int n;
char x[30];

void Print()
{
    for (int i = 1; i <= n; i++)
        cout << x[i];
    cout << "\n";
}
void Try(int i)
{
    for (char j = 'A'; j <= 'B'; j++){
        if (j == 'A' && x[i - 1] == 'A' && i > 1) continue;
        x[i] = j;
        if (i == n) Print();
        else Try(i + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    scanf("%d", &n);
    Try(1);
}
