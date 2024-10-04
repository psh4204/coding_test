/* https://www.acmicpc.net/problem/17144
미세먼지 안녕!

RxC 격자판위에 미세먼지.
공기청정기는 1번C에 항상 설치됨. 

1초다동안 아래의 적힌일이 순서대로 일어난다.
1. 미세먼지 확산. 모든칸에서 동시에 일어남
    - 미세먼지는 네방향으로 확산
    - 공기청정기쪽 으로는 확산 X
        - *미세먼지는 서로 확산되면서 더해짐.
    - 확산되는 양은 A(r,c)/5. 무조건 정수.
    - (r,c)에 남은 먼지양은 A(r,c) - [A(r,c)/5]x(확산된 방향의 개수)
2. 공기청정기 작동
    - 공기청정기에서는 바람이 나온다.
    - 위쪽 공기청정기는 바람이 반시계방향으로 순환, 
      아래쪽은시계방향으로 순환
    - 바람이 불면 방향대로 모두 한칸씩 이동한다.
    - 공기청정기에서 부는 바람은 미세먼지가 없는 바람.
      공기청정기로 들어간 미세먼지는 모두 정화.
        - *공기청정기 위아래로 공기 빨려드가면 값 사라짐.

Input
- R C T(R C 6~50, T 1~1000)
- 지도. (공기청정기 -1 위아래로 두개, 나머지는 공기상태)

Output
- T초가 지난후 방에 남은 먼지양을 출력한다.

Try1
- 구현을 우선 해야할듯
    - 루프문으로 먼지배포. 이전의 지도에서 새 지도를 만드는 형식으로 해야할듯
    - 공기청정기 움직임
- 구현 후에 최적화 하는 방식으로 가자.

Try2
- 세부 구현에서 틀린듯
회전체크용
8 8 2
7 6 5 4 3 2 1 0
8 0 0 0 0 0 0 9
9 0 0 0 3 0 0 8
-1 1 2 3 4 5 6 7
-1 1 2 3 4 5 6 7
9 0 0 0 0 10 43 8
8 0 5 0 15 0 0 9
7 6 5 4 3 2 1 0

https://www.acmicpc.net/board/view/66441
반례1: 답 191 (잡음)
8 8 2
3 0 0 0 0 0 0 0
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0

공기청정기 위치가 (n,0) 아무데나 있을 때.
반례2: 답 68
4 6 4
0 0 9 8 7 6
-1 1 2 3 4 5
-1 1 2 3 4 5
1 0 9 8 7 6

반례3: 답 64
4 6 4
-1 1 2 3 4 5
-1 1 2 3 4 5
4 0 0 0 0 6
3 2 1 0 8 7


*/
#include <bits/stdc++.h>
using namespace std;
int _R, _C, _T, _ret;
vector<vector<int>> _room;
vector<pair<int,int>> _cleaner;

int _dy[4] = {-1, 0 ,1, 0};
int _dx[4] = {0, 1, 0, -1};

inline vector<vector<int>> process_dust(vector<vector<int>> &pre_room)
{
    vector<vector<int>> now_room(_R,vector<int>(_C));
    for(int r = 0; r < _R; r++)
    {
        for(int c = 0; c < _C; c++)
        {
            if(pre_room[r][c]==0) continue;
            else if(pre_room[r][c] == -1)
            {
                now_room[r][c] = -1;
                continue;
            }
            int dust = pre_room[r][c];
            int dust_cnt = 0;
            for(int d_idx = 0; d_idx < 4; d_idx++)
            {
                int ny = _dy[d_idx] + r;
                int nx = _dx[d_idx] + c;
                if(ny < 0 || nx < 0 || ny >= _R || nx >= _C || pre_room[ny][nx] == -1)
                    continue;
                dust_cnt++;
                now_room[ny][nx] += (int)(dust/5);
            }
            now_room[r][c] += (dust -((int)(dust/5)*dust_cnt));
        }
    }

    return now_room;
}

inline vector<vector<int>> process_cleaner(vector<vector<int>> &pre_room)
{
    // room copy
    vector<vector<int>> now_room(pre_room);
    // Cleaner 0 -->
    pre_room[_cleaner[0].first][_cleaner[0].second] =0; 
    for(int nx = 1; nx < _C; nx++) // (y,x+1)
        now_room[_cleaner[0].first][nx] = pre_room[_cleaner[0].first][nx-1];
    // Cleaner 0 UP
    for(int ny = _cleaner[0].first -1; ny >=0; ny--) //(y-1,_C-1)
        now_room[ny][_C-1] = pre_room[ny+1][_C-1];
    // Cleaner 0 <--
    for(int nx = _C-2; nx >= 0; nx--) // (0, C-2)
        now_room[0][nx] = pre_room[0][nx+1];
    // Cleaner 0 Down
    for(int ny = 1; ny <_cleaner[0].first; ny++) // (1, 0)
        now_room[ny][0] = pre_room[ny-1][0];
    now_room[_cleaner[0].first][0] = -1;

    // Cleaner 1 -->
    pre_room[_cleaner[1].first][_cleaner[1].second] =0;
    for(int nx = 1; nx < _C; nx++) // (y,x+1)
        now_room[_cleaner[1].first][nx] = pre_room[_cleaner[1].first][nx-1];
    // Cleaner 1 Down
    for(int ny = _cleaner[1].first+1; ny <=_R-1; ny++) // (y+1,_C-1)
        now_room[ny][_C-1] = pre_room[ny-1][_C-1];
    // Cleaner 1 <--
    for(int nx = _C-2; nx >= 0; nx--) // (_R-1, _C-2)
        now_room[_R-1][nx] = pre_room[_R-1][nx+1];
    // Cleaner 1 Up
    for(int ny = _R-2; ny >_cleaner[1].first; ny--) // (_R-2, 0)
        now_room[ny][0] = pre_room[ny+1][0];
    now_room[_cleaner[1].first][0] = -1;

    return now_room;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> _R >> _C >> _T;
    _room.resize(_R, vector<int>(_C));
    for(int r = 0; r <_R; r++)
    {
        for(int c =0; c < _C; c++)
        {
            cin >> _room[r][c];
            if(_room[r][c] == -1)
                _cleaner.push_back({r,c});
        }
    }
    for(int t_cnt = 0; t_cnt < _T; t_cnt++)
    {
        _room = process_dust(_room);
        _room = process_cleaner(_room);

        // //[[TESTCODE]]
        // cout << "\n [ " << t_cnt << " ]\n";
        // for(auto r: _room)
        // {
        //     for(auto c: r)
        //         cout << c << " ";
        //     cout << "\n";
        // }
    }
    for(int y =0 ; y < _R; y++)
    {
        for(int x = 0; x < _C; x++)
        {
            if((_cleaner[0].first == y && _cleaner[0].second == x)
                || (_cleaner[1].first == y && _cleaner[1].second == x))
                continue;
            _ret+=_room[y][x];
        }
    }
    cout << _ret;
    return 0;
}