#include<bits/stdc++.h>
using namespace std;
int GCD(int a, int b){
    if(a<0) a= -a;
    if(b<0) b = -b;
    if(a == 0) return b;
    b = b%a;
    return GCD(b, a);
}
class Node{
public:
    int tu;
    int mau;
    Node* left;
    Node* right;
    Node(){
        left = right = NULL;
    }
    Node(int _tu, int _mau){
        tu = _tu;
        mau = _mau;
        left = right = NULL;
    }
    Node* operator+(Node* a){
        int _tu =tu * a->mau + mau*a->tu;
        int _mau =mau*a->mau;
        bool flag = (_tu*_mau)<0;
        int gcd = GCD(_tu, _mau);
        tu = abs(_tu) / gcd;
        mau = abs(_mau)/gcd;
        if(flag) tu*=-1;
        return this;
    }
};
int main(){
    Node* a = new Node(-1,3);\
    Node* b = new Node(-1,6);
    a = a->operator+(b);
    cout << a->tu<<" "<<a->mau;
}