/* https://www.acmicpc.net/problem/1189
컴백홈

한수는 집에 가고싶어하고, 한수위치는 왼쪽아래, 집은 오른쪽위이다.
한수는 집가는길은 다양하고, 다양한길을 겹쳐서 가지 않는다.
T는 지나가지 못하는 벽이다.
RxC의 맵과 집가는거리 K가 주어지면, 이 맵에서 K거리로 가는 경우의 수를 구하시오.

Input
- R C (1~5) K (1~25)
- .길 T벽

Output
- K길이의 집가는 거리 경우의수

Try
- 시간복잡도는 그렇게 안높을것으로 보임
- DFS로 완탐하면되고, visited 써서 길 안겹치게만 하면 될듯
- K거리로 도달하는 동시에 집에 도착했을때를 신경써야할듯
    - K거리로 도달했을 때 집인가? 를 체크하고, 아니면 return
- 심지어 visited도 그냥 지도 그대로 쓰면될듯
- 한수: _R-1,0 / 집: 0, _C-1
*/
#include <bits/stdc++.h>
using namespace std;
int _R, _C, _K, _ret;     // 한수: _R-1,0 / 집: 0, _C-1
int _dy[4] = {-1, 0, 1, 0};
int _dx[4] = {0, 1, 0, -1};
vector<vector<int>> _roads;

inline void go_home(pair<int,int> here, int cnt)
{
    if(cnt > _K) return;
    else if(cnt == _K)
    {
        if((here.first == 0 && here.second == _C-1) 
            && (_roads[0][_C-1] == 1))
        {
            _ret++;

            // // [[TEST CODE]]
            // cout << "\n";
            // for(auto r : _roads)
            // {
            //     for(auto c: r)
            //         cout << c << " ";
            //     cout << "\n";
            // }            
        }
        return;
    }
    for(int d = 0; d <4; d++)
    {
        int ny = here.first + _dy[d];
        int nx = here.second + _dx[d];
        if(ny < 0 || nx < 0 || ny >= _R || nx >= _C)    continue;
        if(_roads[ny][nx] != 0) continue;
        _roads[ny][nx] = 1;
        go_home({ny,nx}, cnt+1);
        _roads[ny][nx] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _R >> _C >> _K;
    _roads.resize(_R, vector<int>(_C));
    for(int r = 0; r < _R; r++)
    {
        for(int c = 0; c < _C; c++)
        {
            char in;
            cin >> in;
            if(in == 'T')
                _roads[r][c] = 2;
            else
                _roads[r][c] = 0;
        }
    }
    // // [[TEST CODE]]
    // cout << "\n";
    // for(auto r : _roads)
    // {
    //     for(auto c: r)
    //         cout << c << " ";
    //     cout << "\n";
    // }

    _roads[_R-1][0] =  1;
    go_home({_R-1, 0}, 1);
    
    cout << _ret;
    return 0;
}