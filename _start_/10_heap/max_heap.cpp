#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class MaxHeap
{
private:
    vector<int> vec;

public:
    MaxHeap() : vec(1) {}

    void push(int value)
    {
        vec.push_back(value);
        heapify_up(vec.size()-1);
    }
    void pop()
    {
        // 루트와 끝을 바꾼후 끝을 날린다.
        vec[1] = vec.back();
        vec.pop_back();
        // 규칙성이 맞는지 내려가며 체크한다.
        heapify_down(1);
    }
    int top() const {return vec[1];}
    int size() {return vec.size() -1;}
    bool empty() {return vec.size() == 1;}

private:
    int parent(int i) {return i/2;}
    int left(int i) {return 2*i;}
    int right(int i) {return 2 * i +1;}
    
    // 삽입한 노드와 부모노드 비교. 부모-자식간 규칙이 깨진지 체크 후 깨졌으면 swap. 반복.
    void heapify_up(int i)
    {
        if(i > 1 && vec[i] > vec[parent(i)])
        {
             swap(vec[i], vec[parent(i)]);
             heapify_up(parent(i));
        }
    }

    // 해당 부모노드가 자식노드와 규칙이 맞는지 체크. 안맞다면 자식중 더큰노드와 swap. 반복.
    void heapify_down(int i)
    {
        int largest = i;
        if(left(i) < vec.size() && vec[left(i)] > vec[largest])
            largest = left(i);
        if(right(i) < vec.size() && vec[right(i)] > vec[largest])
            largest = right(i);
        if(largest != i)
        {
            swap(vec[i], vec[largest]);
            heapify_down(largest);
        }
    }

};

using namespace std;

int main(void)
{
    MaxHeap heap;
    heap.push(10);
    heap.push(5);
    heap.push(15); 
    heap.push(7);
    heap.push(3);
    heap.push(14);
    heap.push(8);
    heap.push(4);

    while(!heap.empty())
    {
        cout << heap.top() << ", ";
        heap.pop();
    }
    cout << endl;

    return 0;
}