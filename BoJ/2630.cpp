/* 색종이 만들기
https://www.acmicpc.net/problem/2630

하얀색 파란색으로 칠해진 종이가 있음
주어진 규칙으로 잘라서 
다양한 모양의 '정사각형' 하얀색, 파란색 색종이를 만드려함

규칙
- 종이는 변의 반으로 계속 자를 수 있으며, 
- 자를 수 없을 때 까지 자를수 있음.

주어진 종이에서 '정사각형' 하얀색, 파란색 색종이를 개수를 구하라

입력
- 변길이 N
- 색종이

출력
- 하얀색
- 파란색

풀이
- DFS로 구역을 만들어 나가보자
- 색종이 자르기 규칙대로 2/N 번째 까지만 어떻게 자를지 고민해보자
    - 직접 N/2 씩 잘라서 구역체크를 해보자
    - 만약 해당 사각형이 그려지면, 2로 채우고 무슨색인지 카운트
    - 반복
    - DFS도 아니네 지금보니까 ㅋㅋ
*/
#include <bits/stdc++.h>
using namespace std;
enum COLOR_t{
    WHITE = 0,
    BLUE,
    CUTTED,
};
typedef struct{
    int y;
    int x;
}PaperPoint_t;
int g_whiteCnt, g_blueCnt, g_N;
vector<vector<COLOR_t>> g_paper;

void CheckPaper(PaperPoint_t curr, PaperPoint_t target, COLOR_t targetColor)
{
    // 색종이 잘라도 되는지 체크
    for(int curY = curr.y; curY <= target.y; curY++)
    {
        for(int curX = curr.x;curX <= target.x; curX++)
        {
            if(g_paper[curY][curX] != targetColor)
                return; // 자르면 안되면 return
        }
    }
    // 색종이 자를만 하면 카운트
    if(targetColor == WHITE)
        g_whiteCnt++;
    else if(targetColor == BLUE)
        g_blueCnt++;
    // 자른 색종이 표시
    for(int curY = curr.y; curY <= target.y; curY++)
    {
        for(int curX = curr.x;curX <= target.x; curX++)
        {
            g_paper[curY][curX] = CUTTED;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N;
    g_paper.resize(g_N, vector<COLOR_t>(g_N));
    for(int inY = 0; inY < g_N; inY++)
    {
        for(int inX = 0; inX < g_N; inX++)
        {
            int input;
            cin >> input;
            g_paper[inY][inX] = (COLOR_t)input;
        }
    }

    for(int targetLen = g_N; targetLen > 0; targetLen/=2)
    {
        for(int yIdx = 0; yIdx < g_N; yIdx+=targetLen)
        {
            for(int xIdx =0; xIdx < g_N; xIdx+=targetLen)
            {
                if(g_paper[yIdx][xIdx] != CUTTED)
                    CheckPaper({yIdx, xIdx}, {yIdx+targetLen-1, xIdx+targetLen-1}, g_paper[yIdx][xIdx]);
            }
        }
    }
    cout << g_whiteCnt << "\n" << g_blueCnt;
    return 0;
}