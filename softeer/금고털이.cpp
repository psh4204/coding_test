/* 금고털이
- 배낭 최대무게  W kg
- 금고를 털었을때 가장 값비싼 가격은?

입력
- 가방무게W 귀금속종류N
- N개의 금속무게M 가격P

출력
- 가장 값비싼 가격

풀이
- 무게 1당 P임. 즉, M은 Max Cnt를 의미함
- 1당 가치로 내림차순 정렬 후, 카운트로 전부 더해준다. 
*/

#include <bits/stdc++.h>
using namespace std;
struct stone_t{
    int weight;
    int price;
};
int _W, _N, _max_price, _bag_cnt;
vector<stone_t> _stones;

bool cmp(const stone_t& first, const stone_t& second)
{
    if(first.price > second.price)
        return true;
    else
        return false;
}

int main()
{
    cin >> _W >> _N;
    for(int n_cnt = 0; n_cnt < _N; n_cnt++)
    {
        stone_t in_stone;
        cin >> in_stone.weight >> in_stone.price;
        _stones.push_back(in_stone);
    }
    sort(_stones.begin(), _stones.end(), cmp);

    for(int n_cnt = 0; n_cnt <_N; n_cnt++)
    {
        for(int w_cnt = 0; w_cnt < _stones[n_cnt].weight; w_cnt++)
        {
            if(_bag_cnt == _W) break;
            _max_price += _stones[n_cnt].price;
            _bag_cnt++;
        }
        if(_bag_cnt == _W) break;
    }
    cout << _max_price;
    return 0;
}