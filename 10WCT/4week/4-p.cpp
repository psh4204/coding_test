/* https://www.acmicpc.net/problem/3015
오아시스 재결합 (진짜 오아시스 재결합기념으로 풀어보자.)

N명이 한줄로 줄섬.
내가 서있는 위치에서 볼 수 있는 사람 수를 확인하고싶다.
앞뒤로 보려면 본인보다 키가 '큰' 사람이 '없어야'한다.
줄에 있는 사람 키를 받은 후 서로 볼수있는 쌍의 수를 구하시오.

Input
- N (1~500,000)
- 줄선순서대로 사람키 리스트 (0~2^31)(정수int형max)

Output
- 서로 볼 수 있는 쌍의 수

Try1
- 자신을 기준으로 뒷사람 몇명까지 볼수있는지 캬운트하면 되는 문제.
- 잘못하면 O(n!)이겠는데?
- 모든 걸 탐색하지 못하게 어떻게 해야할까..
    - `스택으로 히스토리 관리`.(들어온 인덱스 번지수)
    - `벡터에는 키로된 500,000+a 배열` 만들어주자.
    - 값이 들어왔을 마지막으로 들어온 값보다 작은 것들은 히스토리 Pop해주며 End_idx에 다 집어넣어주자.
    - 마지막에 계산해서 카운트 구하면 끝.

Try2.
- 접근법은 정답임 (스택과 벡터를 이용한다.)
- 근데 뒷사람들 중에 본인보다 키가 작은사람이 끼여있으면 거기서 카운트가 끊김.(문제를 아주그냥..)
    - 키가 중간에 변동이 일어나면 무조건 카운트 1임.
- 이거에 대한 해답을 찾아보자.
- 이럴 때는 무식하게 해결해보고 생각해보자.

Hint
- 나와 반대로 '마지막에 들어온 키값을 중심'으로 실제'카운트'를 하는 방법을 사용함.
    - 나와 아주 정반대로 했음. 이래야 pop과 카운트를 효율적으로 할 수 있음. 
- 스택의 top에 새 카운트정보를 남겨둔다.
- 같은경우의 카운트만 늘려나간다.

... 이해도 안되고 납득도 안되는 코드로 뭘 하라는건지

Try3.
- 힌트는 얻었는데 너무 어렵다.
- 하나하나 차근차근 해결해보자.
- 짝짓기 = 스택
- 스택의 pop하며 카운팅.
    - 오름차순, 같은거 처리할때 top값을 날려버리며 알맞게 카운트.
        - 단순 오름차순, 내림차순 = n-1 .. 1+1+1+1 .. 각 카운트값 1.
        - 동일한 값 = 1+2+3+4.... 앞의 카운트값을 가져와서 + 1
- 가장 큰수가 들어왔을 때 남아있는 값들의 카운트를 해야함. (이게 핵심)

*/
#include <bits/stdc++.h>
using namespace std;
long long _N, _ret_cnt;
struct pan_t
{
    int height = 0;
    long long cnt = 1;
};
stack<pan_t> _pans; // 팬 정보

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N;
    for(int idx = 0; idx < _N; idx++)
    {
        pan_t now;
        cin >> now.height;
        // top과 같거나 크면 바로바로 처리
        while(!_pans.empty() && (_pans.top().height <= now.height))
        {
            if(_pans.top().height == now.height)
                now.cnt = _pans.top().cnt + 1; // 같으면
            else if(_pans.top().height < now.height)
                now.cnt = 1;   // 오름차순
            
            _ret_cnt += _pans.top().cnt;
            _pans.pop();
        }
        if(!_pans.empty())  // 내림차순
            _ret_cnt+=1;
        
        _pans.push(now);
    }
    cout << _ret_cnt;
    return 0;
}