/* 적록색약
https://www.acmicpc.net/problem/10026

R G B 중에서 일반인은 전부 구별가능, 적록색약은 R G를 같은색으로 봄
일반인과 적록색약이 보는 각 RGB색깔 구역 총 개수를 각각 구하시오

입력
- N (1~100)
- 그림 (NxN)

출력
- 일반인_파악구역 적록색약_파악구역

풀이
- 구역체크니까 DFS가 편하겠다
- visited를 일반인, 적록색약 두개로 만들어서 체크하면 될듯
*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_grbCnt, g_noGrCnt;
vector<vector<char>> g_picture;
vector<vector<int>> g_grbVisited;
vector<vector<int>> g_noGrVisited;
vector<vector<int>> g_degree = {
    {-1,0}, {0,1}, {1,0}, {0,-1}
};

void CheckGrbArea(int startY, int startX, char color)
{
    for(int degIdx = 0; degIdx < 4; degIdx++)
    {
        int nextY = startY + g_degree[degIdx][0];
        int nextX = startX + g_degree[degIdx][1];
        if(nextY < 0|| nextX < 0|| nextY >= g_N|| nextX >= g_N)
            continue;
        if(g_picture[nextY][nextX] != color || g_grbVisited[nextY][nextX] !=0)
            continue;
        
        g_grbVisited[nextY][nextX] = 1;
        CheckGrbArea(nextY, nextX, color);
    }
}

void CheckNoGrArea(int startY, int startX, char color)
{
    for(int degIdx = 0; degIdx < 4; degIdx++)
    {
        int nextY = startY + g_degree[degIdx][0];
        int nextX = startX + g_degree[degIdx][1];
        if(nextY < 0|| nextX < 0|| nextY >= g_N|| nextX >= g_N)
            continue;
        if((color == 'R' || color == 'G') && g_picture[nextY][nextX] == 'B')
            continue;
        else if(color == 'B' && g_picture[nextY][nextX] != 'B')
            continue;
        if(g_noGrVisited[nextY][nextX] !=0)
            continue;
        
        g_noGrVisited[nextY][nextX] = 1;
        CheckNoGrArea(nextY, nextX, color);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N;
    g_picture.resize(g_N, vector<char>(g_N));
    g_grbVisited.resize(g_N, vector<int>(g_N));
    g_noGrVisited.resize(g_N, vector<int>(g_N));
    for(int inY = 0; inY < g_N; inY++)
    {
        for(int inX = 0; inX < g_N; inX++)
            cin >> g_picture[inY][inX];
    }

    for(int loopY = 0; loopY < g_N; loopY++)
    {
        for(int loopX = 0; loopX < g_N; loopX++)
        {
            if(g_grbVisited[loopY][loopX] == 0)
            {
                g_grbVisited[loopY][loopX] = 1;
                CheckGrbArea(loopY, loopX, g_picture[loopY][loopX]);
                g_grbCnt++;
            }
            if(g_noGrVisited[loopY][loopX] == 0)
            {
                g_noGrVisited[loopY][loopX] = 1;
                CheckNoGrArea(loopY, loopX, g_picture[loopY][loopX]);
                g_noGrCnt++;
            }
        }
    }
    // cout << "g_grbVisited\n";
    // for(auto y : g_grbVisited)
    // {
    //     for(auto x: y)
    //         cout << x << " ";
    //     cout << "\n";
    // }

    // cout << "\ng_noGrVisited\n";
    // for(auto y : g_noGrVisited)
    // {
    //     for(auto x: y)
    //         cout << x << " ";
    //     cout << "\n";
    // }

    cout << g_grbCnt << " " << g_noGrCnt;
    return 0;
}