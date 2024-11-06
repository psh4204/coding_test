/* 컵라면
https://www.acmicpc.net/problem/1781

N개의 문제를 각각 풀었을때, 컵라면을 줄거임.
- 파라미터: 문제번호N/데드라인/컵라면수
- 제한된 시간에 문제를 풀어야 하며, 
    최대한 라면을 많이받아야함.
- 문제푸는시간은 1.
- 데드라인은 N이하
- 컵라면수는 2^31이하

입력
- N (번호수,최대시간)
- D C (데드라인, 컵라면수. N개씩 나옴)

풀이
- PQ 문제.
- N시간안으로 데드라인에 맞춰 컵라면을 최대한 받아야함.
- "컵라면을 최대한" 이 키포인트이며, Plan생각말고 오로지 컵라면생각만해야함.
- 데드라인 오름차순으로 sort
- 컵라면을 기준으로 가장 적게받는 컵라면을 top에 두며, 데드라인과 안맞으면 pop
*/
#include <bits/stdc++.h>
using namespace std;
struct problem_t {
    int d_line;
    int ramen;
};
bool cmp_vector(const problem_t & first, const problem_t & second)
{
    if(first.d_line < second.d_line)
        return true;
    return false;
}
struct cmp_pq{
    bool operator() (const problem_t & first, const problem_t & second) const
    {
        if(first.ramen < second.ramen)
            return false;
        return true;
    }
};
vector<problem_t> _problems;
priority_queue<problem_t, vector<problem_t>,cmp_pq> _pq; 
int _N, _max_ramen;

int main()
{
    cin >> _N;
    _problems.resize(_N);
    for(int n_cnt = 0; n_cnt < _N; n_cnt++)
        cin >> _problems[n_cnt].d_line >> _problems[n_cnt].ramen;
    sort(_problems.begin(), _problems.end(), cmp_vector);
    for(int n_cnt = 0; n_cnt < _N; n_cnt++)
    {
        // cout << n_cnt << ":  d:" << _problems[n_cnt].d_line << " r:" << _problems[n_cnt].ramen << "\n"; // [[TEST]]
        _pq.push(_problems[n_cnt]);
        if(_problems[n_cnt].d_line < _pq.size())
            _pq.pop();
    }
    int pq_size = _pq.size();
    // cout << "----\n" ; // [[TEST]]
    for(int pq_cnt = 0; pq_cnt < pq_size; pq_cnt++)
    {
        // cout << pq_cnt << ":  d:" <<  _pq.top().d_line << " r:" <<  _pq.top().ramen << "\n"; // [[TEST]]
        _max_ramen += _pq.top().ramen;
        _pq.pop();
    }
    cout << _max_ramen;
    return 0;
}