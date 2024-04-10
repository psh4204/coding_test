#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    char data;
    Node* left;
    Node* right;

    Node(char d): data(d), left(nullptr), right(nullptr){}
};

// 전위순회
void preorder(Node* node)
{
    if(node)
    {
        cout<< node->data << ", ";
        preorder(node->left);
        preorder(node->right);
    }
}

// 중위순회
void inorder(Node* node)
{
    if(node)
    {
        inorder(node->left);
        cout<< node->data << ", ";
        inorder(node->right);
    }
}

// 후위순회
void postorder(Node* node)
{
    if(node)
    {
        postorder(node->left);
        postorder(node->right);
        cout<< node->data << ", ";
    }
}

// 레벨 우선 탐색
void levelorder(Node* node)
{
    // level 0 push
    queue<Node*> q;
    q.push(node);

    while(!q.empty())
    {
        // 앞 노드 출력 및 pop
        auto curr = q.front();
        q.pop();
        cout << curr->data << ", ";

        // 앞노드를 중심으로 다음 level 쌓기
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}


// 후위 순회로 삭제함수 짜보기
void delete_tree(Node* node)
{
    if(node)
    {
        delete_tree(node);
        delete_tree(node);
        delete node;
    }
}

int main(void)
{
    /*
            A
        B       C
    D     E         F
            G     H     I
    
    
    */
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->right = new Node('F');
    root->right->right->left = new Node('H');
    root->right->right->right = new Node('I');
    root->left->right->right = new Node('G');
    
    preorder(root); // A B D E G C F H I
    cout<<endl;
    inorder(root); // D B E G A C H F I
    cout<<endl;
    levelorder(root); // A B C D E F G H I
    cout<<endl;
    return 0;
}