/*
설비들이 나열되어있고 Q개의 제품을 생산.
특정구간을 차례로 지나야 제품이 만들어짐.
N개의 설비를 관리중이고, 노후화 관리를 하려함.
Q개의 제품 모두 하나씩 만든 후 가장 노후화 된 K개의 주요 설비를 처분하기로함.
K개의 주요 설비를 처분할때, 같은기준으로 설비를 처분할 때 설비번호가 작은 것 부터 처분함.
처분되고 남은 N-K개의 주요설비 중 가장 많이 사용된 주요 설비 번호를 구해라. (설비번호 1~109)

입력
- 설비개수 N, 제품수 Q, 처분할 설비 K (N 0~500,000, Q 1~500,000)
- 설비 번호 리스트(N개. 번호가 붙어있음)
- 각 제품별 시작설비 s와 끝 설비 e가 주어짐.

출력
- 처분되지않고 남은것들 중이 가장 많이 사용된 주요 설비번호.

풀이
- 설비 배열 만든 후, 카운트.
- 카운트 후에 가장 많이 사용된것들로 sort.
- K개 만큼 처분 한 후 가장 위의 번호 print

예제 1)
6 5 2
3 7 10 13 17 20
1 10
3 9
4 23
12 19
3 15

10

예제 2)
10 6 0
1 5 10 20 29 40 55 64 71 79
7 60
20 77
1 21
5 55
10 71
22 27

20

*/
#include <bits/stdc++.h>
using namespace std;
struct robot_t{
    int num = 0;
    int cnt = 0;
};
int _N, _Q, _K;
vector<robot_t> _robots;

bool cmp(robot_t first, robot_t second)
{
    if(first.cnt > second.cnt)
        return true;
    else if(first.cnt == second.cnt)
    {
        if(first.num < second.num)
            return true;
    }
    return false;
}

int main()
{
    cin >> _N >> _Q >> _K;
    _robots.resize(_N);
    for(int n_cnt = 0 ; n_cnt < _N; n_cnt++)
        cin >> _robots[n_cnt].num;
    for(int q_cnt = 0; q_cnt < _Q; q_cnt++)
    {
        int start, end;
        cin >> start >> end;
        for(int n_cnt = 0 ; n_cnt < _N; n_cnt++)
        {
            if(_robots[n_cnt].num >=start && _robots[n_cnt].num <=end)
                _robots[n_cnt].cnt++;
        }
    }
    sort(_robots.begin(), _robots.end(), cmp);
    cout << _robots[_K].num;
    return 0;
}