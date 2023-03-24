#include<iostream>
#include<queue>
using namespace std;
class Stack{
private:
    queue<int>q1, q2;
    int count;
public:
    Stack(){
        count=0;
    }
    void push(int num){
        q2.push(num);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int>q;
        q=q1;
        q1=q2;
        q2=q;
        count++;
    }
    void pop(){
        if(q1.size()>0){q1.pop();count--;}
        return;
    }
    int top(){
        if(q1.size()==0) return -1;
        return q1.front();
    }
};
int main(){
    Stack a;
    a.push(10);
    a.push(11);
    cout << a.top()<<endl;
    a.pop();
    a.pop();
    cout << a.top()<<endl;
}