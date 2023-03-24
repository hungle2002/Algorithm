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
Node* rotateLeft(Node* n) {
        Node* x = n->pRight;
        Node* y = x->pLeft;
        x->pLeft = n;
        n->pRight = y;
        return x;
    }
    Node* rotateRight(Node* n) {
        Node* x = n->pLeft;
        Node* y = x->pRight;
        x->pRight = n;
        n->pLeft = y;
        return x;
    }
    Node* insert(Node* n ,T value)
    {
        if(n== NULL){
            return new Node(value);
        }
        if(n->data > value){
            n->pLeft =  insert(n->pLeft, value);
        }
        else{
            n->pRight = insert(n->pRight, value);
        }
        int deltaheigh = getHeightRec(n->pLeft)- getHeightRec(n->pRight);
        if(deltaheigh>1){
            if(value > n->pLeft->data){
                n->pLeft = rotateLeft(n->pLeft);
            }
            return rotateRight(n);
        }
        else if(deltaheigh<-1){
            if(value < n->pRight->data){
                n->pRight = rotateRight(n->pRight);
            }
            return rotateLeft(n);
        }
        return n;

    }
    void insert(const T &value)
    {
        //TODO
        this->root = insert(this->root, value);
    }
};
int main(){
AVLTree<int> avl;
for (int i = 10; i >=0 ; i--){
avl.insert(i);
}
avl.printTreeStructure();
}