/* 피보나치 함수
https://www.acmicpc.net/problem/1003

문제에 명시된 함수로 피보나치 수열을 구할수 있음
재귀문이며, n-1, n-2각각 0이되었을때 0을, 1이되었을때 1을 출력한다
N번째 피보나치 수를 만들었을때, 해당 재귀문에서 0과 1을 몇번 총 몇번 출력하는지
구하라

제한시간 0.25초

입력
- T (TestCase)
- N (0 ~ 40)
- N... 

출력
- 0카운트 1카운트
- ...

풀이
- 0 [0,1] , 1 [1, 0] ... 이후 피보나치 수 구하듯 [n-2, n-1] 값 구하면됨
- 배열하나 만들어서 각 [n-2, n-1]들 구해서 답 구하면 될듯
*/
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> g_fibos = {{1,0},{0,1},};
int g_T, g_input;

int main()
{
    // Init fibo
    for(int num = 2; num <= 40; num++)
    {
        int firstNum = g_fibos[num-2].first + g_fibos[num-1].first;
        int secondNum = g_fibos[num-2].second + g_fibos[num-1].second;
        g_fibos.push_back({firstNum, secondNum});
    }
    cin >> g_T;
    while(g_T--)
    {
        cin >> g_input;
        cout << g_fibos[g_input].first << " " << g_fibos[g_input].second <<"\n";
    }
    return 0;
}