/* 소가 길을 건너간 이유3
https://www.acmicpc.net/problem/14469

울타리 사이 작은 문으로 소가 방문할 수 있음.
한번에 한마리밖에 못드가고 나머지는 뒤에 서있어야함.

입력
- N (0~100)
- 도착시간 검문시간
... N반복

출력
- 모든소가 입장하는데 걸리는 최소시간

풀이
- 도착시간으로 sort.
- 끝나는시간에 맞춰서 이어붙여서 진행하면 될듯
*/
#include <bits/stdc++.h>
using namespace std;
int _N, _road_times;
struct cow_t
{
    int start;
    int road;
};
struct cmp_cow
{
    bool operator() (const cow_t &first, const cow_t &second)const
    {
        return first.start < second.start;
    }
};
vector<cow_t> _cows;

int main()
{
    cin >> _N;
    _cows.resize(_N);
    for(int n_cnt = 0; n_cnt <_N; n_cnt++)
        cin >> _cows[n_cnt].start >> _cows[n_cnt].road;
    sort(_cows.begin(), _cows.end(), cmp_cow());
    for(int n_cnt = 0; n_cnt < _N; n_cnt++)
    {
        if(_road_times < _cows[n_cnt].start)
            _road_times = _cows[n_cnt].start;
        _road_times += _cows[n_cnt].road;
    }
    cout << _road_times;
    return 0;
}