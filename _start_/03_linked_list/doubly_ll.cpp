#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node* prev;
    Node* next;
};

template <typename T>
class DoublyLinkedList
{
private:
    int count;
    Node<T>* header;   // Dummy. Header Node
    Node<T>* trailer;  // DUmmy. trailer Node

public:
    class iterator
    {
    private:
        Node<T>* ptr;
    public:
        iterator(): ptr(NULL){}
        iterator(Node<T>* p): ptr(p){}

        // * overloading
        T& operator*() {return ptr->data;}

        // ++iterator overloading
        iterator& operator++()
        {
            ptr = ptr->next;
            return *this;
        }
        // --iterator overloading
        iterator& operator--()
        {
            ptr = ptr->prev;
            return *this;
        }
        // != overloading
        bool operator!=(const iterator& it)const
        {
            return ptr != it.ptr;
        }
        // friend keyword
        friend class DoublyLinkedList;
    };

    DoublyLinkedList()
    {
        count = 0;
        header = new Node<T> {T(),NULL,NULL};
        trailer = new Node<T> {T(), NULL, NULL};
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

    iterator begin() const
    {
        return iterator(header->next);
    }

    iterator end () const
    {
        return iterator(trailer);
    }

    void insert(const iterator& pos, const T val)
    {
        Node<T>*p = pos.ptr;
        Node<T>* new_node = new Node<T>{val, p->prev, p};
        new_node->prev->next = new_node;
        new_node->next->prev = new_node;
        count++;
    }
    void push_front(const T val)
    {
        insert(begin(),val);
    }
    void push_back(const T val)
    {
        insert(end(),val);
    }

    void erase(const iterator& pos)
    {
        Node<T>*p = pos.ptr;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        count--;
    }
    void pop_front()
    {
        if(!empty())
            erase(begin());
    }
    void pop_back()
    {
        if(!empty())
            erase(--end());
    }

    
    iterator find(const T& val)
    {
        Node<T>* curr = header->next;
        while(curr->data != val && curr != trailer)
        {
            curr = curr->next;
        }
        return iterator(curr);
    }
    

    void print_all()
    {
        Node<T> *curr = header->next;
        while(curr != trailer)
        {
            std::cout<< curr->data << ", ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
    void print_reverse()
    {
        Node<T> *curr = trailer->prev;
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
    DoublyLinkedList<int> ll;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_back(40);
    ll.push_back(50);

    ll.print_all();
    ll.print_reverse();

    auto it = ll.find(20);
    if(it!=ll.end())
    {
        ll.insert(it,50);
    }
    ll.print_all();

    for(auto& n :ll)
    {
        cout<< n <<", ";
    }
    cout << endl;

    return 0;
}