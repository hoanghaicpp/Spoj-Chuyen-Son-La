#include <bits/stdc++.h>
using namespace std;

int n, s[505], sum = 0, cnt = 0;
void Try(int i, int con1, int con2, int con3)
{
    if (i > n){
        if (con1 == con2 && con2 == con3) cnt++;
        return;
    }
    if (con1 > sum || con2 > sum || con3 > sum) return;
    if (con1 + s[i] <= sum) Try(i + 1, con1 + s[i], con2, con3);
    if (con2 + s[i] <= sum) Try(i + 1, con1, con2 + s[i], con3);
    if (con3 + s[i] <= sum) Try(i + 1, con1, con2, con3 + s[i]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> s[i];
        sum += s[i];
    }
    sort(s + 1, s + n + 1, greater<int>());
    if (sum%3==0)
    {
        sum/=3;
        Try(1, 0, 0, 0);
        if (cnt) cout << cnt;
        else cout << -1;
    }
    else cout << -1;
}
