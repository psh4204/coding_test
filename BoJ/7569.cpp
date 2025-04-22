/* 토메이도우
https://www.acmicpc.net/problem/7569

토마토가 완전히 다 익는데 걸리는 최소시간을 구하라
그리고 만약, 다 못익으면 -1을 뱉어라

풀이
- BFS에 weight 추가한 문제
- 끝까지 탐색하며, 남은 토마토개수(다 익었는지)와 최대 weight수(몇일걸린지)를 체크

3 3 3
-1 -1 -1
-1 0 -1
-1 -1 -1
-1 -1 -1
-1 -1 -1
-1 -1 -1
1 0 0
0 0 0
0 0 1

3 3 3
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0


4 4 3
1 1 1 1
1 -1 1 1
1 1 1 1
1 1 1 1

1 1 1 1
1 1 -1 1
1 1 1 1
1 1 1 1

1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1

4 4 3
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1

1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1

1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1


*/
#include <bits/stdc++.h>
using namespace std;
enum Tomato_t{
    EMPTY = -1,
    RAW = 0,
    RIPED = 1,
};
int g_X, g_Y, g_Z;
int g_maxWeight = 0, g_remainCnt = 0;
vector<vector<vector<int>>> g_tomatoes;
vector<vector<vector<int>>> g_visited; // visted 겸 weight카운트 (-1 부터 시작)
vector<vector<int>> g_degrees = {
    {0, -1, 0}, {0, 0, 1}, {0, 1, 0}, {0, 0, -1}, {-1,0,0}, {1,0,0}
}; // z y x . 상/하/좌/우/위/아래
typedef struct{
    int z, y, x;
}Axis_t;
queue<Axis_t> g_ripenQ;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_X >> g_Y >> g_Z;
    g_tomatoes.resize(g_Z, vector<vector<int>>(g_Y, vector<int>(g_X, 0)));
    g_visited.resize(g_Z, vector<vector<int>>(g_Y, vector<int>(g_X, -1)));

    for(int inZ = 0; inZ < g_Z; inZ++)
    {
        for(int inY = 0; inY < g_Y; inY++)
        {
            for(int inX = 0; inX < g_X; inX++)
            {
                cin >> g_tomatoes[inZ][inY][inX];
                if(g_tomatoes[inZ][inY][inX] == RAW)
                    g_remainCnt+=1;
                else if(g_tomatoes[inZ][inY][inX] == RIPED)
                {
                    g_ripenQ.push({inZ, inY, inX});
                    g_visited[inZ][inY][inX] = 0;
                }
            }
        }
    }

    while (!g_ripenQ.empty() && g_remainCnt >= 0)
    {
        Axis_t now = g_ripenQ.front();
        g_ripenQ.pop();
        for(int degIdx = 0; degIdx < 6; degIdx++)
        {
            Axis_t next;
            next.z = now.z + g_degrees[degIdx][0];
            next.y = now.y + g_degrees[degIdx][1];
            next.x = now.x + g_degrees[degIdx][2];
            g_maxWeight = max(g_visited[now.z][now.y][now.x], g_maxWeight); // 최대 weight = 총 걸린시간

            // 6방향으로 BFS로 나아가려할때, 안익은 토마토를 발견하면 그쪽으로 나아간다.
            if(next.z < 0 || next.y < 0 || next.x < 0 ||
                next.z >= g_Z || next.y >= g_Y || next.x >= g_X ||
                g_tomatoes[next.z][next.y][next.x] == RIPED ||
                g_tomatoes[next.z][next.y][next.x] == EMPTY ||
                g_visited[next.z][next.y][next.x] != -1)
                continue;
            g_visited[next.z][next.y][next.x] = g_visited[now.z][now.y][now.x] + 1; // wegiht 증가
            g_ripenQ.push({next.z, next.y, next.x});
            g_remainCnt-=1;
        }
    } 

    // // >> TEST
    // cout << "---g_visited---\n";
    // for(auto z: g_visited)
    // {
    //     for(auto y: z)
    //     {
    //         for(auto x: y)
    //             cout << x << " ";
    //         cout << "\n";
    //     }
    //     cout << "---\n";
    // }
    // // << TEST

    if(g_remainCnt == g_Z*g_Y*g_X) // 모두 생 토마토 라면 0 출력
        cout << -1;
    else if(g_remainCnt == 0 && g_maxWeight == -1) // 생토마토 없이 이미 모두 익은 사과라면 0 출력
        cout << 0;
    else if(g_remainCnt != 0) // 익은 토마토가 있는데, 생토마토가 있다면 -1 출력
        cout << -1;
    else if(g_remainCnt == 0) // 다 익었다면 걸린시간 출력
        cout << g_maxWeight;
    return 0;
}