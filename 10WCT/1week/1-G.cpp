/*
https://www.acmicpc.net/problem/9996
한국이 그리울 땐 서버에 접속하지

패턴: 알파벳들*알파벳들
주어지는 패턴에 맞는 string을 받으면 DA
아니면 NE

input:
- 총 string 갯수
- 패턴
- string 들
- ...

풀이1
- 패턴 string 받은 후 패턴 저장 (*으로 split)
- 문자열을 받아오는 즉시, 패턴 체크함수 동작
- 패턴체크함수()
    - 패턴의 총길이와 string의 총길이부터 체크/ Fail이면 NE
    - 앞 패턴과 이 길이에 맞게 string의 앞부분이 동일한지 체크/ Fail이면 NE
    - 뒤 패턴과 아 길이에 맞게 string의 뒷부분이 동일한지 체크/ Fail이면 NE
    - 이걸 다 통과하면 DA
*/
#include <bits/stdc++.h>
using namespace std;

std::string _pattern[2];
int _N = 0;

void split_pattern(string str, string delimeter)
{
    long long pos;
    while((pos = str.find(delimeter)) != string::npos)
    {
        _pattern[0] = str.substr(0, pos);
        str.erase(0,pos + delimeter.length());
    }
    _pattern[1] = str;
}

void check_pattern(string user_input)
{
    if(user_input.length() >= _pattern[0].length() + _pattern[1].length())
    {
        string front_input = user_input.substr(0, _pattern[0].length());
        string back_input = user_input.substr(user_input.length() -  _pattern[1].length(), user_input.length());
        if(front_input == _pattern[0] && back_input == _pattern[1])
        {
            cout << "DA" << "\n";
            return;
        }
    }
    cout << "NE" << "\n";
}

int main()
{
    string input;
    vector<string> inputs;
    cin >> _N;
    cin >> input;
    split_pattern(input,"*");
    if(_pattern[0].length() < 1)
        exit(0);
    for(int input_cnt = 0; input_cnt < _N; input_cnt++)
    {
        cin >> input;
        inputs.push_back(input);
    }
    for(auto str_i : inputs)
    {
        check_pattern(str_i);
    }
    return 0;
}