#include<bits/stdc++.h>
using namespace std;
/*
https://www.acmicpc.net/problem/2309

일곱난쟁이
- 9명이 왔다.
- 일곱난쟁이의 키의 합이 100
- 가능한 정답이 여러가지인 경우 아무거나 출력한다.
 */

/*
풀이
- 조합을 이용하여 해결한다.

1,2,3 회차 오답풀이
- 1,2회: 재귀문을 통해 탐색을 함으로써, 크게 2회가량 조회하는 코드를 작성해버렸음. (for 문을 통한 모든 조합 확인 필요)
- 3회: 정답을 찾은 후 마무리하지않았음. (exit(0)으로 정답확인 후 코드 종료 필요)
*/

int input_size = 9;
int output_size = 7;
vector<int> minimans(input_size);
vector<int> ret_minimans;

int recursion_count = 0;

void input()
{
    for(int i = 0; i < input_size; i++)
        cin >> minimans[i];
}

void combi_with_recur(int start_idx, vector<int> curr_minimans)
{
    if(curr_minimans.size() == output_size)
    {
        int sum = 0;
        for(int sum_count = 0; sum_count < output_size; sum_count++)
            sum += curr_minimans[sum_count];
        if(sum == 100)
        {
            for(int i = 0; i < output_size; i++)
                cout << curr_minimans[i] << "\n";
            exit(0);
        }
        return;
    }

    for(int loop_idx = start_idx + 1 ; loop_idx < input_size; loop_idx++)
    {
        curr_minimans.push_back(minimans[loop_idx]);
        combi_with_recur(loop_idx, curr_minimans);
        curr_minimans.pop_back();
    }
    return;
}

int main()
{
    // 값을 차례로 입력
    input();

    // 난쟁이들 오름차순으로 정리
    sort(minimans.begin(), minimans.end());

    // 경우의 수 = 순열 or 조합 -> 순서상관 X -> C.
    combi_with_recur(-1, ret_minimans);

    return 0;
}