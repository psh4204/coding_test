/* https://www.acmicpc.net/problem/4179
불

미로에 지훈이가 있는데 불도 함께났다.
지훈이는 불에타기전 탈출여부, 얼마나빨리 탈출할수있는지 체크해야한다.
불은 4방향확산.
지훈이는 미로의 중앙지점에 있음.
지훈이는 불있는 벽은 통과 불가

Input
- R C (1~100)
- 지도문자열(#벽 .공간 J지훈 F불)

Output
- 탈출가능: 가장빠른 탈출시간
- 탈출불가능: IMPOSSIBLE

Try1.
- 불들은 매 턴마다 4방향으로 번짐. (불은 워낙 많을거니.. 지도에만표시)
- 탈출구는 벽이없는 미로 끝자락. (맨끝에 도달하면 탈출)
- 불이 실시간으로 움직이는데.. 지훈이를 어떻게 그곳으로 보내야할까
    - DFS..로 하되 조합처럼 짜야함.
- 탈출불가능한 턴이 오면, 이전턴으로 다시 돌아온다.
    - 탈출불가능한 방향은 벽으로 체크한다.
- 메모리랑 시간만 봤을땐.. 단순 조합이나 BFS로는 안될것으로 보임
- 일단 지훈이가 먼저 움직인다는 가정하에 작성하자
- 불들이 번지는 카운트를 지도에 전부표시. 지훈이는 그 불카운트를 확인해서 불카운트중에서 가장큰카운트만 골라서간다..
    -불카운트로 예상해서 가장 늦게 불날거 같은곳으로 달려나간다 이말이지. 이때 이거만 DFS로 해결해본다.


5 5
#####
#F.J#
#...#
#.#.#
#.F.#


Try2
- 문제의 TC와 달리 좌표의 끝지점은 0, 그리고 _R-1, _C-1...
- 벽으로 불이 다 막혀있을 케이스까지 생각했어야했음..!!
- 문제가 좀 이상하다: 불이 먼저움직인다는 전제를 안깔았음
- 관련 TC들도 있어서 가져다 써봤음.
- TC: https://www.acmicpc.net/board/view/140963
- TC2: https://www.acmicpc.net/board/view/141761

*/
#include <bits/stdc++.h>
using namespace std;
#define WALL 2000
int _R, _C, _e_cnt;
vector<vector<int>> _miro;      // 미로 .. 공간0, 벽2000, 불1
pair<int,int> _jh;              // 지훈이 위치
queue<pair<int,int>> _fires;    // 불시작 위치
vector<vector<bool>> _fv;       // 불 방문지점
int _dy[4] = {-1, 0, 1, 0};
int _dx[4] = {0, 1, 0, -1};

void TEST();
void set_fires();
bool escape();

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _R >> _C;
    _miro.resize(_R,vector<int>(_C,0));
    _fv.resize(_R, vector<bool>(_C, false));
    for(int r= 0; r < _R; r++)
    {
        for(int c=0; c<_C; c++)
        {
            char in;
            cin >> in;;
            if(in == ',')   continue;
            else if(in == '#')  _miro[r][c] = WALL;
            else if(in == 'J')  _jh = {r,c};
            else if(in == 'F')
            {
                _miro[r][c] = 1;
                _fv[r][c] = false;
                _fires.push({r,c});
            }
        }
    }
    set_fires();
    if(escape())    cout << _e_cnt;
    else            cout << "IMPOSSIBLE";
    
    return 0;
}


void TEST()
{
    // TESTCODE
    cout << "\n";
    for(auto c: _miro)
    {
        for(auto r: c)
        {
            if(r == WALL)
                cout << "W";
            else
                cout << r;
            cout << " ";
        }
        cout << "\n";
    }
}

void set_fires()
{
    
    while(!_fires.empty())
    {
        pair<int,int> here = _fires.front();
        _fires.pop();
        for(int n = 0; n < 4; n++)
        {
            int ny = here.first + _dy[n];
            int nx = here.second + _dx[n];
            if(ny < 0 || nx < 0 || ny >= _R || nx >= _C)    continue;
            if(_miro[ny][nx] == 0 && _fv[ny][nx] == false)
            {
                _fv[ny][nx] = true;
                _miro[ny][nx] = _miro[here.first][here.second] + 1;
                _fires.push({ny, nx});
            }
        }
    }
}

bool escape()
{
    /* 
    Wall 을 피해 자신보다 큰 카운트값만 다녀보자.

    탈출조건
    - 자신의 위치에서 자신의 카운트보다 더큰 값들을 따라간다. (BFS로 분신술 써도 상관없잖아)
    - 끝에 도달했을때 인덱스가 끝을(_R-1 or _C-1) 가리킨다면 탈출.
    
    Imposible 조건
    - 움직이는데 사방이 자신의 카운트보다 작거나 같으면 Fail
    - 끝에 도달했는데 끝이 아닐경우
    */
    queue<pair<pair<int,int>, int>> w_n_c;   // way and count
    vector<vector<bool>> qv(_R,vector<bool>(_C, false));
    w_n_c.push({{_jh.first,_jh.second}, 1});
    qv[_jh.first][_jh.second] = true;
    bool is_escape = false;
    do
    {
        pair<int,int> here = w_n_c.front().first;
        int e_cnt = w_n_c.front().second;
        w_n_c.pop();
        if(here.first == 0 || here.second == 0 || here.first == _R-1 || here.second == _C-1)
        {
            is_escape = true;
            _e_cnt = e_cnt;
            break;
        }
        for(int n = 0; n < 4; n++)
        {
            int ny = here.first + _dy[n];
            int nx = here.second + _dx[n];
            if(ny < 0 || nx < 0 || ny >= _R || nx >= _C)    continue;
            if (_miro[ny][nx]!= WALL && (_miro[ny][nx] > e_cnt+1 || _miro[ny][nx] == 0 ) && qv[ny][nx] == false)
            {
                qv[ny][nx] = true;
                w_n_c.push({{ny, nx}, e_cnt+1});
            }
        }
    } while (!is_escape && !w_n_c.empty());

    return is_escape;
}