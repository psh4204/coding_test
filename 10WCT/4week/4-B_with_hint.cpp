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

Point
- 경우의 수는 (N*2)^2에서 찾는게 아닌, N^2
    - 가로를 다 뒤집고, 세로는 굳이 안뒤집어도 됨
    - 세로를 뒤집은값과 안뒤집은 값 중에 더 작은수가 정답
- 가로 뒤집기는 비트마스킹으로 표현해서 ~연산을 사용하면 한번에 해결.
*/
#include <bits/stdc++.h>
using namespace std;
int _N, _ret_sum = 0x7FFFFFFF;
vector<int> _coins;

inline void get_ret_sum(int here)
{
    if(here == _N)    // 가로관련 경우의 수 끝에 도달
    {
        int all_sum = 0;
        for(int x = 0; x < _N; x++)   // x >> 1. 세로훑기
        {
            int c_sum = 0;
            for(int y = 0; y < _N; y++)
            {
                if(_coins[y] & (1<<x))  c_sum++;    // 각 가로의 세로비트값 체크
            }
            all_sum += min(c_sum, _N-c_sum);
        }
        // cout << _ret_sum << " vs " << all_sum << "\n"; // [[TESTCODE]]
        _ret_sum = min(_ret_sum, all_sum);  // 전체 T합 중 최소값 체크
        return;
    }
    get_ret_sum(here+1); // 안뒤집는 경우
    _coins[here] = ~_coins[here];
    get_ret_sum(here+1); // 뒤집는 경우
}

int main()
{
    int sum =0;
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N;
    _coins.resize(_N);
    for(int y = 1; y <=_N; y++)
    {
        string in;
        cin >> in;
        int val = 0;
        for(int x = 0; x< _N; x++)
        {
            if(in[x] == 'T')
                val |= (1<<x);
        }
        _coins[y-1] = val;
    }
    
    // // [[TESTCODE]]
    // for(auto y : _coins)
    //     cout << y << "\n";
    
    get_ret_sum(0);

    cout << _ret_sum;

    return 0;
}