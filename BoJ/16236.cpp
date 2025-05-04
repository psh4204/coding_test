/* 아기 상어
https://www.acmicpc.net/problem/16236

아기상어가 엄마를 부르지 않는 최소시간을 구하라
- 아기상어 레벨은 2임
    - 자신보다 레벨이 낮은 상대만 잡아먹을 수 있음
- 아기상어는 4방향으로 움직임
    - 자신보다 레벨이 높으면 못지나감
- 레벨업 조건: 자신의 레벨수 만큼 물고기를 잡아먹어야함
- 엄마콜 조건: 아무것도 못할 때

특수조건
- 먹을 수 있는 물고기가 1마리보다 많다면, 가장 가까운물고기를 먹는다
- 가까운 물고기가 많다면, 가장 위의 물고기를, <- 함정1
    그러한 물고기가 여러마리면 가장 왼쪽의 물고기를 먹는다 <- 함정2

입력
- N (공간크기 2~20)
- 공간정보
    - 0: 빈칸
    - 1~6: 물고기 레벨
    - 9: 아기상어 위치

출력
- 엄마블 부르지 않는 최소시간

풀이
- BFS 문제인데 visited가 복잡하네 ..
- 결국 마지막으로 잡아먹는 최소시간을 구해야함
- 메인 루프를 돌림 (못잡아먹으면 종료)
    - visited는 매번 초기화
    - 최단거리에 물고기를 잡아먹을때를 항상 구해야함
    - 먹을때 마다 적절히 레벨업도 해줘야함


[NOTE]
- 문제가 길면 길수록, 더 꼼꼼히 읽어보자
- 꼭 다 정리되면 그때 부터 문제풀고, 안풀리면 문제 다시 꼼꼼히 읽자
- 내가짜는 로직이 틀리는 법이 정말 잘 없다는 것을 기억하자
- "문제 꼼꼼히", "오타", "등잔밑이 어둡다!!!!!!!!!!!"
*/
#include <bits/stdc++.h>
using namespace std;
struct Baby_t{
    int y;
    int x;
    int time;
    int level;
    int eatCnt;
};
struct Fish_t
{
    int y;
    int x;
    int time;
};

bool CustomCmp(const Fish_t & left, const Fish_t & right)
{
    if(left.time < right.time)
        return true;
    else if(left.time == right.time)
    {
        if(left.y < right.y)
            return true;
        else if(left.y == right.y)
        {
            return left.x < right.x;
        }
    }
    return false;
}

int g_N, g_time;
vector<vector<int>> g_area(20, vector<int>(20));
vector<vector<int>> g_degree = {{-1,0}, {0,1}, {1,0}, {0,-1}};
Baby_t g_baby;

int main()
{
    cin >> g_N;
    for(int yIdx = 0; yIdx < g_N; yIdx++)
    {
        for(int xIdx = 0; xIdx < g_N; xIdx++)
        {
            cin >> g_area[yIdx][xIdx];
            if(g_area[yIdx][xIdx] == 9)
            {
                g_baby.y = yIdx;
                g_baby.x = xIdx;
                g_baby.time = 0;
                g_baby.level = 2;
                g_baby.eatCnt = 0;
                g_area[yIdx][xIdx] = 0;
            }
        }
    }
    while(true)
    {
        queue<Baby_t> q;
        vector<vector<int>> visited(g_N, vector<int>(g_N, 0));
        vector<Fish_t> willEatFishList;
        g_baby.time = 0;
        q.push(g_baby);
        visited[g_baby.y][g_baby.x] = 1;
        while(!q.empty())
        {
            Baby_t now = q.front();
            q.pop();
            for(int dIdx = 0; dIdx < 4; dIdx++)
            {
                int nextY = now.y + g_degree[dIdx][0];
                int nextX = now.x + g_degree[dIdx][1];
                int nextTime = now.time+1;
                if(nextY < 0 || nextX < 0 || nextY >= g_N || nextX >= g_N)
                    continue;
                if(visited[nextY][nextX] != 0)
                    continue;
                if(g_area[nextY][nextX] > g_baby.level)
                    continue;
                // 유영
                visited[nextY][nextX] = 1;
                q.push({nextY, nextX, nextTime, now.level, now.eatCnt});
                
                // 잡아먹을게 있다면, 일단 킵
                if(g_area[nextY][nextX]!= 0 && g_area[nextY][nextX] < g_baby.level)
                    willEatFishList.push_back({nextY, nextX, nextTime});
            }
        }
        if(willEatFishList.size() != 0)
        {
            sort(willEatFishList.begin(), willEatFishList.end(), CustomCmp);
            g_area[willEatFishList[0].y][willEatFishList[0].x] = 0;
            g_baby.y = willEatFishList[0].y;
            g_baby.x = willEatFishList[0].x;
            g_baby.eatCnt++;
            if(g_baby.eatCnt == g_baby.level)
            {
                g_baby.level++;
                g_baby.eatCnt = 0;
            }
            g_baby.time = willEatFishList[0].time;
            g_time += g_baby.time;
        }
        else    break;
    }
    cout << g_time;
    return 0;
}