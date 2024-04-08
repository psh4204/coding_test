#include <iostream>

using namespace std;

struct Node
{
    char data;
    Node* left;
    Node* right;

    Node(char d): data(d), left(nullptr), right(nullptr){}
};

int main(void)
{
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    
    return 0;
}