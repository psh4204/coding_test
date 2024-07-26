#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};


class LinkedList
{
private:    
    Node* head;
public:
    // 생성자, 소멸자
    LinkedList() : head(NULL) {}; // 
    ~LinkedList()
    {
        while(!empty())
        {
            pop_front();
        }
    }

    void push_front(int val)
    {
        Node * new_node = new Node {val, NULL};
        if(head != NULL)
            new_node -> next = head;
        head = new_node;
    }
    void pop_front()
    {
        if(head == NULL)
            return;
        // 반드시 heap에있는 head를 삭제해야한다.
        Node* frist = head;
        head = head -> next;
        delete frist;
    }
    void print_all()
    {
        Node* curr = head;
        while(curr != NULL)
        {
            cout << curr->data << ", ";
            curr = curr->next;
        }
        cout << endl;
    }
    bool empty()
    {
        return head == NULL;
    }
};


int main()
{
    LinkedList ll;

    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.push_front(40);
    ll.pop_front();
    ll.push_front(50);
    ll.print_all(); // 50, 30, 20, 10, 
    return 0;
}