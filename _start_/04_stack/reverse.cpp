#include <iostream>
#include <stack>
#include <vector>
using namespace std;

string reverse(const string& str)
{
    string res;
    stack<char> stk;
    for(char c: str)
    {
        stk.push(c);
    }
    while(!stk.empty())
    {
        res+=stk.top();
        stk.pop();
    }

    return res;
}

template <typename T>
void reverse(vector<T>& vec)
{
    // default stack init
    //stack<T> stk; // deque stack
    ////Init
    // for(const auto& e: vec)
    // {
    //     stk.push(e);
    // }

    // vector stack init
    stack<T,vector<T>> stk(vec);

    for(int i =0; i <vec.size(); i++)
    {
        vec[i] = stk.top();
        stk.pop();
    }
}

int main(void)
{
    string str1 = "Oh";
    string str2 = "HellNo..";

    cout<< str1 << " -> " << reverse(str1) <<endl;
    cout<< str2 << " -> " << reverse(str2) <<endl;

    vector<int> vec {10,20,30,40,50};
    reverse<int>(vec);

    for(auto e: vec)
    {
        cout << e << ", ";
    }
    cout << endl;
    


    return 0;
}