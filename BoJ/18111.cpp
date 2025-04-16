/* 마인크래프트
https://www.acmicpc.net/problem/18111

집을짓기위해 땅고르기 작업을 해야함
NxM 집터에 H씩 각기다른 높이를 가지고있음
다음의 작업이 가능함
- 블럭을 제거하면 인텐토리에 넣음 (1초)
- 인벤토리의 블럭을 빼서 블럭쌓기 가능 (2초)

땅고르기 작업시 최소시간과 땅의 높이를 출력한다

입력
- N M B (1~'N,M'~500, B 가지고있는블록개수 0~64,000,000)
-좌표별블럭높이들

출력
- 땅을 고르게하는데 걸리는 시간과 높이 출력
*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_M, g_B, \
    g_midH, g_lowH = INT_MAX, g_highH, g_H, \
    g_minTime = INT_MAX;
vector<vector<int>> g_ground;

void MakeGround(int targetH)
{
    int inven = g_B;
    int tTimeSum = 0; // takenTime Sum
    for(int y = 0; y < g_N; y++)
    {
        for(int x = 0; x < g_M; x++)
        {
            int needBlock =  targetH - g_ground[y][x];
            if(needBlock > 0)
            {
                tTimeSum += 1*needBlock;
                inven-=needBlock;
            }
            else if(needBlock < 0)
            {
                tTimeSum += 2*abs(needBlock);
                inven+=abs(needBlock);
            }
            if(g_minTime < tTimeSum)
                return;
        }
    }
    if(inven < 0)
        return;
    if(tTimeSum <= g_minTime)
    {
        g_minTime = tTimeSum;
        g_H = targetH;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N >> g_M >> g_B;
    g_ground.resize(g_N,vector<int>(g_M));
    for(int y = 0; y < g_N; y++)
    {
        for(int x = 0; x < g_M; x++)
        {
            cin >> g_ground[y][x];
            g_lowH = min(g_lowH, g_ground[y][x]);
            g_highH = max(g_highH, g_ground[y][x]);
        }
    }
    for(int targetH = g_lowH; targetH <= g_highH; targetH++)
    {
        MakeGround(targetH);
    }
    cout << g_minTime << " " << g_H;
    return 0;
}