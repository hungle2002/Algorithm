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
    Node* deleteLeftBalance(Node* &root,bool &shorter) {
    if (root->balance==RH) root->balance=EH;
    else if (root->balance==EH) {
        root->balance=LH;
        shorter=false;
    }
    else {
        Node *leftTree=root->pLeft;
        if (leftTree->balance==RH) {
            Node*rightTree=leftTree->pRight;
            if (rightTree->balance==RH) {
                leftTree->balance=LH;
                root->balance=EH;
            }
            else if (rightTree->balance==EH) {
                root->balance=RH;
                leftTree->balance=EH;
            }
            else {
                root->balance=RH;
                leftTree->balance=EH;
            }
            rightTree->balance=EH;
            root->pLeft=rotateLeft(leftTree);
        }
        else if (leftTree->balance!=EH) {
            root->balance=EH;
            leftTree->balance=EH;
        }
        else {
            root->balance=LH;
            leftTree->balance=RH;
            shorter=false;
        }
        root=rotateRight(root);
    }
    return root;
}
Node* deleteRightBalance(Node* &root,bool &shorter) {
    if (root->balance==LH) root->balance=EH;
    else if (root->balance==EH) {
        root->balance=RH;
        shorter=false;
    }
    else {
        Node*rightTree=root->pRight;
        if (rightTree->balance==LH) {
            Node*leftTree=rightTree->pLeft;
            if (leftTree->balance==LH) {
                rightTree->balance=RH;
                root->balance=EH;
            }
            else if (leftTree->balance==EH) {
                root->balance=LH;
                rightTree->balance=RH;
            }
            else {
                root->balance=LH;
                rightTree->balance=EH;
            }
            leftTree->balance=EH;
            root->pRight=rotateRight(rightTree);
        }
        else {
            if (rightTree->balance!=EH) {
                root->balance=EH;
                rightTree->balance=EH;
            }
            else {
                root->balance=RH;
                rightTree->balance=LH;
                shorter=false;
            }
            root=rotateLeft(root);
        }
    }
    return root;
}
Node* AVLDelete(Node* root, T deleteKey, bool &shorter, bool &success) {
    if (root==NULL) {
        shorter=false;
        success=false;
        return NULL;
    }
    if (deleteKey<root->data) {
        root->pLeft=AVLDelete(root->pLeft,deleteKey,shorter,success);
        if (shorter) {
            root=deleteRightBalance(root,shorter);
        }
    }
    else if (deleteKey>root->data) {
        root->pRight=AVLDelete(root->pRight,deleteKey,shorter,success);
        if (shorter) {
            root=deleteLeftBalance(root,shorter);
        }
    }
    else {
        Node *deleteNode=root;
        if (root->pRight==NULL) {
            Node*newroot=root->pLeft;
            success=true;
            shorter=true;
            delete(deleteNode);
            return newroot;
        }
        else if (root->pLeft==NULL) {
            Node*newroot=root->pRight;
            success=true;
            shorter=true;
            delete(deleteNode);
            return newroot;
        }
        else {
            Node*exchPtr=root->pLeft;
            while(exchPtr->pRight!=NULL) exchPtr=exchPtr->pRight;
            root->data=exchPtr->data;
            root->pLeft=AVLDelete(root->pLeft,exchPtr->data,shorter,success);
            if (shorter) {
                root=deleteRightBalance(root,shorter);
            }
        }
    }
    return root;
}
void remove(const T &value){
    //TODO
    bool shorter,success;
    root=AVLDelete(root,value,shorter,success);
}
};
int main(){
AVLTree<int> avl;
for (int i = 10; i >=0 ; i--){
avl.insert(i);
}
avl.printTreeStructure();
}