/* 1로 만들기
https://www.acmicpc.net/problem/1463

X에 대해 다음 연산을 할 것 이다
- X가 3으로 나누어 떨어지면 3으로 나눈다
- X가 2로 나누어 떨어지면 2로 나눈다
- 1을 뺀다

이렇게 N이 주어지면 세개 연산을 통해 1을 만드려한다
연산 최소횟수를 구하라

(제한시간 0.15초) 

입력
- N (1~1,000,000)
출력
- 최소출력횟수

풀이
- 모듈러연산으로 나머지 값이 무엇이 나오는지에 따라 값이 변할듯
- 10 -> 9 -> 3 -> 1
- 11 -> 10 -> 9 -> 3 -> 1
- 12 -> 4 -> 2 -> 1 / 12 -> 6 -> 3 -> 2 -> 1
- 13 -> 12 -> 4 -> 2 -> 1
- 해보니까 단순 수식문제 아님. 
- 어케하노 진짜 조합인갑네 ㅋㅋ
*/
#include <bits/stdc++.h>
using namespace std;
enum CALC_t
{
    DIV_3 = 0,
    DIV_2,
    MIN_1,
};

int g_N, g_cnt, g_minRCnt= INT_MAX; // RouteCnt

void CheckMinRoute(int value, int rCnt)
{
    if(value == 1)
    {
        // cout << rCnt << " << \n";
        g_minRCnt = min(g_minRCnt, rCnt);
        return;
    }
    for(int calcIdx = 0; calcIdx < 3; calcIdx++)
    {
        if(rCnt >= g_minRCnt)
            return;
        switch(calcIdx)
        {
            case(DIV_3):
            {
                if(value%3 == 0)
                    CheckMinRoute(value/3, rCnt+1);
                break;
            }
            case(DIV_2):
            {
                if(value%2 == 0)
                    CheckMinRoute(value/2, rCnt+1);
                break;
            }
            case(MIN_1):
            {
                CheckMinRoute(value-1, rCnt+1);
                break;
            }
        }
    }
}


int main()
{
    cin >> g_N;
    CheckMinRoute(g_N, 0);
    cout << g_minRCnt;
    return 0;
}