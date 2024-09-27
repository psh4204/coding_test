/* https://www.acmicpc.net/problem/14469
소가 길을 건너간 이유3

소가 자꾸 친구집에 건너간다.
울타리를 쳤고 문은 하나다. 문의 검문을 통과해야만이 소는 친구집에 넘어갈수 있게 됐다.
한번에 한마리만 넘어갈 수 있구, 소가많을수록 그만큼 줄은 길어진다.

N마리의 소가 친구농장에 방문하러 왔고, 소가 문에 도착한 시간~ 검문받는 시간은 소마다 같거나 다름.
- 5초에 도착 -> 7초동안 검문, 8초에 도착한 당므 소는 12초까지 줄을 서야 검문받음

모든 소가 농장에 입장하려면 얼마나 걸릴까용?

Input
- 첫줄 100이하의 양의 정수 N (소 마리수)
- 도착시간,검문시간 (1~1,000,000)

Output
- 모든소가 친구농장에 입장하는데 걸리는 최소 시간 출력

Try1.
- 도착시간으로 sort
- 여기서 도착시간과 검문시간 둘다 sort(PQ하는게 맞겠지) 해서 ret 계산
- 도착시간 + 검문시간 로 된 ret값은 다음 도착시간친구가 더 클경우, 그 다음더큰시간이 ret가 됨
    - max 사용
8
1 9
5 8
9 9
1 6
1 6
5 6
9 7
5 1
*/
#include <bits/stdc++.h>
using namespace std;
struct Cow_t{
    int start = 0;
    int check = 0;
    Cow_t(){};
    Cow_t(int s, int c): start(s), check(c) {};
    // sort로 start 오름차순
    bool operator < (const Cow_t& second)const
    {
        if(start < second.start)
            return true;
        else
            return false;
    }
};
vector<Cow_t> _cows;
priority_queue<int,vector<int>> _pq; // 시간용 PQ.
int _N, _ret, _pre_start;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N;
    for(int in = 0; in < _N; in++)
    {
        Cow_t cow;
        cin >> cow.start >> cow.check;
        _cows.push_back(cow);
    }
    sort(_cows.begin(), _cows.end());
    
    // // [[TEST]]
    // for(auto cow: _cows)
    //     cout << cow.start << " " << cow.check << "\n";
    _ret = _cows[0].start;
    for(int idx = 0; idx < _cows.size(); idx++)
    {
        if(!_pq.empty() && _pre_start != _cows[idx].start)
        {
            do
            {
                // cout << _ret  << " + " << _pq.top() << "\n"; // [[TEST]]
                _ret += _pq.top();
                _pq.pop();
            } while (!_pq.empty());
            _ret = max(_ret, _cows[idx].start);
        }
        _pq.push(_cows[idx].check);
        _pre_start = _cows[idx].start;
    }
    // 마지막소 처리
    do
    {
        // cout << _ret  << " + " << _pq.top() << "\n"; // [[TEST]]
        _ret += _pq.top();
        _pq.pop();
    } while (!_pq.empty());
    
    cout << _ret;
    return 0;
}