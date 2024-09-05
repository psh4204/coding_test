/* https://www.acmicpc.net/problem/3197
백조의 호수

RxC 호수가있고, 백조는 2마리가있음.
얼음은 4방향으로 녹고, 백조도 4방향만으로 만날수있다.
몇일이 지나야 백조가 만날 수있는 지 프로그램 작성 ㄱㄱ

Input
- R C (1~1500)
- . L .....( L 백조. 'X' 얼음. '.' 물)

Output
- 만나는 최단시간

Try1
- 얼음 pair 벡터.(주위에 물있으면 녹음).
    - 바로 erase하지말고, 안녹은 친구를 탐색안하는 기법으로 가자.
- 백조 탐색 BFS.(백조가 물만 visited해서 탐색)
- 물0, 얼음1, 백조2, 탐색된물3.

Try2
- 시간초과됐음.
- 멀 줄여야할까..
    - 플루드필을 활용한 MeltIce 담기로 얼음쪽 최적화 하자.

Try3
- 47퍼 틀림..!
- 반례: 백조가 떠있는곳은 어디 ---> 물
*/
#include <bits/stdc++.h>
using namespace std;
int _R, _C, _days;
vector<vector<int>> _lake;
queue<pair<int,int>> _ices;
vector<pair<int,int>> _birds;
queue<pair<int,int>> _q;
int _dy[4] = {-1, 0, 1, 0};
int _dx[4] = {0, 1, 0, -1};

enum lake_t
{
    WATER       = 0,
    ICE         = 1,
    BIRD        = 2,
    CHKED_WATER = 3,
    CHKED_BIRD  = 4,
    MELT_ICE    = 5,
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _R >> _C;
    _lake.resize(_R,vector<int>(_C));
    string in_str;
    getline(cin, in_str);
    for(int r = 0 ; r < _R; r++)
    {
        getline(cin, in_str);
        for(int c = 0; c< _C; c++)
        {
            char ch = in_str[c];
            if(ch == '.')
            {
                _lake[r][c] = WATER;
            }
            else if(ch == 'X')
            {
                _lake[r][c] = ICE;
                _ices.push({r,c});
            }
            else if(ch == 'L')
            {
                _lake[r][c] = BIRD;
                _birds.push_back({r,c});
            }
        }
    }
    if(_ices.empty())
    {
        cout << 0;
        return 0;
    }
    _q.push(_birds[0]);
    do
    {
        // 백조찾기삼만리~를 하되, 오도가도못하는 가상의백조는 큐에 따로 넣어준다.
        // 이미 방문한 물은 E으로 표시
        vector<pair<int,int>> no_find_list;
        do
        {
            pair<int,int> here = _q.front(); _q.pop();
            bool is_no_find = false;
            for(int d = 0; d < 4; d++)
            {
                int ny = here.first + _dy[d];
                int nx = here.second + _dx[d];
                if(ny < 0 || nx < 0 || ny >=_R || nx >=_C)  continue;
                if(_lake[ny][nx] == WATER)
                {
                    _q.push({ny,nx});
                    _lake[ny][nx] = CHKED_WATER;
                }
                else if(_lake[ny][nx] == ICE) is_no_find = true;
                else if(_lake[ny][nx] == BIRD) _lake[ny][nx] = CHKED_BIRD; 
            }
            // 옆에 얼음있는채로 멈춰있는 가상의 백조를 따로 저장해둔다.
            if(is_no_find)
                no_find_list.push_back(here);
        } while (!_q.empty());

        // // [[TEST CODE]]
        // cout << "\n" << _days << "\n";
        // for(int y = 0 ; y < _R; y++)
        // {
        //     for(int x = 0; x <_C; x++)
        //         cout << _lake[y][x];
        //     cout << "\n";
        // }

        if(_lake[_birds[1].first][_birds[1].second] == CHKED_BIRD) 
            break; //얼음 다녹았을때 혹은 백조를 찾았을때

        for(auto no_find: no_find_list) _q.push(no_find);
        
        _days++;
        // 얼음녹이기... 방금녹인물은 물로안치게해야함. 그리고 큐와함께 플루드 필로 최적화 하자.
        vector<pair<int,int>> melt_ices;
        int ice_size = _ices.size();
        for(int i_idx = 0; i_idx < ice_size; i_idx++)
        {
            pair<int,int> here_ice = _ices.front(); _ices.pop();
            for(int d = 0; d < 4; d++)
            {
                int ny = here_ice.first + _dy[d]; 
                int nx = here_ice.second + _dx[d];
                if(ny < 0 || nx < 0 || ny >=_R || nx >=_C)  continue;
                if((_lake[here_ice.first][here_ice.second] == WATER 
                    || _lake[here_ice.first][here_ice.second] == CHKED_WATER
                    || _lake[here_ice.first][here_ice.second] == BIRD)
                    && _lake[ny][nx] == ICE)
                {
                    _lake[ny][nx] = MELT_ICE;
                    melt_ices.push_back({ny, nx});
                }
                else if((_lake[here_ice.first][here_ice.second] == ICE ) &&
                    (_lake[ny][nx] == WATER || _lake[ny][nx] == CHKED_WATER
                    ||_lake[ny][nx] == BIRD))
                {
                    _lake[here_ice.first][here_ice.second] = MELT_ICE;
                    melt_ices.push_back(here_ice);
                    break;
                }
            }
        }
        for(auto melt: melt_ices)
        {
            _lake[melt.first][melt.second] = 0;
            _ices.push(melt);
        }
    } while (_lake[_birds[1].first][_birds[1].second] != CHKED_BIRD);

    cout << _days;

    return 0;
}