/*
보급품 N개. 각 보급품은 무게와 가치가 매겨짐. (W,V 1~50)
총무게 M만큼 담을 수 있음. (N,M 1~50)
담을수 있는 최대 가치를 구하는 프로그램 작성하기.
사람수 (K)

무게 M을 초과할 순 없음. 쪼개서 담을수도 없음.

입력
- N, K, M (보급품, 사람, 가방무게)
- W V(보급품무게,가치)
출력
- 최대보급품가치의 합

예제1
5 2 5
4 5
3 4
2 1
5 7
1 1

13

예제2
10 3 7
4 5
3 4
2 1
5 7
1 1
7 8
8 6
3 3
4 3
5 4

25

풀이
- 배낭문제 = DP
- 배낭배열 생성.
- 각 배낭의 최대가치 차분히 구해나간다.
- DFS를 통해 구현한다.
- POINT: 완전탐색 가능하게 해야함. (if문 잘못걸면 완탐안함. 완탐은 DFS 들어와도 0부터시작해야함.)
*/
#include <bits/stdc++.h>
using namespace std;
enum check_t{
    NONE,
    CHECKED,
};
struct item_t{
    check_t check = NONE;
    int weight = 0;
    int value = 0;
};
int _N, _K, _M, _max_value;
vector<item_t> _items;
vector<int> _bags;
vector<vector<int>> _history;

void set_best_value(int here, int value, int weight, int k_cnt, vector<int>& trace)
{
    if(here == _N || weight > _M)
    {
        return;
    }
    for(int h_cnt = 0; h_cnt < _N; h_cnt++)
    {
        if(_items[h_cnt].check == CHECKED) continue;
        if(weight+(_items[h_cnt].weight) > _M) continue;        
        trace.push_back(h_cnt);
        _items[h_cnt].check = CHECKED;
        int n_weight = weight+_items[h_cnt].weight;
        int n_value = value+_items[h_cnt].value;
        if(n_weight == _M || (weight > _M && n_weight + _items[here].weight > _M))
        {
            // 최대값을 찾았으면 trace 백업.
            if(_bags[k_cnt] < n_value)
            {
                _bags[k_cnt] = n_value;
                _history[k_cnt].clear();
                _history[k_cnt] = trace;
            }
        }
        set_best_value(h_cnt+1, value+_items[h_cnt].value ,weight+_items[h_cnt].weight, k_cnt, trace);
        _items[h_cnt].check = NONE;
        trace.pop_back();
    }
}

int main()
{
    cin >> _N >> _K >> _M;
    _bags.resize(_K);
    _history.resize(_K);
    for(int n_cnt = 0; n_cnt< _N; n_cnt++)
    {
        item_t in_item;
        cin >> in_item.weight >> in_item.value;
        if(in_item.weight > _M) continue;
        _items.push_back(in_item);
    }
    for(int k_cnt = 0; k_cnt < _K; k_cnt++)
    {
        vector<int> trace;
        set_best_value(0, 0, 0, k_cnt, trace);
        for(auto history :_history[k_cnt])
            _items[history].check = CHECKED;
    }
    for(auto value: _bags)
        _max_value += value;
    cout << _max_value;
}
