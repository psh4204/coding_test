/* https://www.acmicpc.net/problem/7576
토마토

익은토마토 근처 4방향은 영향을 받아 익게됨.
익은토마토와 익지않은 토마토정보를 받았을때, 모두 익게되는 최소의 일수를 구하자.
일부상자에는 토마토가 없을 수 있다.

입력
- M N (가로, 세로 상자수. 2~1000)
- 토마토정보 (1 익음. 0 익지않음. -1 없음)
출력
- 최소일수 (못익으면 -1출력)

풀이
- BFS로 레벨링 해야 할 것으로 보임.
- 익은토마토 들을 큐에 다 넣고 순회돌리자.
*/
#include <bits/stdc++.h>
using namespace std;
struct eek_tomato_t{ // 익은 토마토~
    int y;
    int x;
    int time;
};
int _M, _N;
int _dy[4] = {-1,0,1,0};
int _dx[4] = {0,1,0,-1};

vector<vector<int>> _box;
queue<eek_tomato_t> e_toms;
eek_tomato_t last_tom;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _M >> _N;
    _box.resize(_N, vector<int>(_M));
    for(int y = 0; y < _N; y++)
    {
        for(int x = 0; x < _M; x++)
        {
            cin >> _box[y][x];
            if(_box[y][x] == 1)
                e_toms.push({y, x, 0});
        }
    }

    // //[[TEST]]
    // cout << "\n";
    // for(auto y: _box)
    // {
    //     for(auto x: y)
    //     {
    //         cout << x << " ";
    //     }
    //     cout << "\n";
    // }

    while (e_toms.size())
    {
        eek_tomato_t here = e_toms.front();
        e_toms.pop();
        for(int n_idx = 0; n_idx < 4; n_idx++)
        {
            eek_tomato_t n_tom = here;
            n_tom.y = here.y + _dy[n_idx];
            n_tom.x = here.x + _dx[n_idx];
            n_tom.time = here.time + 1;
            if(n_tom.y >= _N || n_tom.x >= _M || n_tom.y < 0 || n_tom.x < 0 || _box[n_tom.y][n_tom.x] != 0)
                continue;
            _box[n_tom.y][n_tom.x] = 1;
            e_toms.push(n_tom);
            last_tom = n_tom;
        }
    }

    // //[[TEST]]
    // cout << "\n";
    // for(auto y: _box)
    // {
    //     for(auto x: y)
    //     {
    //         cout << x << " ";
    //     }
    //     cout << "\n";
    // }

    // check toms are eek?
    for(auto y: _box)
    {
        for(auto x: y)
        {
            if(x == 0)
            {
                cout << -1;
                return 0;
            }
        }
    }
    cout << last_tom.time;
    return 0;
}