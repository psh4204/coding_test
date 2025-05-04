/* 치즈
https://www.acmicpc.net/problem/2638

세로N과 가로M짜리 모눈종이에 치즈가 놓여있고,
치즈는 자신의 변 두개가 공기와 닿으면 한시간뒤 사라짐
- 참고 치즈 내부 공기로는 안사라짐

모눈종이의 가장자리는 항상 비어있다는 전재를 하고,
치즈가 정확히 몇시간뒤에 사라지는지 확인해보자

입력
- N M (5~100)
- 치즈:1, 공기:0으로 표시된 모눈종이

출력
- 사라지는데 걸리는 시간

풀이
- 탐색으로 풀면될듯
- 공기에 닿은 치즈 확인후 해당 치즈가 공기에 얼마나 닿았는지 체크
    - 삭제할 치즈면 2로 업데이트 (추후 0으로 만들어서 삭제)
- 이런 큰 루프카운트는 결국 루프를 한번더 돌수밖에 없음. 그래서 루프카운트 -1 처리
*/
#include <bits/stdc++.h>
using namespace std;
struct Point_t{
    int y;
    int x;
};
int g_N, g_M, g_loopCnt;
bool g_isRun = true;
vector<vector<int>> g_cheese(100, vector<int>(100));
vector<vector<int>> g_degree = {{-1,0}, {0,1}, {1,0}, {0,-1}}; // 첫번째 값은 쓰레기값

int main()
{
    cin >> g_N >> g_M;
    for(int yIdx = 0; yIdx < g_N; yIdx++)
    {
        for(int xIdx = 0; xIdx < g_M; xIdx++)
        {
            cin >> g_cheese[yIdx][xIdx];
        }
    }

    while(g_isRun)
    {
        vector<vector<int>> visited(g_N, vector<int>(g_M,0));
        // 공기와 맞닿는 치즈만 구해오기
        queue<Point_t> airQ;
        queue<Point_t> cheeseQ;
        airQ.push({0,0});
        visited[0][0] = 1;
        while(!airQ.empty())
        {
            Point_t now = airQ.front();
            airQ.pop();
            for(int dIdx = 0; dIdx < 4; dIdx++)
            {
                Point_t next = {now.y+g_degree[dIdx][0], now.x+g_degree[dIdx][1]};
                if(next.y < 0 || next.x < 0 || next.y >= g_N || next.x >= g_M)
                    continue;
                if(visited[next.y][next.x] == 1)
                    continue;
                visited[next.y][next.x] = 1;
                if(g_cheese[next.y][next.x] == 1)
                    cheeseQ.push(next);
                else
                {
                    g_cheese[next.y][next.x] = 0; // 치즈가 아닌것들은 계속 공기로 만들어둚 (2인 애들도 공기됨)
                    airQ.push(next);
                }
            }
        }
        if(cheeseQ.empty())
        {
            g_isRun = false;
            break;
        }
        // 맞닿는 치즈들 중에 없어질 치즈들 삭제
        while(!cheeseQ.empty())
        {
            Point_t now = cheeseQ.front();
            cheeseQ.pop();
            int airCnt = 0;
            // 해당 치즈가 얼마나 다른면과 닿여있는지 체크
            for(int dIdx = 0; dIdx < 4; dIdx++)
            {
                Point_t next = {now.y+g_degree[dIdx][0], now.x+g_degree[dIdx][1]};
                if(next.y < 0 || next.x < 0 || next.y >= g_N || next.x >= g_M)
                    continue;
                if(g_cheese[next.y][next.x] == 0 && visited[next.y][next.x] == 1)
                {
                    airCnt++;
                }
            }
            if(airCnt >=2)
                g_cheese[now.y][now.x] = 2;
        }
        g_loopCnt++;
        // // TEST <<<< 
        // cout << g_loopCnt-1 << "-----\n";
        // for(int y = 0; y < g_N; y++)
        // {
        //     for(int x =0; x< g_M; x++)
        //         cout << g_cheese[y][x] << " ";
        //     cout << "\n";
        // }
    }

    cout << g_loopCnt;

    return 0;
}