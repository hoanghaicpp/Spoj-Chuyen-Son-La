#include <bits/stdc++.h>
using namespace std;

int n, x[15];
bool use[15];

void Print()
{
    for (int i = 1; i <= n; i++)
        cout << x[i] << ' ';
    cout << "\n";
}
void Try(int i)
{
    for (int j = 1; j <= n; j++){
        if (use[j]){
            x[i] = j;
            use[j] = false;
            Try(i + 1);
            use[j] = true;
            if (i == n) Print();
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    memset(use, true, sizeof use);
    Try(1);
}
