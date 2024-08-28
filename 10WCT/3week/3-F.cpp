/* https://www.acmicpc.net/problem/16637
괄호 추가하기

길이가 N인 수식. 사칙연산의 우선순위는 모두 동일. (숫자는 0~9)
괄호가 추가되면 그거만 우선순위가 올라감. 한괄호에는 수식하나만 존재하고 중첩괄호 X.
수식이 정해졌을때 괄호를 추가해서 최대값을 구하는 프그램 작성하기.
괄호를 추가하지않아도 됨.

Input
- N (1~19) 
- 수식. // 식이 틀리는 경우는 절-대 없음.(무조건 홀수개의 N개를 받음)

Output:
- 최대값출력. 일반 int형 값이다.

Try1.
- 꼭 굳이 괄호를 안넣어도 될거같고.. DFS로 풀면 될거같음.
- 계산은 stack으로 처리하면 됨.
- 부호만 인덱스를 배열에 넣어두자.
    - 이 인덱스의 앞,뒤값을 스택에 넣어서 계산하는 형식으로 쭉 풀어보자.
    - 스택에 넣을대 visited배열을 넣어서 값이 이상하게 들어가는걸 막자.

Try2.
- 순열써서 풀었는데, 이걸로 하면 중첩괄호가 되어버림..
    - 괄호친구들을 계산한 후에는 왼쪽에서 부터 차례로 계산되야함
    - 단순 순열로는 하면안되겠네 또
- 조합문제..다. (괄호계산 차레로한 후 나머지 계산)
- 연산 인덱스를 하나 하나 넣고 빼고를 반복한다.
    - 괄호 인덱스와 우선순위는 덱으로 해결하면 되겠다.
... 괄호계산부터 경우의수 까지 전부 하드코딩했다.. 하ㅏ아.. 진짜 개힘드네
- 난제: 저걸 어떻게 누적합으로 할수있지? 뭐지???
--- 틀림(88%)

Try3. Hint
- 내가하던방향은 맞음
    - DFS를 통한 완탐.
- 다른게있다면
    - 부호와 숫자를 완-전 분리
        - 이걸 기반으로 코드작성
        ==> 경우의수 최소화

- 이 문제는 DFS를 통한 완탐 + 누적합 문제이다.
- 중첩괄호 없이 우선순위를 누구에게 주느냐 이슈인데 이는 DFS를 통한 완탐으로 충분히 해결가능
- 무조건 왼족에서 오른쪽 계산이기 때문에 누적합으로 진행 가능
	- (A . B) . C
- 그럼 괄호가 뒤에 있다면?
	- A . (B . C) 를 계산해서  DFS.
*/
#include <bits/stdc++.h>
#define MIN -1000000000000
using namespace std;
int _N;
long long _max = MIN;
vector<int> _nums;    
vector<char> _opers;

long long calc(char op, long long first, long long second)
{
    switch(op)
    {
        case '+':
            return first + second;
        case '-':
            return first - second;
        case '*':
            return first * second;
    }
    return 0;
}

void get_max(int here, long long pre_result)
{
    if(here == _nums.size()-1)
    {
        if(pre_result > _max)  _max = pre_result;
        return;
    }
    get_max(here+1, calc(_opers[here], pre_result, _nums[here+1])); // (A B) C ...
    if(here + 2 < _nums.size()) // A (B C)    ...
    {
        long long next_res = calc(_opers[here+1], _nums[here+1], _nums[here+2]);
        get_max(here+2, calc(_opers[here],pre_result, next_res));
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string input;
    cin >> _N >> input;
    for(int in_idx = 0; in_idx < _N; in_idx++)
    {
        if(input[in_idx] >= '0' && input[in_idx] <= '9')
            _nums.push_back(input[in_idx]-'0');
        else
            _opers.push_back(input[in_idx]);
    }
    get_max(0, _nums[0]);   // 0번부터 완탐시작
    cout << _max;
}