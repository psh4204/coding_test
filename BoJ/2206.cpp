/* 벽 부수고 이동하기
https://www.acmicpc.net/problem/2206

NxM 지도가 있음
- 0: 이동가능
- 1: 벽

최단경로를 구하라
- 벽은 하나 부술수 있다

입력
- N M (1~1000)
- 지도

출력
- 최단경로

풀이
- BFS문제
- 벽을 하나 부실수 있음
    - 벽 무시 카운트 1개 장전했다 생각하자
    - 벽 무시 카운트가 없는데, 벽이 또 있으면 소멸
포인트
- 벽안부신 visited, 벽 부신 visited 따로 관리
- 이때 부순것,안부순것 둘중하나가 더 빠를 수 있기 때문에 이렇게 관리
- 부순것이 역행할수도 있는데 괜찮은가? -> 그런거 까지 하라고 배열을 두개 나눔
    - 어차피 BFS라 가장빠른길을 찾음 걱정 ㄴㄴ.
*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_M;
struct Node_t{
    int y;
    int x;
    int weight;
    int wellCnt;
};
vector<vector<int>> g_degree = {{-1,0}, {0,1}, {1,0}, {0,-1}};
vector<vector<char>> g_map(1001, vector<char>(1001));
vector<vector<pair<int,int>>> g_visited(1001, vector<pair<int,int>>(1001,{INT_MAX, INT_MAX})); // 벽안부순거, 벽부순거

int main()
{
    cin >> g_N >> g_M;
    for(int yIdx =0 ;yIdx < g_N; yIdx++)
    {
        for(int xIdx =0; xIdx < g_M; xIdx++)
        {
            cin >> g_map[yIdx][xIdx];
        }
    }
    queue<Node_t> nodeQ;
    nodeQ.push({0,0,1,0});
    g_visited[0][0].first = 1;
    while(!nodeQ.empty())
    {
        Node_t now = nodeQ.front();
        nodeQ.pop();
        for(int dIdx = 0; dIdx<4; dIdx++)
        {
            Node_t next = now;
            next.y += g_degree[dIdx][0];
            next.x += g_degree[dIdx][1];
            next.weight +=1;
            if(next.y < 0 || next.x < 0 || next.y >= g_N || next.x >= g_M)
                continue;
            if(g_map[next.y][next.x] == '1')
            {
                if(next.wellCnt == 1)
                    continue;
                else
                    next.wellCnt =1;
            }
            if(next.wellCnt == 0 && g_visited[next.y][next.x].first > next.weight)
            {
                g_visited[next.y][next.x].first = next.weight;
                nodeQ.push(next);
            }
            else if(next.wellCnt == 1 && g_visited[next.y][next.x].second > next.weight)
            {
                g_visited[next.y][next.x].second = next.weight;
                nodeQ.push(next);
            }
        }
    }
    if(g_visited[g_N-1][g_M-1].first == INT_MAX && g_visited[g_N-1][g_M-1].second == INT_MAX)
        cout << -1;
    else
    {
        int ans = min(g_visited[g_N-1][g_M-1].first, g_visited[g_N-1][g_M-1].second);
        cout << ans;
    }

    return 0;
}