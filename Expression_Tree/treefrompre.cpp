#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
class ETNode {
public: 
    char val;
    ETNode *left;
    ETNode *right;
    ETNode() {
        this->left = this->right = NULL;
    };
    ETNode(char val) {
        this->val = val;
        this->left = this->right = nullptr;
    }
    ETNode(char val, ETNode* left, ETNode* right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};
    void printInorder(ETNode* root){
        if(!root) return;
        cout << root->val;
        printInorder(root->left);
        printInorder(root->right);
    }
ETNode* constructET(string str){
    stack<ETNode*>s;
    for(int i=0; i<str.length(); i++){
        ETNode* tmp = new ETNode(str[i]);
        // operand
        if(str[i]<'0' || str[i]>'9'){
            ETNode* a = s.top();
            s.pop();
            ETNode* b = s.top();
            s.pop();
            tmp->left = a;
            tmp->right = b;
        }
        s.push(tmp);
    }
    return s.top();
}
int main(){
    string s = "+*47+-173";
    reverse(s.rbegin(), s.rend());
    ETNode* root = constructET(s);
    printInorder(root);
}