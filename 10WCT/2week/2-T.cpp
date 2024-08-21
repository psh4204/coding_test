/* https://www.acmicpc.net/problem/17298
오큰수

오큰수 NGE: 수열에서 i번째 수의 오른쪽 수열 중에 해당숫자보다 크면서 가장 왼쪽값
- 값이 없다면 -1

Input
- 수열크기N(1~1,000,000)
- 수열

Output
- NGE(1) NGE(2) ... NGE(N)

Try1.
- 1M x 1M = 1,000,000,000,000: 시간초과와 메모리사이즈에 유의해야겠네
- 값 받아올때부터 pair<숫자, -1> 로 초기화하자.
- 이미 NGE가 나온값은 접근못하게 배열로 체크하자.

arr: (1,-1) (2, -1) ...
be_check: 1,2,3,4 ...

Try2.
- 시간초과 났음.. 진짜 ㅆㄹㅈㄷ..
- 입출력 싱크동기화 꺼도 그럼
- for문을 쓸데없이 동작시키는걸 최소화 해야하는건가?
    - 그러라고 be_check 리스트를 사용한건데 이거도 역부족이었음
    - 여기서 체크리스트의 erase가 시간을 어마어마하게 먹고있을거같음. O(n)

Try3.
- erase도 = 연산자도 시간복잡도가 O(n)..ㅋㅋㅋ 미치겠네. 근데 이게 최선임 여기선
- 현재받은값과 이전값이 같으면 뒤도 nge loop 안태우게 하자... 안되네
- erase 안쓰고 자료형을 다른걸 써야하나..
    - 가장 큰수를 받으면 어차피 삭제되는 것 -> stack 처럼써볼까
*/
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> _nums;    // data, nge
stack<int> _be_check;          // 체크해야할 리스트. nge화가 되면 삭제됨.
int _N, _pre_num;

void nge_loop(int input, int in_idx)
{
    // nge여부 체크 루프
    if(input != _pre_num)
    {
        // nge가 나왔으면 set
        while(!_be_check.empty() && _nums[_be_check.top()].first < input)
        {
            _nums[_be_check.top()].second = input; 
            _be_check.pop();
        }
    }
    _be_check.push(in_idx);    // 체크해야할 리스트에 idx 추가
    _pre_num = input;// 이전값 저장
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >>_N;
    _nums.resize(_N, {0,-1});
    for(int in_idx = 0; in_idx < _N; in_idx++)
    {
        int input = 0;
        cin >>input;
        _nums[in_idx].first = input;
        nge_loop(input, in_idx);
    }
    for(auto num: _nums)
        cout << num.second << " ";
    return 0;
}