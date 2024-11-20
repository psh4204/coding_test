/* https://www.acmicpc.net/problem/14889
스타트와 링크

축구하기로한 인원 N(무조건 짝수). 2팀으로 나눠서 진행
스킬배열에서, i번, j번 사람이 같은팀일 때, 능력치가 더해짐 (뭔소리야?)
- i번, j번 사람이 같은 팀 -> Sij + Sji 
- 팀의 총 능력치는 이런 덧셈의 합임

축구의 재미를 위해 팀 능력치 최소화를 해보자.

입력
- 인원 N (4~20, 짝수)
- 2차월 S배열 (Sii Sjj 는 항상 0. 나머지는 1~100)

출력
- 두 팀의 능력치 최소 차이

풀이
- 조합 두번해야하는 문제
- 1~N 까지 순열 (재귀)
- 조합 후 두팀으로 쪼개서, 2개씩 뽑는 조합(루프) 후 각 능력치 덧셈
- 각팀의 능력치 뺄셈 후 min값 체크
*/
#include <bits/stdc++.h>
using namespace std;
int _N, _half_N, _min_ret = 987654321;
vector<int> _peoples;
vector<vector<int>> _S;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N;
    _half_N = _N/2;
    _S.resize(_N,vector<int>(_N,0));
    for(int y = 0; y < _N; y++)
    {
        for(int x = 0; x < _N; x++)
            cin >> _S[y][x];
    }
    for(int p_idx = 0; p_idx < _N; p_idx++)
        _peoples.push_back(p_idx);

    do
    {
        // // TEST
        // cout << "> ";
        // for(int p_idx = 0; p_idx < _N; p_idx++) cout << _peoples[p_idx] << " ";
        // cout << "\n";
        // // ----
        
        // 스타팀 능력치 체크
        int s_score = 0;
        for(int i_idx = 0; i_idx < _half_N; i_idx++)
        {
            for(int j_idx = i_idx +1; j_idx < _half_N; j_idx++)
            {
                s_score += _S[_peoples[i_idx]][_peoples[j_idx]]; 
                s_score += _S[_peoples[j_idx]][_peoples[i_idx]];
            }
        }
        // 링크팀 능력치 체크
        int l_score = 0;
        for(int i_idx = _half_N; i_idx < _N; i_idx++)
        {
            for(int j_idx = i_idx +1; j_idx < _N; j_idx++)
            {
                l_score += _S[_peoples[i_idx]][_peoples[j_idx]]; 
                l_score += _S[_peoples[j_idx]][_peoples[i_idx]];
            }
        }
        // cout << ">> " << abs(s_score - l_score) << "\n"; // TEST
        _min_ret = min(_min_ret, abs(s_score - l_score));
        if(_min_ret == 0)
        {
            cout << _min_ret;
            exit(0);
        }
    } while (next_permutation(_peoples.begin(), _peoples.end()));
    
    cout << _min_ret;
    return 0;
}