#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int data; // 키 값 겸 데이터로 사용 할 예정
    Node* left;
    Node* right;
    Node(int d): data(d), left(nullptr), right(nullptr){}
};

class BinarySearchTree
{
private:
    Node* root = nullptr;

public:
    void insert(int value)
    {
        if(!root)
            root = new Node(value);
        else
            insert_implement(root, value);
    }

    Node* find(int value)
    {
        return find_implement(root, value);
    }

    void preorder()
    {
        preorder_implement(root);
    }

    void inorder()
    {
        inorder_implement(root);
    }

    void postorder()
    {
        postorder_implement(root);
    }

    void levelorder()
    {
        levelorder_implement(root);
    }

    void erase(int value)
    {
        root = erase_implement(root, value);
    }

private:
    void insert_implement(Node* curr, int value)
    {
        // value가 키값 보다 작다면 left, 크다면 right
        if(value < curr->data)
        {
            // 노드가 없다면 삽입. 있다면 재귀.
            if(!curr->left)
                curr->left = new Node(value);
            else
                insert_implement(curr->left, value);
        }
        else
        {
            if(!curr->right)
                curr->right = new Node(value);
            else
                insert_implement(curr->right, value);
        }
    }
    Node* find_implement(Node* curr, int value)
    {
        // 노드가 없으면 null 리턴
        if(curr == nullptr)
            return nullptr;
        
        // 찾는 데이터가 있다면 해당 노드 리턴
        if(value == curr->data)
            return curr;
        // 없다면 규칙대로 find 재귀 하며 리턴.
        else
        {
            if(value < curr->data)
                return find_implement(curr->left, value);
            else
                return find_implement(curr->right, value);
        }
    }

    // 전위순회
    void preorder_implement(Node* node)
    {
        if(node)
        {
            cout<< node->data << ", ";
            preorder_implement(node->left);
            preorder_implement(node->right);
        }
    }

    // 중위순회
    void inorder_implement(Node* node)
    {
        if(node)
        {
            inorder_implement(node->left);
            cout<< node->data << ", ";
            inorder_implement(node->right);
        }
    }

    // 후위순회
    void postorder_implement(Node* node)
    {
        if(node)
        {
            postorder_implement(node->left);
            postorder_implement(node->right);
            cout<< node->data << ", ";
        }
    }

    // 레벨 우선 탐색
    void levelorder_implement(Node* node)
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

    // 후속 노드 찾기
    // 오른쪽 서브트리에서 가장작은값(가장 왼쪽값) 리턴.
    Node* successor(Node* node)
    {
        auto curr = node->right;
        while(curr&&curr->left)
            curr = curr->left;
        return curr;
    }

    // 노드 삭제 후, 부모노드가 가리켜야할 노드주소를 리턴
    Node* erase_implement(Node* node, int value)
    {
        // 노드가 없으면 null
        if(!node)
            return nullptr;
        // value가 노드값보다 작으면 왼쪽으로 재귀
        if(value < node->data)
            node->left = erase_implement(node->left, value);
        // 더크면 오른쪽으로 재귀
        else if(value > node->data)
            node->right = erase_implement(node->right, value);
        // 같다면
        else
        {
            if(node->left && node->right)
            {
                // CASE3. 자식노드가 두개나 있으면. 후속노드를 현재노드와 복사 후 후속노드 삭제.
                //        - 후속노드: successor.오른쪽서브노드중 가장 작은 값
                auto succ = successor(node);
                node->data = succ->data;
                node->right = erase_implement(node->right, succ->data);
            }
            else
            {
                // CASE1. 자식노드 없을경우. 그대로 삭제
                //CASE2. 자식노드가 하나만 있을 경우. 부모와 이어주기
                auto temp = node->left? node->left: node->right;
                delete node;
                return temp;
            }    
        }
        return node;
    }
};

int main(void)
{
    /*
    7 is found
    15 is not found
    5, 6, 7, 10, 13, 14, 16, 18,
    5, 6, 7, 8, 9, 10, 13, 14, 16, 18,
    */
    BinarySearchTree bst;
    bst.insert(10);
    bst.insert(14);
    bst.insert(5);
    bst.insert(7);
    bst.insert(18);
    bst.insert(6);
    bst.insert(16);
    bst.insert(13);

    if(bst.find(7)) cout<<"7 is found" <<endl;
    else cout<<"7 is not found" <<endl;

    if(bst.find(15)) cout<<"15 is found" <<endl;
    else cout<<"15 is not found" <<endl;

    bst.inorder();
    cout << endl;
    bst.insert(8);
    bst.insert(9);
    bst.inorder();
    cout << endl;
    
    bst.erase(5);
    bst.inorder();
    cout << endl;

    return 0;
}