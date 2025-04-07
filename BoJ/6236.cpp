/* 용돈관리 (번역이슈 및 문제 이슈있음)
https://www.acmicpc.net/problem/6236

N일간 매일 돈이 얼마필요한지 미리 기록함. (돈은 1~10,000) (N은 1~100,000)
정확한 지출을 관리하기 위해 M을 만듦. (1 ~ M <= N)
이를 통해 정확히 M번, K원씩 출금하기로 함
K원 그대로 하루를 보내는데
- 부족하면 남은돈을 통장에 넣고, K원을 다시 인출해서 생활한다
K 최소값을 구하라

입력
- N M (1~N~100,000, 1<= M <= N)
- 사용할 금액

출력
- K

풀이
- K원이 하루지출금액보다 적을 수 없음 = 최소K원은 max 지출비
- 정확한 M카운트를 찾기위해 K원을 잘 이분탐색 해보자

자료형 최대최소크기
- https://turtle-dennis.tistory.com/64
- int: INT_MAX INT_MAX
- 

*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_M;
long long g_K = LLONG_MAX, g_lK, g_rK, g_midK, g_input;
vector<int> g_moneys;

int main()
{
    cin >> g_N >> g_M;
    for(int inCnt = 0; inCnt < g_N; inCnt++)
    {
        cin >> g_input;
        g_moneys.push_back(g_input);
        g_lK = max(g_lK, g_input);
        g_rK += g_input;
    }

    while(g_lK <= g_rK)
    {
        int remain = 0; 
        long long mCnt = 0;
        g_midK = (g_lK + g_rK)/2;
        for(int monIdx = 0 ; monIdx < g_N; monIdx++)
        {
            if(remain < g_moneys[monIdx])
            {
                remain = g_midK;
                mCnt +=1;
            }
            remain -= g_moneys[monIdx];
        }
        if(mCnt > g_M)
            g_lK = g_midK+1;
        else if(mCnt <= g_M)
        {
            g_rK = g_midK-1;
            g_K = min(g_midK, g_K);
        }
    }
    cout << g_K;
    return 0;
}