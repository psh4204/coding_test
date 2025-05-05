/* 나무 섭지 ?
https://softeer.ai/practice/7726

NxM 미로에 갇힘.
상하좌우로 움직여냄.
출구로 가면 됨.

유령. "벽통과가능". 상하좌우 이동가능.
- 남우가 유령과 마주치면 탈출해도 실패.

입력
- n m (1~1000)
- 격자 (N 나무/ . 공기/ D 탈출/ G 유령/ # 벽)

출력
- 탈출여부 (Yes, No)

풀이
- 유령 움직임 부터 BFS로 visited 처리 해야함 (벽통과 가능)
- 해당 visited에서 나무의 weight가 더 적을때, 해당 visited로 움직일 수 있음.
- 도착지에 도착못하면 No, 도착하면 Yes
*/

#include <bits/stdc++.h>
using namespace std;
struct Move_t{
    int y;
    int x;
    int weight;
};
bool isYes = false;
int g_N, g_M;
vector<vector<int>> g_visited(1000,vector<int>(1000, -1));
vector<vector<char>> g_map(1000,vector<char>(1000));
queue<Move_t> g_ghost;
queue<Move_t> g_namu;
vector<vector<int>> g_degree = {{-1,0}, {0,1}, {1,0}, {0,-1}};

int main(int argc, char** argv)
{
    // Faster IO
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL); 
    
    // 정보 입력
    cin >> g_N >> g_M;
    for(int yIdx = 0; yIdx< g_N; yIdx++)
    {
        for(int xIdx = 0; xIdx < g_M; xIdx++)
        {
            cin >> g_map[yIdx][xIdx];
            switch(g_map[yIdx][xIdx])
            {
                case 'G':
                {
                    g_ghost.push({yIdx, xIdx, 0});
                    g_visited[yIdx][xIdx] = 0;
                }
                break;
                case 'N':
                {
                    g_namu.push({yIdx, xIdx, 0});
                }
                break;
            }
        }
    }

    // 귀신 움직이기 (맵 전체 탐방)
    while(!g_ghost.empty())
    {
        Move_t now = g_ghost.front();
        g_ghost.pop();
        for(int dIdx = 0; dIdx < 4; dIdx++)
        {
            int nextY = now.y + g_degree[dIdx][0];
            int nextX = now.x + g_degree[dIdx][1];
            int nextWeight = now.weight + 1;
            if(nextY < 0 || nextX < 0 || nextY >= g_N || nextX >= g_M)
                continue;
            if(g_visited[nextY][nextX] != -1)
                continue;
            g_visited[nextY][nextX] = nextWeight;
            g_ghost.push({nextY,nextX,nextWeight});
        }
    }
    
    // 나무 도망치기 (나무자리에 귀신있는지 체크하기 == 0)
    if(g_visited[g_namu.front().y][g_namu.front().x] == 0)
        g_namu.pop();
    else
    {
        g_visited[g_namu.front().y][g_namu.front().x] = 0;
    }
    while(!g_namu.empty() && !isYes)
    {
        Move_t now = g_namu.front();
        g_namu.pop();
        for(int dIdx = 0; dIdx < 4; dIdx++)
        {
            int nextY = now.y + g_degree[dIdx][0];
            int nextX = now.x + g_degree[dIdx][1];
            int nextWeight = now.weight +1;
            if(nextY < 0 || nextX < 0 || nextY >= g_N || nextX >= g_M)
                continue;
            if(g_visited[nextY][nextX] != -1 && g_visited[nextY][nextX] <= nextWeight)
                continue;
            if(g_map[nextY][nextX] == '#')
                continue;
            if(g_map[nextY][nextX] == 'D')
            {
                isYes = true;
                break;
            }
            g_visited[nextY][nextX] = nextWeight;
            g_namu.push({nextY,nextX,nextWeight});
        }
    }

    if(isYes)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}