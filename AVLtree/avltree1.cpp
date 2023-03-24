#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }
    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
    Node* rightRotate(Node* root){
        Node* leftTree = root->pLeft;
        root->pLeft = leftTree->pRight;
        leftTree->pRight=root;
        root = leftTree;
        return leftTree;
    }
    Node* leftRotate(Node* root){
        Node* rightTree = root->pRight;
        root->pRight = rightTree->pLeft;
        rightTree->pLeft = root;
        root = rightTree;
        return rightTree;
    }
    Node* leftBalance(Node* &root, bool &taller){
        Node* leftTree = root->pLeft;
        // left of left
        if(leftTree->balance == LH){
            leftTree->balance = EH;
            root->balance = EH;
        }
        // right of left
        else{
            Node* rightTree = leftTree->pRight;
            if(rightTree->balance == LH){
                root->balance = RH;
                leftTree->balance = EH;
                rightTree->balance = EH;
            }
            else if(rightTree->balance == EH){
                root->balance = EH;
                leftTree->balance = EH;
            }
            else{
                root->balance = EH;
                leftTree->balance = LH;
                rightTree->balance = EH;
            }
        root->pLeft = rightRotate(leftTree);
        }
        root = rightRotate(root);
        taller = 0;
        return root;
    }

    Node* rightBalance(Node* &root, bool &taller){
        Node* rightTree = root->pRight;
        // right of right
        if(rightTree->balance == RH){
            root->balance = EH;
            rightTree->balance=EH;
        }
        // left of right
        else{
            Node* leftTree = rightTree->pLeft;
            if(leftTree->balance == LH){
                root->balance =EH;
                rightTree->balance = RH;
                leftTree->balance = EH;
            }
            else if(leftTree->balance == EH){
                root->balance = EH;
                rightTree->balance = EH;
            }
            else{
                root->balance = LH;
                rightTree->balance = EH;
                leftTree->balance = EH;
            }
            root->pRight = leftRotate(rightTree);
        }
        root = leftRotate(root);
        taller = 0;
        return root;
    }

    Node* solve_insert(Node* &root, T value, bool &taller){
        if(root == NULL){
            root = new Node(value);
            taller=1;
            return root;
        }
        if(root->data < value){
            root->pRight = solve_insert(root->pRight, value, taller);
            if(taller){
                // the right is taller
                if(root->balance == RH){
                    root = rightBalance(root, taller);
                }
                else if(root ->balance == EH){
                    root->balance = RH;
                }
                else{
                    root->balance = EH;
                    taller=0;
                }
            }
        }
        else{
            root->pLeft = solve_insert(root->pLeft, value, taller);
            if(taller){
                // the left is taller
                if(root->balance == RH){
                    taller=0;
                    root->balance = EH;
                }
                else if(root->balance == EH){
                    root->balance = LH;
                }
                else{
                    root = leftBalance(root, taller);
                }
            }
        }
        return root;
    }
void insert(const T &value)
    {
        //TODO
        bool taller = 0;
        this->root = solve_insert(this->root, value, taller);
    }
};
int main(){
AVLTree<int> avl;
for (int i = 10; i >=0 ; i--){
avl.insert(i);
}
avl.printTreeStructure();
}