/* https://www.acmicpc.net/problem/2234
성곽

점선과 굵은선으로 이루어진 성의 지도를 입력받는다.
확인할 것
- 방의개수
- 가장 넓은 방의 넓이
- 하나의 벽을 제거했을때 얻을 수 있는 가장 넓은 방의 크기

성은  MxN (1~M,N~50) 임. 성은 최소 2개의 방이 있음.

Input
- N, M
- M개 줄로 N개의 벽정보를 줌
    - 서쪽벽 1, 북쪽벽 2, 동쪽벽 4, 남쪽벽 8. (4비트정보)

Output
- 입력받은 성벽 방의 개수
- 입력받은 성벽 방의 중 가장 넓은 방 넓이
- 벽하나를 제거했을 때 가장 넓은 방 넓이


Try1 (복잡 할 수록 단순 무식하게)
- 방 하나 하나 잡을때 비트마스킹해서 배열화 시킨다.
    - "서쪽"을 중심으로 "시계방향"으로 방향이 잡혀있음.
- 방개수 탐색은 DFS와 visited 로 한다.
    - 가장 큰 방의 넓이정보를 리턴한다.
- 벽을 없앤후 가장큰방 구하기: 벽 없앤 방으로 부터 넓이를 리턴한다.
    - 모든 방의 벽을 하나씩 허물며, 그 지점에서 DFS로 방크기 체크
        - 테두리방을 제외하고 싶으나, 성이 작을경우 조건성립이 안됨. 
    - 그러면서 가장 큰방을 체크한다.
    - 벽을 허물땐 옆 방의 정보도 수정해줘야한다

Try2.
- 4% 오답
- TC1에서는 정답인데 아래의 반례에서 카운트를 +1 해줌.
4 1
15 15 15 15

- 보니까 벽을 열고, 안닫았네.. ㅋㅋㅋ 뭐지? 닫았지않았어?
    - 옆 벽을 안닫고있었음. TC는 운좋아서 풀린듯
    - TODO: 다음부터는 위와같이 극단적이고 심플한 TC하나 만들고 테스트해가며 해보자.
*/
#include <bits/stdc++.h>
using namespace std;
int _M, _N, _room_cnt, _max_size, _vcnt;
vector<vector<int>> _castle;
vector<vector<int>> _v;
int _dy[4] = {0,-1,0,1};
int _dx[4] = {-1,0,1,0};

inline int get_room_size(pair<int,int> here)
{
    int size = 1;
    _v[here.first][here.second] = 1;
    // cout << here.first << "," << here.second << " ";  // [[TESTCODE]]
    for(int d = 0; d < 4; d++)
    {
        if((_castle[here.first][here.second] & (1<<d)) == 0)
        {
            int ny = here.first + _dy[d];
            int nx = here.second + _dx[d];
            if(ny <0 || nx <0 || ny >= _M || nx >= _N)  continue;
            if(_v[ny][nx]) continue;
            size += get_room_size({ny, nx});
        }
    }
    return size;
}

inline int get_room_size_at_breakwell(pair<int,int> here)
{
    int size = 1;
    _v[here.first][here.second] = _vcnt;
    // cout << here.first << "," << here.second << " ";  // [[TESTCODE]]
    for(int d = 0; d < 4; d++)
    {
        if((_castle[here.first][here.second] & (1<<d)) == 0)
        {
            int ny = here.first + _dy[d];
            int nx = here.second + _dx[d];
            if(ny <0 || nx <0 || ny >= _M || nx >= _N)  continue;
            if(_v[ny][nx] == _vcnt) continue;
            size += get_room_size_at_breakwell({ny, nx});
        }
    }
    return size;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N >> _M;
    _castle.resize(_M, vector<int>(_N)); _v = _castle;
    for(int y = 0; y < _M; y++)
    {
        for(int x = 0; x < _N; x++)
        {
            int room = 0; cin >> room;
            _castle[y][x] = room;
        }
    }
    // get room_cnt, first _max_ret;
    for(int y = 0; y < _M; y++)
    {
        for(int x = 0; x < _N; x++)
        {
            if(_v[y][x]) continue;
            _room_cnt++;
            int room_size = get_room_size({y,x});
            _max_size = max(room_size, _max_size);
            // cout << " : " << room_size << "\n"; // [[TESTCODE]]
        }
    }
    cout << _room_cnt << "\n" << _max_size << "\n";
    _v.clear();
    _v.resize(_M,vector<int>(_N));
    // get max_size with break_well.
    for(int y = 0; y < _M; y++)
    {
        for(int x = 0; x < _N; x++)
        {
            for(int d = 2; d < 4; d++)  // 남,동 쪽 벽만 부시는게 효율적인거 같음.
            {
                _vcnt++;
                if((_castle[y][x] & (1<<d)) == 0) continue;
                int ny = y + _dy[d]; 
                int nx = x + _dx[d];
                if(ny <0 || nx <0 || ny >= _M || nx >= _N)  continue;
                 // 부시기
                _castle[y][x] &= ~(1<<d);
                _castle[ny][nx] &= ~(1<<(d-2));   // 옆방 벽도 같이 부셔야함
                int room_size = get_room_size_at_breakwell({y,x});
                _max_size = max(room_size, _max_size);
                // cout << " : " << room_size << "\n";  // [[TESTCODE]]
                // 복구
                _castle[y][x] |= (1<<d);
                _castle[ny][nx] |= (1<<(d-2));
            }
        }
    }
    cout << _max_size;

    return 0;
}