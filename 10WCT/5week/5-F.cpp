/* https://www.acmicpc.net/problem/1202
보석도둑

보석 N개.
무게 M, 가격 V.
가방개수 K, 각 최대 무게 C.
가방에는 최대 한개의 보석만 담을 수 있음.
훔치는 경우 중에서 최대가격이 얼마인가?

입력
- N K (보석개수, 가방. 1~300,000)
- M V (보석무게, 가격. 0 ~ 1,000,000)
- ... (N번 반복)
- C   (각 가방 무게)
- ... (K번 반복)

출력
- 보석가격 최대값

풀이
- 라인스위핑 + 현재가방무게를 통한 PQ 문제
- 각 보석무게와 각 가방무게를 오름차순 sort.
- 현재 가방무게를 중심으로 보석PQ.top의 무게와 비교후, 알맞으면 돈+
    - 보석PQ는 내림차순으로 top에는 가장 비싼 보석을 집어넣는다.
    - PQ에 넣기전에 현재 가방무게와 같던지 작던지 해서 비교해야함 

5 5
1 5
1 2
100 103
100 99
100 105
2
2
5
5
1

*/
#include <bits/stdc++.h>
using namespace std;
struct jewelry_t
{
    long long weight;
    long long value;
};
struct cmp_weight
{
    bool operator() (const jewelry_t& first, const jewelry_t& second) const
    { // vector 무게 오름차순 컴페어
        return first.weight < second.weight;
    }
};
struct cmp_value_pq
{
    bool operator() (const jewelry_t& first, const jewelry_t& second) const
    { // vector 무게 오름차순 컴페어
        return !(first.value > second.value);
    }
};
vector<jewelry_t> _jews;
vector<long long> _bags;
priority_queue<jewelry_t,vector<jewelry_t>,cmp_value_pq> _jews_pq;
int _N, _K;
long long _value_sum;

int main()
{
    cin >> _N >> _K;
    _jews.resize(_N);
    _bags.resize(_K);

    for(int n_cnt = 0; n_cnt < _N; n_cnt++)
        cin >> _jews[n_cnt].weight >> _jews[n_cnt].value;
    sort(_jews.begin(), _jews.end(), cmp_weight());
    for(int k_cnt = 0; k_cnt < _K; k_cnt++)
        cin >> _bags[k_cnt];
    sort(_bags.begin(), _bags.end());
    
    // // TEST ---
    // cout << "jew---\n";
    // for(auto j: _jews)
    //     cout << j.weight << " " << j.value << "\n";
    // cout << "bag---\n";
    // for(auto k: _bags)
    //     cout << k << "\n";
    // cout << "------\n";
    // // ---

    int jew_cnt = 0;    
    for(int k_cnt = 0; k_cnt < _K; k_cnt++)
    {
        // 현재 보석과 가방 무게 체크
        // 가방무게보다 작거나 같으면 pq 담기
        // pq에 계속 담기
        while(jew_cnt < _N && _jews[jew_cnt].weight <= _bags[k_cnt])
        {
            _jews_pq.push(_jews[jew_cnt]);
            jew_cnt++;
        }
        // pq의 top 값을 최대가격에 담기
        // 무게비교.
        if(!_jews_pq.empty() && _jews_pq.top().weight <= _bags[k_cnt])
        {
            // cout <<  _jews_pq.top().value << "\n"; // TEST
            _value_sum +=_jews_pq.top().value;
            _jews_pq.pop();
        }
    }
    cout << _value_sum;
    return 0;
}