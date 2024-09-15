/* https://www.acmicpc.net/problem/15353
큰수

두 정수 A B를 받은 후 A+B를 출력하는 프로그램 출력.

Input
- A B (0 ~ 10^10000)

Output
- A+B

Try1
- 비트마스킹이랑 무슨 상관이지?
- 수를 받는데 엄청 큰 수를 받아서 처리해야함.
- 이렇게 큰수를 받아서 처리하는 자료형이 있을까? (없을거임)
- vector로 수를 받은 후, +했을때 10을 넘기면 앞의수에 값을 1씩 넘겨주면되지않나?
- 10,000 -> 20kB.. 40kB... 그냥 무식하게하자
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> _vals(2);
int _max_length = 0;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string num;
    for(int in = 0 ; in < 2 ; in++)
    {
        int str_len = 0;
        cin >> num;
        reverse(num.begin(), num.end());
        str_len = num.length();
        _max_length = max(_max_length,str_len);
        for(int n_cnt =0; n_cnt< num.length(); n_cnt++)
        {
            _vals[in].push_back(num[n_cnt]-'0');
        }
    }
    _vals[0].resize(_max_length+1);
    _vals[1].resize(_max_length+1);
    //calc
    for(int c_idx = 0; c_idx <_max_length; c_idx++)
    {
        int c_val = _vals[0][c_idx] +_vals[1][c_idx];
        if(c_val >= 10)
        {
            _vals[0][c_idx] = c_val%10;
            _vals[0][c_idx+1]++;
        }
        else
            _vals[0][c_idx] = c_val;
        // cout << _vals[0][c_idx] << " "; [[TESTCODE]]
    }
    bool can_i_print = false;
    for(int p_idx = _max_length; p_idx >= 0; p_idx--)
    {
        if(can_i_print == false &&_vals[0][_max_length] == 0 && _vals[0][p_idx] != 0)
            can_i_print = true;
        else if(_vals[0][_max_length] != 0)
            can_i_print = true;
        if(can_i_print)
            cout << _vals[0][p_idx];
    }
    if(can_i_print == false)
        cout << 0;
    return 0;
}