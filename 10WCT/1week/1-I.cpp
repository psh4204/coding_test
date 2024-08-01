/*
https://www.acmicpc.net/problem/1620

포켓몬 마스터 이다솜

주어진 포켓몬들 중에서 번호를 물으면 포켓몬, 포켓몬을 물으면 번호를 답하라

입력
- N M (포켓몬수N, 맞춰야하는 문제 M. 1 ~ 100,000)

- 포켓몬이름(첫글자 또는 마지막글자가 대문자)
- 포켓몬이름 ... (N번받음)

- 문제 (번호 or 포켓몬 이름)

출력
- 각 문제의 답 출력

Try1
- vector로 값 받아와서 적절히 잘 출력하면 끝아닌가?
- string 파라미터를 쓸때 &을 쓰자. 일부 컴파일러가 문제를 일으켜서 써야함.
==> 시간초관

Try2
- 메모리도 충분한데 vector하나 map 하나 만들자

*/
#include <bits/stdc++.h>
using namespace std;
int _N, _M = 0;
vector<string> _pocketmon_names;
map<string, int> _pocketmon_names_nums;
vector<string> _answers;

bool is_name(string &str_input)
{
    if((str_input[0] >= 'a' && str_input[0] <= 'z') 
    || (str_input[0] >= 'A' && str_input[0] <= 'Z'))
        return true;
    return false;
}

int main()
{
    cin >> _N >> _M;
    for(int pocketmon_cnt = 0; pocketmon_cnt < _N; pocketmon_cnt++)
    {
        string pocketmon;
        cin >> pocketmon;
        _pocketmon_names.push_back(pocketmon);
        _pocketmon_names_nums.insert({pocketmon, pocketmon_cnt+1});
    }
    for(int problem_cnt = 0; problem_cnt < _M; problem_cnt++)
    {
        string problem;
        cin >> problem;
        if(is_name(problem))
        {
            _answers.push_back(to_string(_pocketmon_names_nums[problem]));
        }
        else
        {
            _answers.push_back(_pocketmon_names[stoi(problem) -1]);
        }
    }
    for(auto answer: _answers)
        cout << answer << "\n";
    return 0;
}