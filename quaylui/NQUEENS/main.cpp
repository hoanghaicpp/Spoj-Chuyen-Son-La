#include <bits/stdc++.h>
#define nmax 105
using namespace std;

int n, x[nmax], cnt = 0;
bool cot[nmax], cheo_chinh[nmax], cheo_phu[nmax], isPrint;
vector<int> a;

void MakeAns()
{
    for (int i = 1; i <= n; i++)
        a.push_back(x[i]);
}
void Try(int i)
{
    for (int j = 1; j <= n; j++){
        if (cot[j] && cheo_chinh[i - j + n] && cheo_phu[i + j - 1]){
            x[i] = j;
            if (i == n){
                cnt++;
                if (!isPrint)
                {
                    MakeAns();
                    isPrint = true;
                }
            }
            else{
                cot[j] = false; cheo_chinh[i - j + n] = false; cheo_phu[i + j - 1] = false;
                Try(i + 1);
                cot[j] = true; cheo_chinh[i - j + n] = true; cheo_phu[i + j - 1] = true;
            }
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    memset(cot, true, sizeof(cot));
    memset(cheo_chinh, true, sizeof(cheo_chinh));
    memset(cheo_phu, true, sizeof(cheo_phu));
    isPrint = false;
    Try(1);
    cout << cnt << "\n";
    for (int x:a)
        cout << x << ' ';
}
