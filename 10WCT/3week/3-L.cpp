/* https://www.acmicpc.net/problem/1987
알파벳

RxC 보드. 칸마다 대문자알파벳. 좌측상단칸에 말이있음. (0,0)
상하좌우로 움직일수있고, 여태지나온 알파벳들과 중복불가.
말이 최대 몇칸지날수있는지 구하는 프로그램 작성.

Input
- R C (1~20)
- 보드

Output
- 최대칸수

Try1
- DFS로 하면 되겠다.
- 입력받을때 입력시 최대 카운트가 몇인지를 받아오자.
- 히스토리는 단순하게 visited 배열사용하면되는데
    - 26짜리 전역 vistied 쓰고, return 할때 받았던거 0으로 만들어줘야함.
- 정답카운트도 만들자.
*/
#include <bits/stdc++.h>
using namespace std;
int _R, _C, _max, _retcnt;
vector<vector<int>> _board;
vector<int> _apb_cnt(26);    // 입력받았을때 알파벳갯수 체크용
vector<int> _v(26);         // DFS를 통한 visited
int _dy[4] = {-1, 0, 1, 0};
int _dx[4] = {0, 1, 0, -1};

void srch_board(pair<int, int> here, int cnt)
{
    _v[_board[here.first][here.second]] = 1;
    if(cnt >= _retcnt)  _retcnt = cnt;
    if(_retcnt >= _max)
    {
        cout << _max;
        exit(0);
    }

    // cout << _board[here.first][here.second] << " ";

    for(int d = 0; d < 4; d++)
    {
        int ny = here.first + _dy[d];
        int nx = here.second + _dx[d];
        if(ny < 0 || nx < 0 || ny >= _R || nx >= _C)    continue;
        if(_v[_board[ny][nx]] == 0)
        {
            int n_cnt = cnt+1;
            srch_board({ny, nx}, n_cnt);
            // cout << "\n";
            _v[_board[ny][nx]] = 0;
        }
    }
}

int main()
{
    string input;
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _R >> _C;
    _board.resize(_R, vector<int>(_C));
    for(int r = 0; r < _R; r++)
    {
        cin >> input;
        for(int c = 0; c < _C; c++)
        {
            _board[r][c] = input[c] - 'A';
            _apb_cnt[_board[r][c]] = 1;
        }
    }
    for(auto apb : _apb_cnt)
        _max += apb;

    // /*   [[TEST CODE]]    */
    // cout << "\n" << _max << "\n";
    // for(int r = 0; r < _R; r++)
    // {
    //     for(int c = 0; c < _C; c++)
    //     {
    //         cout << _board[r][c] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    // /* --------------- */


    srch_board({0,0}, 1);
    cout << _retcnt;
    return 0;
}