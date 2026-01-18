/* https://www.acmicpc.net/problem/14503
로봇 청소기 (청소하는 영역의 개수를 구하라)

*****문제 제대로 읽어라!!  1은 벽이다!!!!!!!! ********



방은 N*M으로 표현됨. (0~ N-1, 0~M-1)
청소기는 4방향으로 움직일 수 있음.
처음엔 청소가 되지않은 상태로 칸이 주어짐.

청소기 움직임
1. 청소되지않은 현재칸은 청소한다.
2. 주변 4칸중 청소되지않은 칸이 없는경우 (X)
- 바라보는 방향을 유지한 채 **후진할 수 있다면 후진**한 후, 1번으로 돌아감
- 바라보는 방향의 뒤쪽같이 벽이라 후진할수 없다면 **작동을 멈춘다**.
3. 주변 4칸중 청소되지않은 칸이 있는 경우 (O)
- **반시계방향**으로 90도 회전한다
- 바라보는 방향을 기준으로 앞칸이 청소되지않았다면 한칸 전진 후 1번으로 돌아간다.

[입력]
N M (3~50)
r c (청소기 좌표) d (바라보는방향 0 북, 1 동쪽 .. 시계방향)
각 장소 상태들 (0 청소안됨, 1 청소됨)

[출력]
시작 후 청소하는 칸의 개수를 출력한다.

[풀이]
탐색..인데 DFS처럼 풀어야하는 문제로 보임
규칙대로 움직였을때 청소하는 칸의 개수를 출력해야함.
청소할게 없다면(X) **후진**해야한다는 점 기억해야함.
- 후진 불가시(X X) 종료. (exit 1)
청소할게 있다면(O)
- d 는 시계방향인데, 움직이는건 **반시계방향**으로 해야함.
- 반시계방향 회전 후 앞칸 청소 가능하면 전진.

잠만,, 개어렵네이거
- d 방향은 시계방향이고, 주위 네바퀴돌땐 반시계방향.
- next d를 구할때 loop로 돌리는 법이 개빡센데 이거
  0
 3 1
  2
    - 3 2 1 0
    - 2 1 0 3
    - 1 0 3 2
    - 0 3 2 1
    - 아! next가 0보다 작으면 3으로 돌리면되는구나
*/
#include <bits/stdc++.h>
using namespace std;
struct Robot_t {
    int y;
    int x;
    int d;
};

Robot_t g_robot;
int g_N, g_M, g_cleanCnt;
vector<vector<int>> g_map;
vector<int> g_dy = {-1, 0, 1, 0};
vector<int> g_dx = {0, 1, 0, -1};

void LetsCleaning(Robot_t now)
{
    Robot_t next = now;
    // 1. 현재 칸이 청소되지 않은 경우 청소 진행.
    if(g_map[now.y][now.x] == 0)
    {
        g_map[now.y][now.x] = 2;
        g_cleanCnt++;
    }
    // /***** TEST ******/
    // cout << "( " << g_cleanCnt <<" ) \n";
    // for(int y = 0; y < g_N; y++)
    // {
    //     for(int x = 0; x < g_M; x++)
    //         cout << g_map[y][x] << " ";
    //     cout << "\n";
    // }
    // /***** TEST ******/

    // 2. 주변 4칸 중 청소할게 있다면(O)
    // - d 는 시계방향인데, 움직이는건 **반시계방향**으로 해야함.
    // - 반시계방향 회전 후 앞칸 청소 가능하면 1번으로 이동.
    for(int d = 0; d < 4; d++)
    {
        // 반시계방향 회전
        next.d = next.d - 1 >= 0 ? next.d - 1 : 3;
        // 해당 바라보는 방향으로 갈 수 있는지 체크
        int preNextY = now.y + g_dy[next.d];
        int preNextX = now.x + g_dx[next.d];
        // cout << " [" << preNextY <<  "," << preNextX <<"] "; /***** TEST ******/ 
        if(preNextY < 0 || preNextX < 0 || preNextY >= g_N || preNextX >= g_M)
            continue;
        // 청소 가능 여부 확인 후 청소
        next.y = preNextY; 
        next.x = preNextX;
        if(g_map[next.y][next.x] == 0) // 청소 가능 (O)
        {
            // cout << "GotoFront " ;/***** TEST ******/
            LetsCleaning(next);
            return;
        }
    }

    // 3. 주변 4칸 중 청소할게 없다면(X) **후진**후 1번으로 이동.
    // - 후진 불가시(X X) 종료. (exit 0). 벽까지 포함.
    next.y = now.y - g_dy[now.d];
    next.x = now.x - g_dx[now.d];
    if(next.y < 0 || next.x < 0 || next.y >= g_N || next.x >= g_M || g_map[next.y][next.x] == 1)
    {
        // 후진불가판정
        cout << g_cleanCnt;
        exit(0);
    }
    // cout << "GotoBack" ;/***** TEST ******/
    LetsCleaning(next); // 후진
}

int main()
{
    cin >> g_N >> g_M;
    g_map.resize(g_N, vector<int>(g_M,0));
    cin >> g_robot.y >> g_robot.x >> g_robot.d;
    for(int y = 0; y < g_N; y++)
    {
        for(int x = 0; x < g_M; x++)
        {
            cin >> g_map[y][x];
        }
    }
    LetsCleaning(g_robot);

    return 0;
}