/*
https://www.acmicpc.net/problem/2178
미로탐색

NxM 미로. (1,1) 출발하여 끝점(N,M)으로 이동핳ㄹ 때 지나야하는 최소한의 칸수를 구하는 프로그램.
한칸씩움직일 수 있으며, 인접한 칸으로만 움직일 수 있다.

Try1.
- 문제에서 맵으로 보여주네.
    - array를 인접행렬로 표현하자.
    - 4방향으로 움직일 수 있다.
    - 최단거리 = BFS.
        - 지도와, 방문예정-방문한 지도를 (2차원배열들) 만들어서 BFS하자.
*/
#include <bits/stdc++.h>
using namespace std;
int _y = 0, _x = 0;
int _dy[] = {-1, 0, 1, 0};
int _dx[] = {0, 1, 0, -1};
vector<vector<int>> _array_map;
vector<vector<int>> _visited;   // will visit and visited array

void init_array_and_visited()
{
    cin >> _y >> _x;
    for(int y_cnt = 0; y_cnt < _y; y_cnt++)
    {
        string user_input;
        cin >> user_input;
        _array_map.push_back({});
        _visited.push_back({});
        for(auto ch: user_input)
        {
            _array_map[y_cnt].push_back(ch -'0');
            _visited[y_cnt].push_back(0);
        }
    }
}

void check_weight_and_push_ways(int here_y, int here_x, queue<pair<int,int>> &q)
{
    for(int idx = 0; idx < 4; idx++)
    {
        int ny = here_y+_dy[idx];
        int nx = here_x+_dx[idx];
        if(ny < 0 || nx < 0 || ny >= _y || nx >= _x)
            continue; 
        if(_array_map[ny][nx] == 1 && _visited[ny][nx] == 0)
        {
            q.push({ny, nx});
            _visited[ny][nx] = _visited[here_y][here_x] + 1;
        }
    }
}

void search_with_bfs()
{
    queue<pair<int,int>> q;
    _visited[0][0] = 1;
    q.push({0,0});
    do
    {
        pair<int,int> here_yx = q.front();
        q.pop();
        if(here_yx == pair<int,int>{_y-1, _x-1})
        {
            cout << _visited[here_yx.first][here_yx.second];
            exit(0);
        }
        check_weight_and_push_ways(here_yx.first, here_yx.second, q);
    } while (q.empty() == false);
    
}

int main()
{
    init_array_and_visited();
    search_with_bfs();
}