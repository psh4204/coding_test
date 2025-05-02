/* 가장 긴 바이토닉 부분 수열
https://www.acmicpc.net/problem/11054

바이토닉 수열 예시
- 1 2 3 2 1
- 1 2 3
- 3 2 1

수열에서 가장 긴 바이토닉 수열의 길이를 구하라

입력
- N (1~1000)
- 수열 (1~1000)
출력
- 가장긴바이토닉수열 길이

풀이
- dp이긴한데, 2차원 dp 필요할듯
- 하나는 증가수열 dp, 반대로 증가하는 수열
- 각 i번째 LIS를 더한 후 -1 을 해줘야함 (자신을 중복포함하는것을 지우기 위함)

감소    1 1 2 3 2 3 2 1 2 3

         1 5 2 1 4 3 4 5 2 1
증가     1 2 2 1 3 3 4 5 2 1
반증     1 5 2 1 4 3 3 3 2 1

만약 합이 2가 최대면 바이토닉으로썬 1임

0 1 5 2 1 4 3 4 5 2 1
0 1 2 2 1 3 3 4 5 2 1
0 1 5 2 1 4 3 3 3 2 1
*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_maxCnt;
vector<int> g_nums(1002);
vector<int> g_incr(1002);
vector<int> g_opin(1002);

int main()
{
    cin >> g_N;
    for(int nIdx = 1; nIdx <= g_N; nIdx++)
        cin >> g_nums[nIdx];
    
    for(int target = 1; target <= g_N; target++)
    {
        for(int prev = 1; prev < target; prev++)
        {
            if(g_nums[target] > g_nums[prev])
                g_incr[target] = max(g_incr[target], g_incr[prev]);
        }
        g_incr[target] +=1;
    }
    for(int target = g_N; target > 0; target--)
    {
        for(int prev = g_N; prev > target; prev--)
        {
            if(g_nums[target] > g_nums[prev])
                g_opin[target] = max(g_opin[target], g_opin[prev]);
        }
        g_opin[target] +=1;
    }

    // // TEST >>
    // for(int nIdx = 0; nIdx <= g_N; nIdx++)
    //     cout << g_nums[nIdx] << " ";
    // cout << "\n";
    // for(int nIdx = 0; nIdx <= g_N; nIdx++)
    //     cout << g_incr[nIdx] << " ";
    // cout << "\n";
    // for(int nIdx = 0; nIdx <= g_N; nIdx++)
    //     cout << g_opin[nIdx] << " ";
    // cout << "\n";
    // // TEST <<
    for(int target = 1; target <= g_N; target++)
    {
        g_maxCnt = max(g_maxCnt, g_incr[target]+g_opin[target]-1 );
    }
    cout << g_maxCnt;
    return 0;
}