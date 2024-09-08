/* https://www.acmicpc.net/problem/14620
꽃길

NxN 화단에 씨앗(총3개)을 심으면, 1년 뒤에 꽃잎이 4방향으로 펼쳐지며 만개한다.
화단을 나가던지 꽃잎이던 뭐든 겹지면 그꽃은 죽어버린다.
화단 지점마다 대여료가 다른데, 꽃을 만개하면서 가장싸게 대여할수 있는비용을 구하라 


Input
- 화단 한변 길이 N (6~10)
- 화단 배열(지점당 가격 0~200)

Output
- 최소대여비용

Try1
- DFS로 하는게 더 빠를거같음
- 화단 겉방향이 아닌 안쪽(1~N-2) 부분에서 조합을 구하면 되겠다.
    - 화단을 받았을 때 미리 꽃이 만개했을 때 4방향계산가격을 저장해놓자.
    - 이거로 완탐하자
    - 조합을 확인하는 도중 최소비용보다 큰비용이 나오면 back.
    - 꽃이 겹치는지는 visited 쓰는게 나아보임.(조건이 branch더 빨릴듯)
*/
#include <bits/stdc++.h>
using namespace std;
int _N , _min_cost = 1000000;
vector<vector<int>> _pre_field;
vector<vector<int>> _field;
vector<vector<int>> _v;
int _dy[4] = {-1, 0, 1, 0};
int _dx[4] = {0, 1, 0, -1};

inline void search_mincost(int cost, int f_cnt)
{
    if(f_cnt > 3)   return;
    else if(f_cnt == 3)
    {

        // // [[TESTCODE]]
        // cout << "\n";
        // for(auto r: _v)
        // {
        //     for(auto c: r)
        //     {
        //         if( c== 1)
        //             cout << "# ";
        //         else
        //             cout << "- ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";

        if(cost < _min_cost)
            _min_cost = cost;
        return;
    }
    for(int y = 1; y < _N-1; y++)
    {
        for(int x = 1; x < _N-1; x++)
        {
            // v 체크
            bool can_i_seed = true;
            if(_v[y][x] == 1) continue;
            for(int d = 0; d < 4; d++)
            {
                if(_v[y+_dy[d]][x+_dx[d]] == 1)
                {
                    can_i_seed = false;
                    break;
                }
            }
            if(can_i_seed == false) continue;
            // v 1
            _v[y][x] = 1;
            for(int d = 0; d < 4; d++)
                _v[y+_dy[d]][x+_dx[d]] = 1;
            // go to next search
            search_mincost(cost + _field[y][x], f_cnt+1);
            // v 0
            _v[y][x] = 0;
            for(int d = 0; d < 4; d++)
                _v[y+_dy[d]][x+_dx[d]] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N;
    _pre_field.resize(_N,vector<int>(_N));
    _field.resize(_N,vector<int>(_N));
    _v.resize(_N,vector<int>(_N));
    for(int y = 0; y <_N; y++)
    {
        for(int x = 0; x <_N; x++)
        {
            int in;
            cin >> in;
            _pre_field[y][x] = in;
        }
    }
    // 화단 가격 미리 계산
    for(int y = 1; y < _N-1; y++)
    {
        for(int x = 1; x < _N-1; x++)
        {
            int money = _pre_field[y][x];
            for(int d = 0; d < 4; d++)
            {
                money += _pre_field[y+_dy[d]][x+_dx[d]];
            }
            _field[y][x] = money;
        }
    }

    // // [[TESTCODE]]
    // cout << "\n";
    // for(auto r: _field)
    // {
    //     for(auto c: r)
    //         cout << c << " ";
    //     cout << "\n";
    // }
    // cout << "\n";

    // get 최소비용
    search_mincost(0, 0);

    cout << _min_cost;
    return 0;
}