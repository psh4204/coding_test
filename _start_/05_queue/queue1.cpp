#include <iostream>
#include <list>

template<typename T>
class Queue
{
private:
    std::list<T> lst;
public:
    Queue(){}
    void enqueue(const T& e) {lst.push_back(e);}
    void dequeue(){lst.pop_front();}
    const T& front() const{return lst.front();}

    bool empty() const{return lst.empty();};
    int size() const{return lst.size();};
};

using namespace std;

int main(void)
{
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();

    cout << q.front() << endl;
    q.enqueue(40);

    while(!q.empty())
    {
        auto& e = q.front();
        cout<< e << endl;
        q.dequeue();
    }

    return 0;
}