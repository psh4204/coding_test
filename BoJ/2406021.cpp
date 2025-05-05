/* 자동설비

설비들이 일렬로 번호가 증가하는 순서로 배치됨
Q개의 제품을 생산한다

각 설비를 지나가야함
- Q개의 제품을 만들때 구간이 있으며 시작 s와 끝 e로 정의됨

N개의 주요 설비들을 관리하고있음
- 가장 빨리 노후화(가장사용많이) 되는 설비를 빨리 찾고싶음

Q개를 만들고난 뒤, 주요설비 K개를 처분하기로 함
- 같이 노후화 되면 처분될때 설비번호가 낮은것 부터 처분됨 (오름차순)

처분되고 남은 N-K개의 주요 설비 중 가장 많이 사용된 주요 설비 번호를 구하라
- 설비 개수(N 1~500,000)
- 제품 수(Q 1~500,000)
- 처분할 설비 수(0~500,000)
- 설비 번호 1~109

입력
- N Q K
- 설비번호들(오름차순으로)
- 각 제품 별 거쳐가는 설비 s e

출력
- 처분되지 않고 남은것들 중에 가장많이 사용된 주요 설비 번호 출력 (여러개라면 가장작은 설비 번호)

6 5 2
3 7 10 13 17 20
1 10
3 9
4 23
12 19
3 15

ans: 10


10 6 0
1 5 10 20 29 40 55 64 71 79
7 60
20 77
1 21
5 55
10 71
22 27

ans: 20


풀이
- 각 제품 s e를 걸치는 설비들을 K개 없앤 후 (걸친횟수가 같으면 오름차순으로)
    거기서 남은 설비 중 가장 오래된 설비출력(여기서도 걸친 횟수가 같음면 오름차순으로)
- 설비개수가 어마어마 하지만, 끽해봤자 번호가 1~109개임 (겹치는게 많다는 소리)
- Q개 단순루프 돌려도 문제 풀릴듯
- 이건 풀었다.. 하아..
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Machine_t{
    int num = 0;
    int coup = 0;
    ll cnt = 0;
};
int g_N, g_Q, g_K, g_input, g_s, g_e;
vector<Machine_t> g_machines(110);
vector<Machine_t> g_last;
int g_ans;

bool CustomCmp(const Machine_t & left, const Machine_t & right)
{
    if(left.cnt > right.cnt)
        return true;
    else if(left.cnt == right.cnt)
        return left.num < right.num;
    return false;
}

int main()
{
    cin >> g_N >> g_Q >> g_K;
    // 1. 기계 등록
    for(int nIdx = 0; nIdx < g_N; nIdx++)
    {
        cin >> g_input;
        g_machines[g_input].num = g_input;
        g_machines[g_input].coup++;
    }
    // s e 이벤트에 맞게 카운트
    for(int qIdx = 0; qIdx < g_Q; qIdx++)
    {
        cin >> g_s >> g_e;
        for(int sIdx = g_s; sIdx <= g_e; sIdx++)
            g_machines[sIdx].cnt++;
    }
    for(auto m: g_machines)
    {
        if(m.coup != 0)
            g_last.push_back(m);
    }
    sort(g_last.begin(), g_last.end(), CustomCmp);

    // TEST >>>
    for(int mIdx = 0; mIdx < g_last.size(); mIdx++)
    {
        cout << g_last[mIdx].num << ", coup:" << g_last[mIdx].coup << ", cnt:" << g_last[mIdx].cnt << "<< \n";
    }
    // <<< 
    for(int mIdx = 0; mIdx < g_last.size(); mIdx++)
    {
        g_K -= g_last[mIdx].coup;
        if(g_K < 0)
        {
            g_ans = g_last[mIdx].num;
            break;
        }
    }
    cout << g_ans;
    return 0;
}
