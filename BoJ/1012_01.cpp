/* 유기농 배추
배추밭에 지렁이 키워서 유기농 배추농사를 하려함
지렁이는 인접한 배추로 움직일 수 있음 (4방향)

배추(1) 빈땅(0) 으로 된 지도를 받았을때,
농사지을 때 필요한 "최소한의 지렁이 수"를 구하라.

[입력]
테케
배추밭 가로길이 M, 세로길이 N, 배추위치 개수. (1~50,1~50,1~2500)
X, Y 좌표
...
....
배추밭 가로길이 ... 반복

[출력]
각 테케별 최소 배추흰지렁이 마리수 출력.

[풀이]
2차원 visited를 써야하는 탐색문제
편하게 BFS로 풀자~
*/
#include <bits/stdc++.h>
using namespace std;
int g_tc, g_N, g_M, g_BC, g_x, g_y;
vector<int> g_dy = {-1, 0, 1, 0};
vector<int> g_dx = {0, 1, 0, -1};

int main()
{
    cin >> g_tc;
    for(int tc = 0; tc < g_tc; tc++)
    {
        cin >> g_M >> g_N >> g_BC;
        vector<vector<int>> field(g_N,vector<int>(g_M,0));
        vector<vector<int>> visited(g_N,vector<int>(g_M,0));
        int bugs = 0;
        for(int bc = 0; bc < g_BC; bc++)
        {
            cin >> g_x >> g_y;
            field[g_y][g_x] = 1;
        }

        // 밭에 배추좌표를 통해 이어져있는 배추가 있는지 체크
        // 하면서 그룹화 시킨다. 그룹화가 성공적으로 되면 애벌레 카운팅을 한다.
        for(int y = 0; y < g_N; y++)
        {
            for(int x = 0; x < g_M; x++)
            {
                if(field[y][x] == 1 && visited[y][x] == 0)
                {
                    bugs++;
                    // 해당 좌표에 대한 BFS 진행
                    queue<pair<int,int>> Q;
                    Q.push({y,x});
                    visited[y][x] = 1;
                    while(!Q.empty())
                    {
                        pair<int,int> now = Q.front();
                        Q.pop();
                        for(int move = 0; move<4; move++)
                        {
                            int nextY = now.first + g_dy[move];
                            int nextX = now.second + g_dx[move];
                            if(nextY < 0 || nextY == g_N)
                                continue;
                            if(nextX < 0 || nextX == g_M)
                                continue;
                            if(visited[nextY][nextX] || field[nextY][nextX] == 0)
                                continue;
                            Q.push({nextY,nextX});
                            visited[nextY][nextX] = 1;
                        }
                    }
                }
            }
        }
        cout << bugs << "\n";
    }
    return 0;
}

