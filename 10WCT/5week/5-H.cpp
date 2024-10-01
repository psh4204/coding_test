/* https://www.acmicpc.net/problem/13144
List of Unique Numbers

길이 N인 수열이 주어졌다. 
수열에서 연속한 1개 이상의 수를 뽑았을 때 
같은 수가 여러번 등장하지 않는 경우의 수 구하기

Input
- 수열의길이 N (1 ~ 100,000)
- 수열 (크기 1~100,000)

Output
- 조건을 만족하는 경우의 수

Try1
- 1초까지.. (1억루프)
- 순열,조합 이런게 아니라, '연속된' 부분수열 문제
    - >12345
    - 1 2 3 4 5 (5)
    - 12 23 34 45 (4)
    - 123 234 345 (3)
    - 1234 2345 (2)
    - 12345 (1)
    - = 15
    
    - >12312
    - 1 2 3 1 2 (5)
    - 12 23 31 12 (4)
    - 123 231 312 (3)
    - = 12
    
    - >11111
    - 1 1 1 1 1 (5)
    - = 5

- 이런식으로 카운트 해야하네
- 어떤수가 뽑히던 연속된 숫자가 안나오는 컨테이너를 만들어야겠네
    - 배열에 넣고 인덱스만 세팅? -> 매 루프마다 배열만드는 시간 소요. (O(n))
    - n 보다는 logn 이니까, hash를 통한 중복체크 하자.==> set으로 배열 분배
    - 카운트만 해주면 끝나겠다.

Try2
- 시간초과 이슈 (뭐?)
- 도저히 최적화가 안되서 힌트를 봤음
    - 등차수열의 합으로 경우의수를 구하라
    - 어이가 없네
- 중복안되는 수까지 카운트를 구한 후, 거기서 등차1인 등차수열로 경우의수 계산을 하면 끝난다.
    - 등차수열이라는 걸 익혔으니 다른곳에서도 써먹어야징
    - 얘는 복습안하면 바로 까먹을듯
*/
#include <bits/stdc++.h>
using namespace std;
int _N; 
long long _ret_cnt, _last_size;
vector<int> _n_list;
vector<int> _v(100002, -1);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N;
    for(int in_idx = 0; in_idx < _N; in_idx++)
    {
        int input = 0;
        cin >> input;
        _n_list.push_back(input);
    }
    for(int n_idx = 0; n_idx < _N; n_idx++)
    {
        int sub_size = 0;
        for(int sub_idx = n_idx; sub_idx <_N; sub_idx++)
        {
            if(_v[_n_list[sub_idx]] == n_idx)
                break;
            _v[_n_list[sub_idx]] = n_idx;
            sub_size++;
            // cout << _n_list[sub_idx] << " "; // [[TEST]]
        }
        // cout << "\n"; // [[TEST]]
        if(n_idx + sub_size == _N)
        {
            _last_size = sub_size;
            break;
        }
        _ret_cnt += sub_size;
    }
    _ret_cnt += _last_size*(_last_size+1)/2;
    cout << _ret_cnt;
    return 0;
}