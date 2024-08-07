/*
https://www.acmicpc.net/problem/16496

- input:
    N
- output:
    n n n n ...
    n의 배치 중 가장 큰수 (nnnn)

풀이: 순열문제. 부분적으로 sort와 순열을 해서 경우의수를 최소화 한다.
- 입력 후 2차원벡터로 숫자받기: ({a,b,c,d})
    - 내림차순으로 sort: 앞자리수로 내림차순정렬됨 ({9, ..}, {8, ..})
- 앞자리수로 그룹화. 이또한 2차원벡터로 저장한다. ({9,2}, {8,1}, )
- 각 그룹마다 순열 후 숫자크기가 가장 큰 값을 저장.
    - 각 그룹별 가장 큰 숫자 string으로 저장: {"aa", "bb", "ccc", "0000"}
- 그 숫자들을 잘 이어붙인 후 return.

TC
---
5
3 30 34 5 9

5
0 0 0 0 1

2
0 0


NN차 제츨:
- stoll로 인한 런타임 에러. 문자열이 너무길면 난다
- 순열로 문제를 풀었는데 당연히 시간초과 (n!)

정답
- 이진 퀵소트인 sort()를 통해, 해당 정답의 규칙을 찾고, 해결해나갔음
- 퀵소트는 시간이 nlogN 이라 순열보다 훨씬 빠름
- 그리고 string 0처리를 잘 해야함.
- sort가 좋구먼 ㅎㅎ
 */
#include <bits/stdc++.h>
using namespace std;

int _N = 0;
vector<string> _str_nums;

bool custon_cmp(string first, string second)
{
    int int_first = stoi(first);
    int int_second = stoi(second);
    if(int_first == int_second) // 앞자리가 0인 정수문자열 처리
    {
        return first.length() < second.length(); // 01, 001 중 length 짧은값이 앞으로감.
    }
    return (first + second) > (second + first); // 그외에는 string 끼리 합쳤을때 더큰값을 만드는 값이 앞으로 감.
}

void get_input_and_init_nums()
{
    // get N
    cin >> _N;

    // get 
    for(int input_cnt = 0; input_cnt < _N; input_cnt++)
    {
        string input;
        cin >> input;
        _str_nums.push_back(input);
    }
    sort(_str_nums.begin(), _str_nums.end(), greater<string>()); // {33,31,30,21,2,1}
    sort(_str_nums.begin(), _str_nums.end(), custon_cmp);
}

void sum_num_and_print_answer()
{
    string str_answer;
    int int_num = stoi(_str_nums[0]);
    str_answer += to_string(int_num);

    for(int loop_cnt = 1; loop_cnt < _str_nums.size(); loop_cnt++)
    {
        str_answer += _str_nums[loop_cnt];
    }
    if(str_answer[0] == '0')
        cout << 0;
    else
        cout << str_answer;
}

int main()
{
    // 입력 후 _str_nums init and greater-custom sort.
    get_input_and_init_nums();

    // // 값 출력
    sum_num_and_print_answer();

    return 0;
}