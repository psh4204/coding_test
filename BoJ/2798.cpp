/* https://www.acmicpc.net/problem/2798
블랙잭

N장의 카드를 숫자가보이게 바닥에 둔다. 
M을 외치는 순간에 카드 3장을 가져간다.
이 세장으로 M을 넘지않는 최대값을 만들어야한다.

[입력]
N (3~100) M (10~300,000)
숫자 리스트 (1~100,000)

[출력]
M을 넘지않는 최대값

[풀이]
조합으로 풀면될듯.
받은 숫자 정렬 후 숫자를 잘 골라야함.
숫자 세개를 조합하여 가장 큰값을 구해보자.

for문으로 해도 되는데, 연습삼아서 재귀로 풀어보자.

*/

#include <bits/stdc++.h>
using namespace std;
#define MAX_ITER 3
int g_max, g_N, g_M;
vector<int> g_cards;

void combi(int curLoopIdx, int iterCnt, int sum)
{
    if(iterCnt == MAX_ITER)
    {
        if(sum > g_M)
            return;
        g_max = max(sum, g_max);
        return;
    }

    for(int loopIdx = curLoopIdx+1; loopIdx < g_cards.size(); loopIdx++)
    {
        combi(loopIdx, iterCnt+1, sum + g_cards[loopIdx]);
    }
}

int main()
{
    cin >> g_N >> g_M;
    g_cards.resize(g_N,0);
    for(int inCnt = 0; inCnt < g_N; inCnt++)
        cin >> g_cards[inCnt];
    sort(g_cards.begin(), g_cards.end());
    combi(-1,0,0);
    cout << g_max;
    return 0;
}