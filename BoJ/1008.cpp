/* https://www.acmicpc.net/problem/1008
Special Judge.  A/B
*/
#include <bits/stdc++.h>
using namespace std;
double g_first, g_second;

void Init()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}


int main()
{
    Init();
    cin  >> g_first >> g_second;
    cout << setprecision(10) << g_first /  g_second;
    return 0;
}