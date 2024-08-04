/*
https://www.acmicpc.net/problem/1940
주몽

주어진 재료 N개중에 중에서 구개의 재료를 합쳐 딱 M이되는 갑옷을 몇개나 만들 수 있는지 구하시오.

Input
- 재료개수N (1~15,000)
- 갑옷필요재료숫자 M (1~100,000)

Output
- 갑옷갯수 구하기

Try1
- 입력받자마자 입력값에 마지막 Input값을 더해주면서 count해나가면 될거같은데?
*/

#include <bits/stdc++.h>
using namespace std;

int _N, _M,_ret_cnt = 0;
vector<int> _ingredients;

int main()
{
    cin >> _N >> _M;
    int input = 0;
    cin >> input;
    _ingredients.push_back(input);
    for(int input_cnt = 1; input_cnt < _N; input_cnt++)
    {
        cin >> input;
        for(auto ingredient: _ingredients)
        {
            if(ingredient + input == _M)
                _ret_cnt++;
        }
        _ingredients.push_back(input);
    }
    cout << _ret_cnt;
    return 0;
}