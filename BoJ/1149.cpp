/* RGB 거리
https://www.acmicpc.net/problem/1149

1번집 부터 N번집까지 순서대로 있음
- 빨강, 초록, 파랑 하나로 색칠해야함
- 각 집을 마다 각 색깔별 색칠비용이 주어짐

다음 규칙을 만족하며 모든 집을 칠하는 최소비용을 구해보자
- 1번집은 2번집과 색이 달라야함
- N번집은 N-1번 집과 색이 달라야함
- '집 색은 i-1, i+1번집과 색이 달라야함'

입력
- N (2~1,000)
- R G B(색깔별 비용)

출력
- 모든 집을 칠하는 비용의 최소값을 출력한다

풀이
- BFS인가?
- 앞의 집과 뒷집이 색이 같으면 안되면서, 가장 최소비용이라.. 
- dp요소가 있어야할듯
    - 해당 집의 색을 선택했을때와 안했을때 최소비용
- dp1차원으로 3가지 (R,G,B)
    - 현재집 까지 규칙을 어기지않고(앞집이랑 색깔달라야함)
        가장 최소값의 비용
    - 마지막 집까지 RGB 최소비용에서 가장 작은거 체크
*/
#include <bits/stdc++.h>
using namespace std;
enum RGB_t{
    R,
    G,
    B
};
int g_N, g_ans = INT_MAX;
vector<int> g_R(1002);
vector<int> g_G(1002);
vector<int> g_B(1002);
vector<vector<int>> g_house(1002,vector<int>(3)); // {{R,G,B},}

int main()
{
    cin >> g_N;

    for(int inCnt = 1; inCnt <= g_N; inCnt++)
    {
        cin >> g_house[inCnt][0];
        cin >> g_house[inCnt][1];
        cin >> g_house[inCnt][2];
    }
    for(int hIdx = 1; hIdx <= g_N; hIdx++)
    {
        // 각 집의 R G B 중 최소합만 RGB dp에 기입한다
        // Check R
        g_R[hIdx] = g_G[hIdx-1] <= g_B[hIdx-1] ? 
            g_G[hIdx-1] + g_house[hIdx][R]: g_B[hIdx-1] + g_house[hIdx][R];
        // Check G
        g_G[hIdx] = g_R[hIdx-1] <= g_B[hIdx-1] ? 
            g_R[hIdx-1] + g_house[hIdx][G]: g_B[hIdx-1] + g_house[hIdx][G];
        // Check B
        g_B[hIdx] = g_R[hIdx-1] <= g_G[hIdx-1] ? 
            g_R[hIdx-1] + g_house[hIdx][B]: g_G[hIdx-1] + g_house[hIdx][B];
    }
    
    g_ans = min(g_R[g_N], g_G[g_N]);
    g_ans = min(g_ans, g_B[g_N]);
    cout << g_ans;
    return 0;
}