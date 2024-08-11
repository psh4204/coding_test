/* https://www.acmicpc.net/problem/4659
비밀번호 발음하기

1. 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
3. 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.

Input
- 패스워드 (1~20. 영어 소문자로만 구성)
- 마지막은 end

Output
- <tv> is not acceptable.
- <ptoui> is not acceptable.

Try
- end받으면 끝
- 글자연속여부 체크
    - ee, oo는 허용.
    - 모음 3회, 자음 3회 연속 까지 허용.
- 모음포함여부 체크
*/
#include <bits/stdc++.h>
using namespace std;
char _aeiou[] ={'a','e','i','o','u'};

int main()
{
    while(1)
    {
        string pw;
        char pre_ch = 0; // 연속 글자 체크용.
        bool pass = true;
        bool is_there_aeiou = false; // 모음 체크
        int e_cont_cnt = 0; // e 연속 몇번? 2번초과부터 FAIL
        int o_cont_cnt = 0; // o 연속 몇번? 2번초과부터 FAIL
        int aeiou_cont_cnt = 0; // 모음 연속 몇번? 2번초과부터 FAIL
        int ja_cont_cnt = 0;    // 자음 연속 몇번? 2번초과부터 FAIL
        cin >> pw;
        if(pw == "end") break;
        for(auto ch: pw)
        {
            // 모음 체크
            bool is_aeiou_now = false;
            for(int aeiou_idx = 0; aeiou_idx < 5; aeiou_idx++)
            {
                // e와 o 인지 체크
                if(ch == _aeiou[aeiou_idx])
                {
                    if(ch == 'e')
                        e_cont_cnt++;
                    else if(ch == 'o')
                        o_cont_cnt++;
                    is_aeiou_now = true;
                    is_there_aeiou = true;
                    aeiou_cont_cnt++;
                    ja_cont_cnt = 0;
                    break;
                }
            }
            // 자음체크
            if(is_aeiou_now == false)
            {
                ja_cont_cnt++;
                aeiou_cont_cnt = 0;
            }
            // 연속글자 체크
            if(ch == pre_ch)
            {
                if(ch != 'e' && ch != 'o') // 연속글자인데- ee, oo가 아닐때 FAIL
                {
                    pass = false;
                    break;
                }
            }
            else
            {
                e_cont_cnt = 0;
                o_cont_cnt = 0;
            }
            // e와 o가 2번 초과 연속이라면 FAIL
            // 모음 or 자음 3회 초과 연속이라면 FAIL
            if((e_cont_cnt > 2 || o_cont_cnt > 2)||
                (aeiou_cont_cnt > 2 || ja_cont_cnt > 2))
            {
                pass = false;
                break;
            }
            pre_ch = ch;
            
            if(pass == false) break;
        }
        // PASS or FAIL
        if(pass == true && is_there_aeiou == true)
        {
            cout << "<" << pw << "> is acceptable.\n";
        }
        else
        {
            cout << "<" << pw << "> is not acceptable.\n";
        }
    }
    return 0;
}