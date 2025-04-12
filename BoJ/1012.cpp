/* 유기농배추: https://www.acmicpc.net/problem/1012

요약: 인접한 배추 구역 개수를 구하라

입력
- TC
- M N (가로 세로. 1~50) K(배추위치개수. 1~2500)
- 배추 위치
- ...

출력
- 배추구역개수

풀이
- DFS, BFS 문제
- DFS로 해결해보자
- 배추는 4방향에 배추가있으면 인접하다라고 판단한다
*/
#include <bits/stdc++.h>
using namespace std;
enum BAECHU_STATE_t{
    INVITE = -1,
    GROUND = 0,
    BAECHU = 1,
};
int g_TC, g_BaechuCnt;
vector<vector<int>> g_degree = {{-1,0},{0,1},{1,0},{0,-1}};

void CheckBaechuArea(int curY, int curX, const int & yMax, const int & xMax ,vector<vector<int>> & baechus)
{
    int cnt = 0;
    for(int dIdx = 0; dIdx < 4; dIdx++)
    {
        int nY = curY + g_degree[dIdx][0];
        int nX = curX + g_degree[dIdx][1];
        if(nY >= yMax|| nX >= xMax|| nY < 0 || nX <0)
            continue; 
        if(baechus[nY][nX]!= BAECHU)
            continue;
        baechus[nY][nX] = INVITE;
        CheckBaechuArea(nY, nX, yMax, xMax, baechus);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_TC;
    while(g_TC--)
    {
        vector<vector<int>> baechus;
        int xMax, yMax, baechuCnt, areaCnt = 0;
        cin >> xMax >> yMax >> baechuCnt; // 가로,세로, 배추위치
        baechus.resize(yMax, vector<int>(xMax));
        while(baechuCnt--)
        {
            int x, y;
            cin >> x >> y;
            baechus[y][x] = BAECHU;
        }
        for(int yIdx = 0; yIdx < yMax; yIdx++)
        {
            for(int xIdx = 0; xIdx < xMax; xIdx++)
            {
                if(baechus[yIdx][xIdx] == BAECHU)
                {
                    CheckBaechuArea(yIdx,xIdx, yMax, xMax, baechus);
                    areaCnt+=1;
                }
            }
        }
        cout << areaCnt << "\n";
    }
    return 0;
}