/* 내려가기
https://www.acmicpc.net/problem/2096

N줄에 0이상 9이하의 숫자가 세개씩 적혀있음
층 내려가기 규칙
- 바로아래, 혹은 바로아래와 붙어있는 같은층의 수
- 가장 위층부터 가장 아래층까지 내려가면 됨

게임 후의 최대점수, 최소점수 두개를 구하라

입력
- N (1~100,000)
- N줄씩 숫자 세개씩 (0~9)

출력
- 최대점수 최소점수

풀이
- BFS문제인거같은데 (다익스트라)
    - PQ로 점수 큰거 위주로 한번 구하
    - PQ로 점수 작은거 위주로 한번 구하면 끝
- PQ쓰던 DP쓰던 전부 메모리초과
- 뭐가문제지?
- Input 받을때 단순 for문 돌려서 dp 만들어 풀자
*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_minAns = INT_MAX, g_maxAns;
struct Value_t{
    int min = INT_MAX;
    int max;
};
vector<Value_t> g_sums(3);
vector<int> g_input(3);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N;
    for(int xIdx = 0; xIdx < 3; xIdx++)
    {
        cin >> g_sums[xIdx].min;
        g_sums[xIdx].max = g_sums[xIdx].min;
    }
    // // TEST
    // for(auto sum: g_sums)
    //     cout << sum.max << " " << sum.min << "[[TEST]]\n";
    
    for(int yIdx = 1; yIdx < g_N; yIdx++)
    {
        vector<Value_t> sums(3);
        for(int xIdx = 0; xIdx < 3; xIdx++)
            cin >> g_input[xIdx];
        for(int xIdx = 0; xIdx < 3; xIdx++)
        {
            for(int nIdx = -1; nIdx <=1; nIdx++)
            {
                int preX = xIdx + nIdx;
                if(preX < 0 || preX >=3)
                    continue;
                sums[xIdx].min = min(g_sums[preX].min+g_input[xIdx], sums[xIdx].min);
                sums[xIdx].max = max(g_sums[preX].max+g_input[xIdx], sums[xIdx].max);
            }
        }
        // cout << yIdx << "[y]\n";
        // for(auto sum: sums)
        // {
        //     cout << sum.max << " " << sum.min << "[[TEST]]\n";
        // }
        g_sums = sums;
    }
    for(auto sum : g_sums)
    {
        g_minAns = min(g_minAns, sum.min);
        g_maxAns = max(g_maxAns, sum.max);
    }
    cout << g_maxAns << " " << g_minAns;
    return 0;
}