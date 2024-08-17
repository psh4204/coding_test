/* https://www.acmicpc.net/problem/2636
치즈

NxM의 판에 치즈가 놓여져 있으며, 테두리의 칸에는 치즈가 안놓여짐.
1로 표시된 구역이 치즈가 놓인부분이고, 가에서 부터 0과 닿은 부분들은 한시간뒤에 사라짐.
이렇게 완전히 치즈가 사라지는 시간과, 완전히 사라지기 한시간 전 치즈의 개수를 적어라.

Input
- N, M
- Array

Output
- 완전히 사라지는데 걸리는 시간
- 완전삭제1시간전 치즈개수

Try1.
- 테두리 부분(0,0~)에서 시작한 0의 4방향으로 1의 가부분을 체크할 수 있음.
- 1의 가부분을 가져온 후 1루프 후 삭제하는 시퀀스 작성
- 다 삭제후 몇번 카운트했는지 체크. 그리고 마지막 치즈개수로 return.
*/
#include <bits/stdc++.h>
using namespace std;
int _Y, _X, _hour;
int _dy[4] ={-1,0,1,0};
int _dx[4] ={0,1,0,-1};
vector<vector<int>> _box;   // 치즈를 담을 박스
set<pair<int,int>> _c_list;   // 치즈의 가부분
set<pair<int,int>> _pre_c_list;

void set_c_list()
{
    // (0,0)을 시작으로 주위에 값이 1인 pair들을 c_list에 쌓는다. (중복되지않게 set사용)
    vector<vector<int>> copy_box(_box); // vistied box. 방문한 0은 3이 된다.
    queue<pair<int,int>> q;
    _c_list.clear();
    q.push({0,0});
    while(!q.empty())
    {
        pair<int,int> here = q.front();
        copy_box[here.first][here.second] = 3;
        q.pop();
        for(int idx=0; idx<4; idx++)
        {
            int ny = here.first + _dy[idx];
            int nx = here.second+ _dx[idx];
            if(ny <0 || nx <0 || ny >= _Y || nx >= _X)
                continue;
            switch(copy_box[ny][nx])    // 0나오면 방문표시 후 bfs, 1나오면 set c_list
            {
                case 0:
                    copy_box[ny][nx] = 3;
                    q.push({ny,nx});
                    break;
                case 1:
                    _c_list.insert({ny,nx});
                    break;
                default:
                    break;
            } 
        }
    }
}

int rm_cheese()
{
    int rm_cnt = 0;
    for(auto c: _c_list)
    {
        rm_cnt++;
        _box[c.first][c.second] = 0;
    }

    if(rm_cnt == 0)
        return 0;
    return 1;
}

int main()
{
    cin >> _Y >> _X;
    for(int y = 0; y < _Y; y++)
    {
        _box.push_back({});
        for(int x = 0; x <_X; x++)
        {
            int val = 0;
            cin >> val;
            _box[y].push_back(val);
        }
    }

    do
    {
        _pre_c_list = _c_list;
        set_c_list();
        _hour += rm_cheese();
    } while (!_c_list.empty());
    cout << _hour << "\n";
    cout << _pre_c_list.size() << "\n";
    
    return 0;
}