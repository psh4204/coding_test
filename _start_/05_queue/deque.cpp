#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
    deque<int> d {1,2,3,4,5};
    d.push_front(6);
    d.push_back(7);

    for(auto i : d)
    {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}