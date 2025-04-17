/* 헌내기는 친구가 필요해~
https://www.acmicpc.net/problem/21736

N M 대학캠퍼스
이동하는 법: 벽이아닌 상하좌우
- O: 빈공간
- X: 벽
- P: 사람

도연이가 만날 수 있는 사람수 체크~
*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_M, g_friends;
pair<int,int> g_doyeon;
vector<vector<char>> g_campus;
vector<vector<int>> g_visited;
vector<vector<int>> g_degree =
{
    {-1,0}, {0,1}, {1,0}, {0,-1}
};

void CheckPeopleBFS(const int &currY, const int &currX)
{
    queue<pair<int,int>> roadsQ;
    roadsQ.push({currY,currX});
    g_visited[currY][currX] = 1;
    while(!roadsQ.empty())
    {
        int oldY = roadsQ.front().first;
        int oldX = roadsQ.front().second;
        roadsQ.pop();
        for(int dIdx = 0; dIdx < 4; dIdx++)
        {
            int nextY = oldY + g_degree[dIdx][0];
            int nextX = oldX + g_degree[dIdx][1];
            if(nextY >= g_N || nextX >= g_M || nextY < 0 || nextX < 0
                || g_visited[nextY][nextX] == 1 || g_campus[nextY][nextX] == 'X')
                continue;
            if(g_campus[nextY][nextX] == 'P')
                g_friends+=1;
            roadsQ.push({nextY,nextX});
            g_visited[nextY][nextX] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N >> g_M;
    g_campus.resize(g_N, vector<char>(g_M));
    g_visited.resize(g_N, vector<int>(g_M, 0));
    for(int inY = 0; inY < g_N; inY++)
    {
        for(int inX = 0; inX < g_M; inX++)
        {
            cin >> g_campus[inY][inX];
            if(g_campus[inY][inX] == 'I')
                g_doyeon = {inY, inX};
        }
    }
    CheckPeopleBFS(g_doyeon.first, g_doyeon.second);
    if(g_friends == 0)
        cout << "TT";
    else
        cout << g_friends;
    return 0;
}