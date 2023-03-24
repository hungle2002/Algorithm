#include<iostream>
#include<stack>
using namespace std;
class Queue{
private:
    stack<int> s1,s2;
    int count=0;
public:
    Queue(){
        count=0;
    }
    void push(int num){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(num);
         while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        count++;
    }
    void pop(){
        s1.pop();
    }
    int top(){
        if(s1.empty()) return -1;
        return s1.top();
    }
};
int main(){
    Queue a;
    a.push(1);
    a.push(2);
    a.push(3);
    cout << a.top()<<" ";
    a.pop();
    cout << a.top()<<" ";
    a.pop();
    cout << a.top()<<" ";
}