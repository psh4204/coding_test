/* 뱀과 사다리 게임
https://www.acmicpc.net/problem/16928
- 주사위를 조작하면 최소 몇번만에 도착점에 도착할까?

주사위는 1~6
게임크기 10x10. 각 칸마다 1~100까지 순서대로 적힘

주사위를 돌려 칸 이동을 함
사다리가 나오면 사다리 타서 올라갈수있음
뱀이 나오면 뱀따라 내려가야함
출발점은 1, 도착지는 100번째 칸

게임판을 받았을때, 최소 몇번 주사위를 굴려야 100번째까지 도달하는가?


입력
- 사다리수N(1~5) 뱀의수M(1~15)
- 사다리 정보 x,y들(x에 도착하면 y로 감)
- 뱀 정보 u,v 들 (u에 도착하면 v로 감)
(1,100번째칸은 깨끗. 모든 칸은 뱀-사다리중 하나만 가질수 있음)

출력
- 최소 주사위 횟수

풀이
- 1~100 까지 배열 만듦
    - 각 칸은 몇번 점프할수있는지 들어감 (기본 0)
    - 사다리나 뱀이 주어지면 그에맞는 점프횟수를 넣는다 (+, -)
- 움직일때, 6칸씩 앞을 보는데, 
    이중 가장 큰 점프회수가 있는 곳으로 간다
- 만약 전부 동일한 점프회수밖에 없다면, 가장먼 점프칸으로 간다
- 그리고 마지막 쯤에 100번째 칸에 도달할 수 있는 칸으로 이동한다. (제일큰거를 꼭 고를필요X)
- 반드시 100번째 칸에 도달하게 게임을 만들어뒀으니, 무리한 뱀의 개수는 생각안해도 될듯

- 음.. 그럼 이문제는 투포인터 문제네 -> 틀림
    - 내 예상엔 0 0 0 6 -1 -4 0 0 6 0 0 -1 0 0 0 0 <- 얘처럼 6으로 안넘어가는게 좋은 경우도 있을듯
    - BFS로 처리해보자
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> g_game(101, 0); // 1~100 인덱스를위해 101로함
vector<int> g_visited(101, 0); // 1~100 인덱스를위해 101로함
int g_N, g_M, g_start, g_target, g_nowPoint = 0, g_diceCnt;

int main()
{
    cin >> g_N >> g_M;
    while(g_N--) // 사다리 체크
    {
        cin >> g_start >> g_target;
        g_game[g_start] = g_target - g_start;
    }
    while(g_M--) // 뱀 체크
    {
        cin >> g_start >> g_target;
        g_game[g_start] = g_target - g_start;
    }
    // //TEST
    // for(int i = 1; i <= 100; i++)
    //     cout << i << " : " << g_game[i] << "\n";

    queue<pair<int,int>> pointQ; // {nowPoint, diceCnt}
    pointQ.push({1,0});
    g_visited[0] = 1; g_visited[1] = 1;
    while(!pointQ.empty())
    {
        pair<int,int> now = pointQ.front();
        pointQ.pop();
        if(now.first == 100)
        {
            g_diceCnt = now.second;
            break;
        }

        for(int diceIdx = 1; diceIdx <= 6 && now.first + diceIdx <=100; diceIdx++)
        {
            int nextPoint = now.first+diceIdx;
            if(nextPoint > 100) // 단순 주사위 카운트로 100넘기는지
                continue;
            if(g_visited[nextPoint] != 0)
                continue;
            if(g_game[nextPoint] == 0) // 해당 칸에 사다리,뱀 없으면
            {
                g_visited[nextPoint] = 1;
                pointQ.push({nextPoint, now.second+1});
                // cout << "now.Point: " << now.first << "  now.DiceCnt: " << now.second << " nextPoint: "<<nextPoint  << " nextDice: " << now.second+1 << "\n"; // TEST 
            }
            else if(g_game[nextPoint] != 0)// 사다리나 뱀이 있으면
            {
                int nNextPoint = nextPoint + g_game[nextPoint];
                if(nNextPoint > 100) // 해당 weight + diceCnt + 을 했을때, 100을 넘기는지
                    continue;
                if(g_visited[nNextPoint] != 0)
                    continue;
                // 이나라면 weight 증가 및 visited
                g_visited[nextPoint] = 1;
                g_visited[nNextPoint] = 1;
                pointQ.push({nNextPoint, now.second+1});
                // cout << "now.Point: " << now.first << "  now.DiceCnt: " << now.second << " nNextPoint: "<< nNextPoint  << " nNextDice: " << now.second+1 << "\n"; // TEST 
            }
        }
    }
    cout << g_diceCnt;
    return 0;
}