/* https://www.acmicpc.net/problem/2109
순회강연

학자에게 n(1~10000)개의 대학강연 초청.
각 대학은 d(1~10000)일 안에 와서 강연을 해주면 (이때까지 와야해요)
p(1~10000)만큼의 강연료를 지불하겠다고 알려왔다.
- 각 대학에서 제시하는 d,p는 다를 수있음.

이를 바탕으로 가장 큰 돈을 벌 수 있는 쪽으로 순회강연을 하고싶음.
- 하루에 최대 한곳만 강연할 수 있음.

Input
- n
- p d 리스트

Output
- 최대값 리스트

Try1
- Sort하면 문제 풀릴듯?
- 우선순위 큐로 해결해보자. (동작시간 2초이니까)
    - 규칙1. 돈 큰 순 sort.
    - 규칙2. day 작은 순 sort.

Try2. 힌트
- 우선순위 큐에 대한 이해, operator < 와 C++ 기본 문법 스터디 하고옴.
- 근데 안풀려서 힌트봄.
- 다른분께 물어보니 구조체를 사용한 우선순위큐는 흔하진 않다는 첨언 들음.
- 우선순위큐를 그럼 int 부터 써봐야징 ㅎㅎ

- 일단 day 별로 sort해야하는 규칙은 찾음
- day에 맞춰서 Pay를 최대치로 뽑아야함. -> PQ로하면 심플하게 끝남.

*/
#include <bits/stdc++.h>
using namespace std;
struct Univ_t
{
    int pay, day;
    Univ_t() {pay = 0; day = 0;}
    Univ_t(int p, int d): pay(p), day(d) {}
    // PQ가 아닌 day에서 쓸거라서 정상적인 오름차순으로 만듦.
    bool operator < (const Univ_t& second) const
    {
        if(day < second.day)
            return true;
        else
            return false;
    }
};
vector<Univ_t>  _schd;
priority_queue<int, vector<int>, greater<>> _pays;  // PQ는 반대로.
int _n, _max_ret;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _n;
    for(int in_idx = 0; in_idx < _n; in_idx++)
    {
        Univ_t univ;
        cin >> univ.pay >> univ.day;
        
        _schd.push_back(univ);
    }
    sort(_schd.begin(), _schd.end());

    // // [TEST CODE]
    // cout << "\nTEST\n";
    // for(auto schd : _schd)
    //     cout << schd.day << " " << schd.pay << "\n";
    
    // PQ
    for(int sch_idx = 0; sch_idx < _schd.size(); sch_idx++)
    {
        _pays.push(_schd[sch_idx].pay);
        if(_pays.size() > _schd[sch_idx].day)
            _pays.pop();
    }
    // Add datas
    while(!_pays.empty())
    {
        _max_ret += _pays.top(); 
        _pays.pop();
    }
    cout << _max_ret;
    return 0;
}