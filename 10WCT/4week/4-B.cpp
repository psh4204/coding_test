/* https://www.acmicpc.net/problem/1285
동전뒤집기

NxN의 동전배치.H(앞)T(뒤)
한열 혹은 한행의 모든 동전을 뒤집을 수 있음.
뒤집는 모든 경우의 수에서 T(뒤) 동전의 최소개수를 구하라

input
- N (1~20)
- 동전리스트 (H T)

output
- H를 향하여 놓일 수 있는 동전 최소개수를 출력

Try1.
- 완탐 문제이고 최소값보다 작은경우는 pass.
    - DFS로 해야할거로 보임.
- 행, 열의 개수만큼 비트마스킹 하자.

Try2.
- 시간초과나네. 이게뭔..
- 벽느꼈다. 힌트볼래.

Hint
- 전형적인 어려운문제. 로직만으로 풀수없음
- 뒤집어도 되는 값인지 아닌지 부터 체크를 한 후에 뒤집어야함.
*/
#include <bits/stdc++.h>
using namespace std;
int _N, _lines, _ret_sum;
vector<vector<int>> _coins;

inline void get_ret_sum(int here, int pre_sum)
{
    for(int l_idx = here; l_idx < (2*_N); l_idx++)
    {
        if(_lines & (1<<here))
            continue;
        int sum = pre_sum;
        int line_sum = 0;
        // 뒤집기전에 뒤집어도 될지 확인
        if(l_idx < _N)
        {
            for(int x = 0; x < _N; x++)
                line_sum += _coins[l_idx][x];
        }
        else
        {
            for(int y = 0; y < _N; y++)
                line_sum += _coins[y][l_idx-_N];
        }
        if(line_sum < _N/2) continue;

        // 라인 별 뒤집고 합치기
        if(l_idx < _N)
        {
            for(int x = 0; x < _N; x++)
            {
                if(_coins[l_idx][x])
                {
                    sum -= _coins[l_idx][x];
                    _coins[l_idx][x] = 0;
                }
                else
                {
                    _coins[l_idx][x] = 1;
                    sum += _coins[l_idx][x];
                }
            }
        }
        else
        {
            for(int y = 0; y < _N; y++)
            {
                if(_coins[y][l_idx-_N])
                {
                    sum -= _coins[y][l_idx-_N];
                    _coins[y][l_idx-_N] = 0;
                } 
                else
                {
                    _coins[y][l_idx-_N] = 1;
                    sum += _coins[y][l_idx-_N];
                }
            }
        }
        _lines |= (1<<l_idx);

        // // [[TESTCODE]]
        // cout << "\n>sum: " << pre_sum << "\n";
        // for(auto r: _coins)
        // {
        //     for(auto c: r)
        //         cout << c << " ";
        //     cout << "\n";
        // }

        if((_ret_sum != 0 && _ret_sum > pre_sum)
            ||(_ret_sum == 0))
            _ret_sum = pre_sum;
        
        get_ret_sum(here+1, sum);

        // 복구
        _lines &= ~(1<<l_idx);
        if(l_idx < _N)
        {
            for(int x = 0; x < _N; x++)
            {
                if(_coins[l_idx][x]) _coins[l_idx][x] = 0;
                else _coins[l_idx][x] = 1;
            }
        }
        else
        {
            for(int y = 0; y < _N; y++)
            {
                if(_coins[y][l_idx-_N]) _coins[y][l_idx-_N] = 0;
                else _coins[y][l_idx-_N] = 1;
            }
        }
    }
}

int main()
{
    int sum =0;
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N;
    _coins.resize(_N, vector<int>(_N));
    for(int y = 0; y <_N; y++)
    {
        for(int x =0; x <_N; x++)
        {
            char in;
            cin >> in;
            if(in == 'T')
            {
                _coins[y][x] = 1;
                sum++;
            }
        }
    }

    // // [[TESTCODE]]
    // for(auto r: _coins)
    // {
    //     for(auto c: r)
    //         cout << c << " ";
    //     cout << "\n";
    // }
    cout << "\n";

    if(sum == 0)
    {
        cout << 0;
        return 0;
    }

    get_ret_sum(0, sum);
    cout << _ret_sum;

    return 0;
}