/* 잃어버린 괄호
https://www.acmicpc.net/problem/1541

숫자와 +,-로된 식을 받았을때,
괄호를 적절히 쳐서 수식의 계산값을 최소로 만들어라

입력
- 수식 (예: 55-50+40, 0001 + 0002) (입력값은 5자리이하 많이 연속되는 숫자는 없음)
출력
- 최소값

풀이
- String으로 값 받아서 파싱먼저 해야함
- - 값이 나오기전까지 값들을 다 더한다
- - 값이 나오면 -뒤에값들중에서 -값이 나오기전까지 계산해준 후 값을 또 더한다
- 이런식으로 밖에생각안남 ..
- 맞음. 시간제한이 2초라는게 함정

*/
#include <bits/stdc++.h>
using namespace std;
enum BUHO_t{
    PLUS = 0, // 비어있거나, 덧셈
    MINUS = 1, // 뺄셈
};
typedef struct {
    BUHO_t buho = PLUS;
    int num = 0;
}NUMBER_t;
string g_input;
vector<NUMBER_t> g_nums;
long long g_sum;
int main()
{
    cin >> g_input;
    // Parsing Nums
    for(int frontIdx = 0; frontIdx < g_input.size(); frontIdx++)
    {
        NUMBER_t number;
        // 부호 부터 파싱 (없으면 자동 '+')
        if(g_input[frontIdx] == '+')
        {
            number.buho = PLUS;
            frontIdx++;
        }
        else if(g_input[frontIdx] == '-')
        {
            number.buho = MINUS;
            frontIdx++;
        }
        int backIdx = frontIdx;
        for(; backIdx < g_input.size(); backIdx++)
        {
            if(g_input[backIdx] == '+' || g_input[backIdx] == '-')
                break;
        }
        number.num = stoi(g_input.substr(frontIdx, backIdx-frontIdx));
        frontIdx = backIdx-1;
        g_nums.push_back(number);
    }
    for(int numIdx = 0; numIdx < g_nums.size(); numIdx++)
    {
        int subIdx = 0;
        if(g_nums[numIdx].buho == MINUS) // 뺄셈
        {
            long long subSum = g_nums[numIdx].num;
            subIdx = numIdx+1;
            for(;subIdx < g_nums.size(); subIdx++)
            {
                if(g_nums[subIdx].buho == MINUS)
                    break;
                subSum += g_nums[subIdx].num;
            }
            // cout << "-" << subSum ; // TEST
            g_sum -= subSum;
            numIdx = subIdx-1;
        }
        else // 덧셈
        {
            // cout << "+" << g_nums[numIdx].num ; // TEST
            g_sum += g_nums[numIdx].num;
        }
    }
    // cout << " = "; // TEST
    cout << g_sum;
    return 0;
}