/* 함께하는 효도
m명의 친구를 불러서 부모님열매따기 봉사하려함.
n*n 격자에 나무가 있고, 열매가 남.
1초에 1번 상하좌우로 친구들이 움직일 수 있음.
모든 열매의 수확량을 최대로 하기로함.
열매는 딱한순간만 수확가능.
친구들은 이동경로가 겹치면 안됨.

m명의 친구들이 3초동안 최대로 얻을 수 있는 수확량은? (초사이어인?)

입력
- n m (밭크기 2~20, 친구수 1~3)
- 열매밭지도
- 친구위치(Y,X)

출력
- 3초간 최대열매수확량

풀이
- DFS로 각 친구들의 경로 중 최적의 값을 구한다.
- 첫번째 친구부터 시작해서, 가장 높은 값의 경로를 찾으면 - 그 다음친구선에서 또 최적의 값과 경로 ..
    - 반복
- 첫번째 친구가 끝났으면 두번째 친구부터 또 최적의 값과 경로... 이렇게 친구 하나하나 먼저 경로 구하면서 최적의 값을 찾는다.
- 친구 *친구 수만큼의 DFS가 동작할것임.

4 2
20 26 185 80
100 20 25 80
20 20 88 99
15 32 44 50
1 2
2 3

4 2
1 1 1 1
2 200 1 1
2 8 1 1
1 8 4 1
4 1
4 3
*/
#include<bits/stdc++.h>
using namespace std;
enum check_t{
    APPLE,
    FRIEND,
    CHECKED
};
struct point_t{
    int y = 0;
    int x = 0;
};
struct apple_t{
    int value = 0;
    check_t check = APPLE;
};
int _n, _m, _s_max, _max; // s_max: 서브루프에서 쓰일 맥스값. max: 최종 맥스값.
vector<vector<apple_t>> _apples;
vector<point_t> _trace;
vector<point_t> _friends; // {fri, fri, fri}
int _dy[4] = {-1, 0, 1, 0};
int _dx[4] = {0, 1, 0, -1};

void draw_route(vector<vector<apple_t>>& apples, vector<point_t>& trace)
{
    for(auto t: trace)
        apples[t.y][t.x].check = CHECKED;

    // // TEXT CODE ---
    // cout << _max << "\n";
    // for(auto r: apples)
    // {
    //     for(auto c: r)
    //         cout << c.check << " ";
    //     cout << "\n";
    // }
    // cout << "\n";
    // // ---
}

void get_value(point_t here, int cnt, int sum_val, vector<vector<apple_t>>& apples, vector<point_t>& trace)
{
    if(cnt == 3)
    {
        if(_s_max < sum_val)
        {
            // TEXT CODE ---
            for(auto t: trace)
                cout << t.y << "," << t.x << " ";
            cout << "\n";
            // ---
            _s_max = sum_val;
            _trace.clear();
            _trace = trace;
        }
        return;
    }
    for(int d_cnt = 0; d_cnt < 4; d_cnt++)
    {
        int ny = here.y + _dy[d_cnt];
        int nx = here.x + _dx[d_cnt];
        if(ny < 0 || nx <0 || ny >= _n || nx >= _n) continue;
        if(apples[ny][nx].check != APPLE) continue;
        int n_val = sum_val+apples[ny][nx].value;
        apples[ny][nx].check = CHECKED;
        trace.push_back({ny,nx});
        get_value({ny,nx}, cnt+1, n_val, apples, trace);
        apples[ny][nx].check = APPLE;
        trace.pop_back();
    }
}

int main(int argc, char** argv)
{
    cin >> _n >> _m;
    _apples.resize(_n, vector<apple_t>(_n));
    for(int r = 0; r < _n ; r++)
    {
        for(int c = 0; c < _n ; c++)
            cin >> _apples[r][c].value;
    }
    _friends.resize(_m);
    for(int m_cnt = 0; m_cnt < _m; m_cnt++)
    {
        cin >> _friends[m_cnt].y >> _friends[m_cnt].x;
        _friends[m_cnt].y -=1;
        _friends[m_cnt].x -=1;
        _apples[_friends[m_cnt].y][_friends[m_cnt].x].check = FRIEND; 
    }

        // TEXT CODE ---
    cout << _max << "\n";
    for(auto r: _apples)
    {
        for(auto c: r)
            cout << c.check << " ";
        cout << "\n";
    }
    cout << "\n";
    // ---
    
    for(int f_cnt = 0; f_cnt < _m; f_cnt++)
    {
        int max_cnt = 0;
        vector<vector<apple_t>> apples_cpy = _apples;
        vector<point_t> trace;
        _s_max = 0;
        _s_max += _apples[_friends[f_cnt].y][_friends[f_cnt].x].value;
        trace.push_back(_friends[f_cnt]);
        get_value(_friends[f_cnt], 0, _s_max, apples_cpy, trace);
        draw_route(apples_cpy, _trace);
        max_cnt += _s_max;
        for(int s_cnt = 0; s_cnt< _m; s_cnt++) // sub_friend count
        {
            if(s_cnt == f_cnt) continue;
            // TEXT CODE ---
            cout << _max << "\n";
            for(auto r: apples_cpy)
            {
                for(auto c: r)
                    cout << c.check << " ";
                cout << "\n";
            }
            cout << "\n";
            // ---
            trace.clear();
            trace.push_back(_friends[s_cnt]);
            _s_max = 0;
            _s_max += _apples[_friends[s_cnt].y][_friends[s_cnt].x].value;
            get_value(_friends[s_cnt], 0, _s_max, apples_cpy, trace);
            max_cnt += _s_max;
            draw_route(apples_cpy, _trace);
        }
        _max = max(_max, max_cnt);
        // TEXT CODE ---
        cout << _max << "\n";
        for(auto r: apples_cpy)
        {
            for(auto c: r)
                cout << c.check << " ";
            cout << "\n";
        }
        cout << "\n";
        // ---
    }
    cout << _max;
    return 0;
}