/* 가장 긴 감소하는 부분수열
https://www.acmicpc.net/problem/11722

수열을 받았을때, 가장긴 줄어드는 부분수열의 카운트를 구하라

입력
- N (1~1000)
- 수열
출력
- 가장 긴 감소하는 부분수열의 길이를 구한다

풀이
- LIS의 반대문제
- 10 30 10 20 20 10
--> 1 1 2 2 2 3 -> 3
*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_maxCnt = 0;
vector<int> g_lds;
vector<int> g_nums;

int main()
{
    cin >> g_N;
    g_lds.resize(g_N);
    g_nums.resize(g_N);
    for(int inCnt = 0; inCnt < g_N; inCnt++)
    {
        cin >> g_nums[inCnt];
    }
    for(int targetIdx = 0; targetIdx < g_N; targetIdx++)
    {
        for(int cmpIdx = 0; cmpIdx <= targetIdx; cmpIdx++)
        {
            if(g_nums[cmpIdx] > g_nums[targetIdx] && g_lds[cmpIdx] >= g_lds[targetIdx])
            {
                g_lds[targetIdx] = g_lds[cmpIdx];
            }
        }
        g_lds[targetIdx]+=1;
        g_maxCnt = max(g_lds[targetIdx], g_maxCnt);
    }
    cout << g_maxCnt;
    return 0;
}