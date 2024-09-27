/* https://www.acmicpc.net/problem/9935
문자열 폭발

문자열 사이에 폭발하는 문자열이 숨어있음.
문자열이 폭발하고나면 그건 사라지고, 나머지는 다시 합쳐짐

과정
- 문자열 중에서 모든 폭발문자열이 폭발하고 순서대로 이어붙여지며 만들어짐.
- 새로생긴 문자열에 폭파 문자열 포함 가능
- 폭발문자열없을때까지 계속 됨.

모든 문자열이 폭발이 끝난후 어떤문자열이 남는지 궁금하다.
- 남은 문자열이 없으면  "FRULA" 출력.
폭발문자열은 같은 문자 두개 이상 포함하지 않음.

Input
- 문자열 (길이 1~1,000,000)
- 폭파문자열(길이 1~36)
- 참고: 문자열은 모두 영어(소문자, 대문자)

Output
- 폭발 후 남은 문자열 출력.

Try1
- 문자열 폭발 이라했지만, 실제론 그 문자열이 삭제되는 양상
- 단순하게 구현
    - 문자열 인덱스화
    - 폭팔문자열의 첫번째 문자와 같은걸 찾으면, 인덱스값 0으로 수정.
        - 다음 숫자 다음 숫자 체크
- 좀더 효율적이게 구현
    - 폭파문자의 첫 문자열과 같은 인덱스 담은 배열을 만들어서 사용하자
    - 이때 여기서도 삭제가 일어나면 얘네도 -1으로 수정. <- 이게 무거울거 같음 (1M ^2)
        - 일단 구현 부터하자
- 삭제 루프 조건
    - 폭파문자의 첫 문자열과 같은 인덱스 담은 배열을 다 돌았을때, 
    아무런 일이 안벌어지면 시마이

Try2
- erase 그냥 써도됨
    - 내가 원래 사용하려했던 것은, erase할 친구에 플래그0을넣는 그런것을 생각했는데
    이건 결국엔 다시 새로운 배열을 만들어야한다는 것에서 erase보다 무겁거나 비효율적이라 생각이 듦.
    - 결국 erase가 맞음
- 스택써도 됨.(폭발 혹은 짝짓기면 스택 한번 써봐도됨.)

Try2.1
- erase 로 구현중. 충분히 속도나오는데, 최적화 조금더 필요
- temp str에 char을 넣고 삭제하고, 이런 시퀀스로 하는 최적화 기법도 괜찮아 보인다. (유사 스택?)
- 이를테면 스택쓰는게 맞을거같은데? 스택이 구현난이도가 더 낮겠음

*/
#include <bits/stdc++.h>
using namespace std;
#define EMPTY "FRULA"
string _input, _bomb, _ret;
bool _can_i_run = true;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _input >> _bomb;
    int b_len = _bomb.length();
    int loop_idx = 0;
    for(auto ch : _input)
    {
        _ret += ch;
        if(loop_idx < _ret.length() && loop_idx >= b_len-1 && _ret[loop_idx] == _bomb[b_len-1])
        {
            // cout << _ret << " " << _ret[loop_idx] << " " 
            //     << loop_idx << " " << _ret.substr(loop_idx-b_len+1, b_len) << "\n"; //[[TEST]]
            if(_ret.substr(loop_idx-b_len+1, b_len) == _bomb)
            {
                // cout << _ret << " " << loop_idx << " "; //[[TEST]]

                _ret.erase(_ret.end()-b_len, _ret.end());
                loop_idx = max(-1, loop_idx-b_len);

                // cout << _ret << " " << loop_idx << "\n"; //[[TEST]]
            }
        }
        loop_idx++;
    }
    if(_ret.empty())
    {
        cout << EMPTY;
        return 0;
    }
    cout << _ret;
    return 0;
}