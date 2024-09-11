/* https://www.acmicpc.net/problem/1062
가르침

남극에 김지민씨가 언어를 가르친다.
남극언어는 N개 밖에없음.
학생들은 K개의 글자까지밖에 못읽는다.
어떤 K개의 글자를 가르쳐야 최대개수의 단어를 학생들이 읽을수있을까
남극언어의 시작은 anta. 끝은 tica임. (a n t c i 글자도 알려줘야하는 거임)

Input
- 단어개수 N, K (1~N~50, 1~K~26)
- N개의 단어리스트. (영어소문자. 단어길이 8~15. 중복x)

Output
- 읽을 수 있는 단어의 최대값

Try1
- 남극언어 시작과 끝을 포함한 K 개의 글자를 읽을 수 있는것으로 보임.
- DFS로 해야함. (최대값 K가 정해져있어서)
- 각 단어를 비트마스킹 해서 리스트하자.(읽은수있는지 체크용)
- 알아야할 문자들을 리스트에 담자.(조합용도)
- 조합 할 변수를 하나 만들어서 조합해보자.

Try N
- 최소K보는 파트를 빼보니 정답률이 줄어듦을 확인. 완탐을 잘못하는걸로보임
- 다시 풀자...

Memo: TC는 모든 파라미터의 최대 최소를 대입하면 다 나옴. 다예상해봐야함.
*/
#include <bits/stdc++.h>
using namespace std;
int _N, _K, _ret, _be_known;
vector<int> _k_list;
vector<int> _in_list;

inline void get_ret(int here, int k_cnt, int pre_known)
{
    if(here > _k_list.size()) return;
    if((k_cnt == _K || k_cnt == _k_list.size())
        && (pre_known & 1<<('a'-'a')) 
        && (pre_known & 1<<('n'-'a')) 
        && (pre_known & 1<<('t'-'a')) 
        && (pre_known & 1<<('i'-'a'))
        && (pre_known & 1<<('c'-'a')))
    {
        int can_read_cnt = 0;
        //  읽어내는지 체크
        for(auto in: _in_list)
        {
            if((in&pre_known) == in)
                can_read_cnt++;
        }
        // // [[TESTCODE]]
        // cout << "(" << here << ")" << _ret << " vs " << can_read_cnt << "\n";

        _ret = max(_ret, can_read_cnt);
        return;
    }

    int known = pre_known | (1<<_k_list[here]);
    get_ret(here+1, k_cnt+1, known);
    get_ret(here+1, k_cnt, pre_known);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N >> _K;
    for(int in_cnt = 0; in_cnt < _N; in_cnt++)
    {
        string str_input;
        int input = 0;
        cin >> str_input;
        for(int cnt = 0; cnt < str_input.length(); cnt++)
        {
            int val = str_input[cnt] - 'a';
            input |= (1<<val);
            if(_be_known & (1<<val)) continue;
            _be_known |= (1<<val);
            _k_list.push_back(val);
        }
        _in_list.push_back(input);
    }
    
    if(_K < 5) // "antic"글자수보다 못읽겠다하면 종료 // <-  이거 빼면 14% 넣으면 66% 정답. 완탐을 잘못하고있는것으로 판단됨.
    {
        cout << 0;
        return 0;
    }
    get_ret(0,0,0);
    cout << _ret;
    return 0;
}