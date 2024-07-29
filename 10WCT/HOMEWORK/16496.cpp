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


1차 제츨: 런타임 에러
- 벡터를 막갈기고있었나봄. 확인해보자
- _N이 0일때를 막아보자.

2차 제출: 시간초과.
- ...? 왜지?? 이게 가장 효율적일 줄 알았는데..
- 생각해보니, 앞자리수로 체크하는게 더 비효율적이네. 그냥 문자열로 greater 하면 되는구나
- 그룹은 어떻게 받아오지..? 흐음.. string앞자리수로 체크하면 되겠다
- 모든 순열을 도는건 비효율적임. 중간에 return 해야할텐데.. 그룹화가 최선인거 같다.

3차 제출: 시간초과
- 받아오면서 처리할게 좀 필요해보임
- 입력 후 숫자 init -> 그룹생성 -> 그룹별 permutation. 이렇게하는데 어떻게 해야할까
- permutation이 문제인건가..?
    - 문자열을 받아온 직후 바로 합쳐보는데, 
    - string 벡터는 그대로 놔두고, 
    - 방금 합친값-전에합친값 둘다 비교 후, 가장큰값 성립되면 루프탈출, 아니면 다음번째에 insert해서 다시확인 루프
- 잠만.. 그냥 문자다받아오고 greater하고, 그룹으로 sort 한후 더하면 끝아님? -> 아님.
- 앞자리로 그룹화 -> 그룹 내에서 두 String을 합쳐가며 더큰값 만드는 루프로 진행.

4차 제출: 틀렸습니다
- 흐음.. 왤까 ㅋㅋㅋ
- 일단 시간초과는 안남.
- 앗. string으로 내보내버림.

5차 제출: 런타임에러
- 흐음~ stoi 잘못썼나?

6차 제출: 틀렸습니다.
- 흐음~ 머지..? 머냐고!

7차 제출: 틀렸습니다.
- stoi가 아니라 stoll을 써야했음
- 이번에 틀렸습니다는 좀 오래갔다.

다른 방법을 강구하자
- sort(begin(), end(), cmp): cmp에 모든 조건이 부합되게 sort.
- 여태 내가 하려했던게 이건데, 규칙이 어떻게 될까
    - 그냥 greater는 사실 안됨 (93,912, 9-> 93,912,9) (원하는거: 9,93,912)
    - 9+93, 912+9, 93+912 이런식으로 경우의 수 다 permutation해도 시간초과.
    - 생각을 해보면 sort할때 퀵소트로 모든 수를 전부 cmp에 부합되게 바꿔주는데, cmp를 어떻게해야할까..
    - (9 93) (93 912) 로 나눠보자
    - (993(9) ? 939(93)) (93912(93) ? 91293(912))
    -> 9 93 912
    - cmp로 string끼리 더한 후  정렬하면 되겠네. sort와 cmp 그리고 이진트리는 신이다. 될까 이게?

8차 제출: 틀렸습니다. (86%)
- 거의 다 왔다.
- 여기서 그룹화를 해보자.(내가좋아하는)

9차 제출: 틀렸습니다. (86%)
- 그룹화, 커스텀sort 다썼는데 안된다.
- 그렇담 최적화, 탐색 이슈는 아닐거같음.(내 머리론)

1N차 제출: 틀렸습니다 (86%)
- 앞자리 0인친구들 처리하는게 문제일 것같아서 처리함
- 근데 왜 86에서 못올라갈까
- 
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