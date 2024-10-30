/* 징검다리
개울에 동/서로 징검다리가 놓여있고, 징검다리 높이가 '모두' 다름.
철수는 개울의 서->동 으로 지나갈건데, '돌의 높이의 오름차순'으로 지나가려함.

돌이 서-> 동으로 주어졌을때,
밟을 수 있는 최대 돌의 개수?

입력
- N (돌의 개수 1~ 3,000)
- A ... (돌의 높이 1~ 100,000,000)

출력
- 첫 번째줄 부터 밟을 수 있는 돌의 최대 개수.

풀이1. (오답)
- 철수 다리는 엄청 긴가보다..
    - 못지나간다 라는 조건도 없으니까 !
- 돌 하나하나씩 밟아가며 가장 많이 밟는 값을 찾아본다.

풀이2.
- 현재 돌이 이전돌보다 높으면, 이전돌 중에서 가장 많이 밟힌 돌의 개수 +1 을 현재돌 배열에 넣는다.
- 이중에서 max 값을 구한다.

6
3 9 11 7 8 9

6
3 4 1 2 4 3
*/

#include<bits/stdc++.h>
using namespace std;
struct rock_t{
    int height;
    int count = 1;
};
int _N, _A, _cnt, _max_count;
vector<rock_t> _rocks;

int main(int argc, char** argv)
{
    cin >> _N;
    for(int a_cnt = 0; a_cnt < _N; a_cnt++)
    {
        rock_t n_rock;
        cin >> n_rock.height;
        _rocks.push_back(n_rock);
    }
    
    for(int r_cnt = 1; r_cnt < _rocks.size(); r_cnt++)
    {
        int sub_count = 0;
        for(int sub_cnt = r_cnt-1; sub_cnt >= 0; sub_cnt--)
        {
            // 현재보다 이전값이 크면 넘김
            if(_rocks[r_cnt].height <= _rocks[sub_cnt].height) continue;
            // 이전값 중에서 가장 큰 카운트 찾기.
            sub_count = max(sub_count, _rocks[sub_cnt].count);
        }
        _rocks[r_cnt].count = sub_count+1;
        _max_count = max(_rocks[r_cnt].count, _max_count);
        // cout << _rocks[r_cnt].height<< ":" << _rocks[r_cnt].count << " ";     // TEST
    }
    // cout << "\n";     // TEST

    if(_max_count == 0)
        _max_count = 1;
    cout << _max_count;
    return 0;
}