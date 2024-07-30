/*
https://www.acmicpc.net/problem/2559

수열
매일 온도값을 측정한다.
온도값 N개에서 K일 연속의 온도합이 중에서 가장큰 값을 구하시오.

input
- N K
- D D D D ...

output
- 가장 큰 K연속 온도합

try1
- N 과 K를 받아온 후 N개만큼 값을 받아 vector에 저장
- K개의 합을 구하는 동시에 가장큰값을 체크한다.
=> 시간초과

try2
- 모든 수를 순환하는게 문제인가? -> 안할수가 없어보임
- 값을 받자마자 더할까 -> 흐음.. 안땡겨
- 값을 받아온 후 _K 루프 만큼 sum하는걸 최소화하자
    - 현재 sum값 과 이전 sum값을 만들기에는 루프는 없어도 되잖아?

*/
#include <bits/stdc++.h>
using namespace std;

int _N, _K = 0;

int main()
{
    vector<int> degrees;
    int input_degree, prev_sum, max_sum = 0;
    cin >> _N >> _K;
    for(int day_cnt = 0; day_cnt < _N; day_cnt++)
    {
        cin >> input_degree;
        degrees.push_back(input_degree);
    }
    for(int first_sum_idx = 0; first_sum_idx < _K; first_sum_idx++)
    {
        max_sum += degrees[first_sum_idx];
    }
    prev_sum = max_sum;
    for(int loop_idx = _K; loop_idx < _N; loop_idx++)
    {
        int curr_sum = prev_sum + degrees[loop_idx] - degrees[loop_idx-_K];
        if(curr_sum > max_sum)
            max_sum = curr_sum;
        prev_sum = curr_sum;
    }
    
    cout << max_sum;
    return 0;
}