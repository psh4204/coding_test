#include <iostream>

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList
{
private:
    int count;
    Node* header;   // Dummy. Header Node
    Node* trailer;  // DUmmy. trailer Node

public:
    DoublyLinkedList()
    {
        count = 0;
        header = new Node {0,NULL,NULL};
        trailer = new Node {0, NULL, NULL};
        header -> next = trailer;
        trailer -> prev = header;
    }
    ~DoublyLinkedList()
    {
        while(!empty())
        {
            pop_front();
        }
        delete header;
        delete trailer;
    }
    
    void insert(Node* p, int val)
    {
        Node* new_node = new Node{val, p->prev, p};
        new_node->prev->next = new_node;
        new_node->next->prev = new_node;
        count++;
    }
    void push_front(int val)
    {
        insert(header->next,val);
    }
    void push_back(int val)
    {
        insert(trailer,val);
    }

    void erase(Node* p)
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        count--;
    }
    void pop_front()
    {
        if(!empty())
            erase(header->next);
    }
    void pop_back()
    {
        if(!empty())
            erase(trailer->prev);
    }

    void print_all()
    {
        Node *curr = header->next;
        while(curr != trailer)
        {
            std::cout<< curr->data << ", ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
    void print_reverse()
    {
        Node *curr = trailer->prev;
        while(curr != header)
        {
            std::cout<< curr->data << ", ";
            curr = curr->prev;
        }
        std::cout<<std::endl;
    }

    bool empty()
    {
        return count==0;
    }

    int size()
    {
        return count;
    }

};



int main(void)
{
    DoublyLinkedList ll;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_back(40);
    ll.push_back(50);

    ll.print_all();
    ll.print_reverse();

    ll.pop_front();
    ll.pop_back();
    ll.print_all();
    ll.print_reverse();

    ll.push_front(100);
    ll.push_back(200);
    ll.print_all();
    ll.print_reverse();

    return 0;
}