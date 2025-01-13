/* A-B: https://www.acmicpc.net/problem/1001
두 정수 입력 후 뺀값 출력 프로그램
*/
#include <bits/stdc++.h>
using namespace std;
int g_first = 0, g_second = 0;

void Init()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
}

int main()
{
    Init();
    cin >> g_first >> g_second;
    cout << g_first - g_second;
    return 0;
}