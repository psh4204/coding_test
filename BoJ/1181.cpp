/* https://www.acmicpc.net/problem/1181
단어정렬

알파벳 소문자로 이루어진 N개의 단어가들어오면 정렬하기
1. 짧은것 부터
2. 길이가같으면 사전순 (딕셔너리 쓰라고 협박하노)
- 단어중복 없음(map,set 써라)

입력
- N (1~20000)
- Strings

출력
- 단어정렬 후 출력

풀이
- set으로 값 받고 그대로 출력
*/
#include <bits/stdc++.h>
using namespace std;
struct Compare{
    bool operator() (const string& first, const string& second) const
    {
        if(first.length() < second.length())
            return true;
        else if(first.length() == second.length())
        {
            if(first < second)
            return true;
        }
        return false;
    }
};

int _N;
set<string, Compare> _strlist;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N;
    for(int n_idx = 0; n_idx < _N; n_idx++)
    {
        string in;
        cin >> in;
        _strlist.insert(in);
    }
    for(auto it: _strlist)
        cout << it << "\n";
    return 0;
}