/* https://www.acmicpc.net/problem/1931
회의실 배정

한개의 회의실. N개의 회의.
- 회의실의 시작시간 ~ 끝나는시간 주어짐.
- 끝나는동시에 회의를 시작할 수 있음.
- 회의시간이 겹치지않게 배정하여, 최대한 많은 회의 횟수를 구하라

입력
- N (1~100,000)
- 시작시간 끝시간 ...

출력
- 최대사용가능한 회의 최대개수

풀이
- 끝나는 시간으로 sort
- 회의실 합치는 루프에서, 시작시간이 겹치면 Pass.

4
1 1
2 2
1 2
1 1
*/
#include <bits/stdc++.h>
using namespace std;
struct meet_t{
    int start;
    int end;
};
struct comp_meet{
    bool operator() (const meet_t &first, const meet_t &second)const
    {
        if(first.end < second.end)
            return true;
        else if(first.end == second.end)
        {
            if(first.start < second.start)
                return true;
        }
        return false;
    }
};
int _N, _meet_cnt, _end_time;
vector<meet_t> _meets;

int main()
{
    cin >> _N;
    _meets.resize(_N);
    for(int n_cnt = 0; n_cnt < _N; n_cnt++)
        cin >> _meets[n_cnt].start >> _meets[n_cnt].end;
    sort(_meets.begin(), _meets.end(), comp_meet());
    // // TEST
    // cout << "---\n";
    // for(auto m: _meets)
    //     cout << m.start << " " << m.end << "\n";
    // cout << "---\n";
    // // ---
    for(int n_cnt = 0; n_cnt < _N; n_cnt++)
    {
        if(_end_time > _meets[n_cnt].start)
            continue;
        // cout << _meets[n_cnt].start << " " << _meets[n_cnt].end << "\n"; // TEST
        _end_time = _meets[n_cnt].end;
        _meet_cnt++;
    }
    cout << _meet_cnt;
    return 0;
}