/*
차량이동가능 시나리오수 카운트하기.
0은 길, 1은 벽.
nxn 지도.
차량은 m개의 지점을 순서대로 방문하려함. 상하좌우 움직임가능. 벽 못지나가고, 한번지나간곳은 못지나감.
이동가능한 서로다른 가지수 카운트하기.

첫지점 -> 마지막 지점.

입력
- n (지도크기 2~4) m (지점 수)
- 지점 x y 배열

출력
- 방문할 수 있는 가지수 출력
- 불가능하면 0.

풀이
- DFS를 통한 지점방문.
- 완탐하고, 타겟이 차례로 통과됐는지를 카운트를 세자.
*/
#include<bits/stdc++.h>
using namespace std;
int _N, _M, _ret_cnt;
enum land_t{
    ROAD =0,
    WALL,
    CHECKED,
};
struct point_t{
    int y;
    int x;
};
vector<point_t> _points;
vector<vector<int>> _land;
int _dy[4] = {-1, 0, 1, 0};
int _dx[4] = {0, 1, 0, -1};

inline void go_end_point(point_t here, vector<point_t> trace)
{
    if(here.y == _points[_M-1].y && here.x == _points[_M-1].x)
    {
        if(trace.size() < _M) return;
        int p_cnt = 1; // 이미 trace에 첫번째 지점은 저장되어있어서 1로 함.
        for(int t_cnt = 1; t_cnt < trace.size(); t_cnt++)
        {
            if(trace[t_cnt].y == _points[p_cnt].y && trace[t_cnt].x == _points[p_cnt].x)
                p_cnt++;
        }
        if(p_cnt == _M) _ret_cnt++;
    }
    for(int n_idx = 0; n_idx < 4; n_idx++)
    {
        int ny = here.y + _dy[n_idx];
        int nx = here.x + _dx[n_idx];
        if(ny < 0 || nx < 0 || ny>= _N || nx >= _N) continue;
        if(_land[ny][nx] != ROAD) continue;

        //Check and GO
        _land[ny][nx] = CHECKED;
        trace.push_back({ny,nx});
        go_end_point({ny,nx}, trace);
        //Pop
        _land[ny][nx] = ROAD;
        trace.pop_back();
    }
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N >> _M;
    _land.resize(_N,vector<int>(_N));
    _points.resize(_M);
    for(int y_cnt = 0; y_cnt < _N; y_cnt++)
    {
        for(int x_cnt = 0; x_cnt <_N; x_cnt++)
            cin >> _land[y_cnt][x_cnt];
    }
    for(int m_cnt =0; m_cnt <_M; m_cnt++)
    {
        cin >> _points[m_cnt].y >> _points[m_cnt].x; 
        _points[m_cnt].y-=1;
        _points[m_cnt].x-=1;
    }

    // // TEST
    // for(auto y: _land)
    // {
    //     for(auto x: y)
    //         cout << x << " ";
    //     cout << "\n";
    // } 
    // for(int m_cnt =0; m_cnt <_M; m_cnt++)
    //     cout << _points[m_cnt].y <<" " <<_points[m_cnt].x <<"\n"; 
    // // ---

    vector<point_t> trace = {_points[0]};
    _land[_points[0].y][_points[0].x] = CHECKED;
    go_end_point(_points[0],trace);

    cout << _ret_cnt;
    
    return 0;
}