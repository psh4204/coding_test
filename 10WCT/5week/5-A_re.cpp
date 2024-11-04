/* 순회강연
https://www.acmicpc.net/problem/2109

각 대학에서 d일 안에와서 강연시 강연료p를 줌.
가장많은 돈을 벌 수 있도록한다.
하루 한곳에서만 강연가능.

입력
- n (대학교 수. 0~10,000)
- p d (돈, 날짜. 1~10,000)


출력
- 가장 많이 벌수 있는 돈

풀이
- 대학강연정보 (p,d)에서 d기준 오름차순정렬
- pay가 가장 쎈 학교만 골라가면 될듯?
    -> "~일 안에" 때문에 틀린로직.
- 


(C++ 자체 버그 발견)
- for auto 문은 무적이 아니다.
    - loop에서 0이 지속되면, for문 동작을 안함.
*/
#include <bits/stdc++.h>
using namespace std;
struct univ_t{
    int pay;
    int day;
};
struct cmp_pq{
    bool operator() (const univ_t &first, const univ_t &second) const
    {
        if(first.pay < second.pay)
            return false;
        return true;
    }
};
bool cmp_vector(const univ_t &first, const univ_t &second)
{
    if(first.day < second.day)
        return true;
    return false;
}
int _uni_cnt, _money;
priority_queue<univ_t, vector<univ_t>, cmp_pq> _pq;
vector<univ_t> _univs;

int main()
{
    cin >> _uni_cnt;
    _univs.resize(_uni_cnt);
    for(int u_cnt = 0; u_cnt < _uni_cnt; u_cnt++)
        cin >>  _univs[u_cnt].pay >> _univs[u_cnt].day;
    sort(_univs.begin(), _univs.end(), cmp_vector);
    
    // cout << "---\n";
    // for(auto u: _univs) // TEST
    //     cout << u.day << " " << u.pay << "\n";
    
    for(int u_cnt = 0; u_cnt < _uni_cnt; u_cnt++)
    {
        _pq.push(_univs[u_cnt]);
        if(_univs[u_cnt].day < _pq.size())
            _pq.pop();
    }
    // cout << "---\n";
    while (!_pq.empty())
    {
        // cout << _pq.top().day << " " << _pq.top().pay << "\n";
        _money += _pq.top().pay;
        _pq.pop();
    }
    
    cout << _money;

    return 0;
}