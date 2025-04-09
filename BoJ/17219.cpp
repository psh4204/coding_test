/* 비밀번호 찾기
https://www.acmicpc.net/problem/17219

메모장에서 비밀번호를 찾는 프로그램 작성하기

입력
- 사이트 주소 숫자 N (1~100,000) 비번을 찾으려는 사이트주소수 M (1~100,000)
- 각 사이트 주소와 비밀번호 (String String)
- 찾고싶은 사이트 주소

출력
- 비번
*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_M;
unordered_map<string, string> g_pwBook;

int main()
{
    cin >> g_N >> g_M;
    while(g_N--)
    {
        string site, pw;
        cin >> site >> pw;
        g_pwBook.insert({site, pw});
    }
    while(g_M--)
    {
        string site;
        cin >> site;
        cout << g_pwBook[site] << "\n";
    }
    return 0;
}