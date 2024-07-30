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

int main()
{
    string input;
    cin >> input;
    // 패턴 가져온 후 아무것도 패턴없는거까지 
    split_pattern(input,"*");
    if(_pattern[1].length() < 1)
        exit(0);
    
    return 0;
}