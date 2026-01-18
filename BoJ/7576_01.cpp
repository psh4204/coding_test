/* https://www.acmicpc.net/problem/2606
토마토 창고가 있음.
하루가 지나면 익은토마토 상하좌우방항으로 새토마토들이 익음.
최소 감 하나는 창고에 있음.
토마토가 익는데 걸리는 최소일수를 구하라.
(참고로 새토마토는 자연으로 익지 않으며 익은토마토 옆에있어야만이 익음)

[입력]
M N
0(안익은), 1(익은), -1(빈칸)로된 감 지도 (익은건 1. 가로세로 크기 2~1000)

[출력]
- 처음부터 전부 익어있으면 0을 출력.
- 안익은 감이 있다면 -1을 출력.
- 안그렇다면 최단경로 값 중 가장 큰 값 출력

[풀이]
일단 BFS로 풀면 풀릴듯.
0. 입력 받은 후 익은감들은 따로 관리.
1. 익은감 별로 전부 다 BFS 돌린다. (각각 Weight 0부터 시작)
2. 마지막에 
- 처음부터 전부 익어있으면 0을 출력.
- 안익은 감이 있다면 -1을 출력. (안익은감이 단 하나라도 있는 경우)
- 안그렇다면 최단경로 값 중 가장 큰 값 출력
*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_M, g_maxRoad, g_gamCnt;
vector<vector<int>> g_gams;
vector<vector<int>> g_visited;
queue<pair<int,int>> g_evens;

vector<int> g_dy = {-1, 0, 1, 0};
vector<int> g_dx = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_M >> g_N;
    g_gams.resize(g_N, vector<int>(g_M,0));
    g_visited.resize(g_N, vector<int>(g_M,-1)); // -1이면 방문하지 않은 곳.
    for(int y = 0; y < g_N; y++)
    {
        for(int x = 0; x < g_M; x++)
        {
            cin >> g_gams[y][x];
            if(g_gams[y][x] == 1)
            {
                g_evens.push({y,x}); // 익은감은 따로 정리해둔다.(뒤에 BFS시작용으로)
                g_visited[y][x] = 0;
                g_gamCnt++;
            }
            else if(g_gams[y][x] == 0)
                g_gamCnt++;
        }
    }

    // 감이 전부 익어있다면?
    if(g_evens.size() == g_gamCnt)
    {
        cout << 0;
        return 0;
    }

    while(!g_evens.empty())
    {
        int nowY = g_evens.front().first;
        int nowX = g_evens.front().second;
        g_evens.pop(); 
        for(int dIdx = 0; dIdx < 4; dIdx++)
        {
            int nextY = nowY + g_dy[dIdx];
            int nextX = nowX + g_dx[dIdx];
            if(nextY < 0 || nextX < 0 || nextY >= g_N || nextX >= g_M)
                continue;
            if(g_visited[nextY][nextX] != -1)
                continue;
            if(g_gams[nextY][nextX] == -1 || g_gams[nextY][nextX] == 1)
                continue;
            g_gams[nextY][nextX] = 1;
            g_visited[nextY][nextX] = g_visited[nowY][nowX] +1;
            g_maxRoad = max(g_visited[nextY][nextX], g_maxRoad);
            g_evens.push({nextY,nextX});
        }
    }
    for(auto y: g_gams)
    {
        for(auto gam: y)
        {
            // 안익은 감 발견!
            if(gam == 0)
            {
                cout << -1;
                return 0;
            }
        }
    }
    cout << g_maxRoad;
    return 0;
}