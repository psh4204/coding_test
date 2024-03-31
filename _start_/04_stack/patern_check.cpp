#include <iostream>
#include <stack>

using namespace std;

/// @brief 괄호 체크 함수
/// @param s 문자열
/// @return 
bool patern_check(const string& s)
{
    stack<char> stk;

    for(char c : s)
    {
        if(c == '(' || c == '{' || c == '[')
        {
            stk.push(c);
        }
        else
        {
            if(stk.empty() ||
                (stk.top() != '(' && c ==')')||
                (stk.top() != '{' && c =='}')||
                (stk.top() != '[' && c ==']') )
            {
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}

int main(void)
{
    // correct
    cout<< "(){}[]: "<< patern_check("(){}[]") << endl;
    cout<< "(((()))): "<< patern_check("(((())))") << endl;
    cout<< "(){[()]()}: "<< patern_check("(){[()]()}") << endl;

    // wrong
    cout<< "(){}]: "<< patern_check("(){}]") << endl;
    cout<< ")(: "<< patern_check(")(") << endl;
    cout<< "({[]: "<< patern_check("({[]") << endl;

    return 0;
}