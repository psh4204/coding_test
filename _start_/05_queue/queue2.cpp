#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.pop();

    cout << q.front() << endl;
    q.push(40);

    while(!q.empty())
    {
        auto& e = q.front();
        cout<< e << endl;
        q.pop();
    }

    return 0;
}