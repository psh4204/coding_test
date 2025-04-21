/* 쉬운 최단거리
https://www.acmicpc.net/problem/14940

0: 벽
2: 타겟

각 지점에서 2까지의 최소거리를 전부 구하라

입력
- N M (1~1000)
- 지도

출력
- 최단거리
    - 갈수없으면 -1, 벽은 0, 2는 0

풀이
- BFS문제
- 2에서 각 지점에 최소거리를 입력하는 식으로 하면 될듯
- 그리고 못가는 애들 체크를 위해 전부 -1로된 visited 만들면될듯
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g_inputs;
vector<vector<int>> g_answers;
int g_N, g_M;
pair<int,int> g_start;
vector<vector<int>> g_degrees = {{-1,0}, {0,1}, {1,0}, {0,-1}};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N >> g_M;
    g_inputs.resize(g_N, vector<int>(g_M));
    g_answers.resize(g_N, vector<int>(g_M, -1));
    for(int inY = 0; inY < g_N; inY++)
    {
        for(int inX = 0; inX < g_M; inX++)
        {
            cin >> g_inputs[inY][inX];
            if(g_inputs[inY][inX] == 0)
                g_answers[inY][inX] = 0;
            else if(g_inputs[inY][inX] == 2)
            {
                g_start.first = inY;
                g_start.second = inX;
            }
        }
    }

    queue<pair<int,int>> searchQ;
    searchQ.push(g_start);
    g_answers[g_start.first][g_start.second] = 0;
    do{
        pair<int, int> now = searchQ.front(); 
        searchQ.pop();
        for(int degree = 0; degree < 4; degree++)
        {
            int nextY = now.first + g_degrees[degree][0];
            int nextX = now.second + g_degrees[degree][1];
            if(nextY < 0|| nextX < 0|| nextY >=g_N|| nextX>=g_M
                ||g_answers[nextY][nextX] != -1)
                continue;
            searchQ.push({nextY,nextX});
            g_answers[nextY][nextX] = g_answers[now.first][now.second] + 1;
        }
    }while(!searchQ.empty());

    for(int outY = 0; outY < g_N; outY++)
    {
        for(int outX = 0; outX < g_M; outX++)
        {
            cout << g_answers[outY][outX];
            if(outX == g_M-1)
                cout << "\n";
            else
                cout << " ";
        }
    }
    return 0;
}