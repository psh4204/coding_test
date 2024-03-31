#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.pop();

    cout<< stk.top() << endl;
    stk.push(40);
    
    while(!stk.empty())
    {
        auto& e = stk.top();
        cout << e << ", ";
        stk.pop();
    }
    cout<<endl;
    return 0;
}