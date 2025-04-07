/* 집합
https://www.acmicpc.net/problem/11723

공집합 S에 다음을 수행하는 프로그램작성하시오
- add x: S에 x 추가 (1~x~20). 이미있는경우 무시
- remove x: S에서 x제거. x가 없는경우 무시
- check x: S에 x가 있으면 1, 없으면 0
- toggle x: S에 x가 있므녀 x제거, 없으면 x 추가
- all: S를 {1~20}으로 바꾼다 (?) (가득채우란 말인듯)
- empty: S를 공집합으로 바꾼다 (비우란 말인듯)
*/
#include <bits/stdc++.h>
using namespace std;
vector<bool> g_nums(21,0);
int g_M, g_input;
string g_instStr;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_M;
    while(g_M--)
    {
        cin >> g_instStr;
        if(g_instStr.find("add") != string::npos)
        {
            cin >> g_input;
            g_nums[g_input] = true;
        }
        else if(g_instStr.find("remove") != string::npos)
        {
            cin >> g_input;
            g_nums[g_input] = false;
        }
        else if(g_instStr.find("check") != string::npos)
        {
            cin >> g_input;
            cout << g_nums[g_input] << "\n";
        }
        else if(g_instStr.find("toggle") != string::npos)
        {
            cin >> g_input;
            g_nums[g_input] = !g_nums[g_input];
        }
        else if(g_instStr.find("all") != string::npos)
        {
            for(auto isNum : g_nums)
                isNum = true;
        }
        else if(g_instStr.find("empty") != string::npos)
        {
            for(auto isNum : g_nums)
                isNum = false;
        }
    }
    return 0;
}