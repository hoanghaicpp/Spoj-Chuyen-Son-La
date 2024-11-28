#include <bits/stdc++.h>
using namespace std;

int n;
char x[25];

void Print()
{
    for (int i = 1; i <= n; i++)
        cout << x[i];
    cout << "\n";
}
void Try(int i, int check)
{
    if (i > n){
        if (check == 0) Print();
        return;
    }
    x[i] = '(';
    Try(i + 1, check + 1);
    if (check > 0){
        x[i] = ')';
        Try(i + 1, check - 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    n*=2;
    Try(1, 0);
}
