/*
https://www.acmicpc.net/problem/1159
농구 경기

성이 같은(이름의 앞글자) 농구선수 5명을 선발한다.
5명 미만이면 기권

- input
    - N : 몇명
    - 소문자영어이름 ..
    - ...
- output
    - 5명선수선발: 선발된 성들 (예시: b, bk)
    - 없으면 기권: PREDAJA

풀이1.
- 알파벳 map 선언
- input 받을때마다 해당 알파벳의 value에 ++
- output 주기전에 value 5이상의 값만 루프로 체크한 후 내보낸다.
*/

#include <bits/stdc++.h>
using namespace std;


int _people_cnt = 0;
map<char, int> _alpha;
string _ret;

int main()
{
    cin >> _people_cnt;
    if(_people_cnt < 1 || _people_cnt >150)
        exit(0);    
    for(int input_cnt = 0; input_cnt < _people_cnt; input_cnt++)
    {
        string people_name;
        cin >> people_name;
        _alpha[people_name[0]]++;
    }
    for(auto a: _alpha)
    {
        if(a.second >= 5)
            _ret += a.first;
    }
    if(_ret.length() < 1)
        cout << "PREDAJA";
    else
        cout << _ret;

    return 0;
}