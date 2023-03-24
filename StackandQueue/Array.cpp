// stack + queue by array
#include<iostream>
using namespace std;
class Stack{
private:
    int* arr;
    int size;
    int topIndex;
public:
    Stack(int size){
        this->size=size;
        arr=new int[size];
        this->topIndex=-1;
    }
    bool Isfull(){
        if(topIndex == size-1) return 1;
        return 0;
    }
    bool Isempty(){
        if(topIndex<0) return 1;
        return 0;
    }
    bool push(int val){
        if(this->Isfull()) return 0;
        topIndex++;
        arr[topIndex]=val;
        return 1;
    }
    bool pop(){
        if(this->Isempty()) return 0;
        topIndex--;
        return 1;
    }
    int top(){
        if(Isempty()) return -1;
        return arr[topIndex];
    }
    void print(){
        if(Isempty()) return;
        for(int i=0;i<=topIndex;i++) cout << arr[i] << " ";
        cout << endl;
    }
};
class Queue{
private:
    int* arr;
    int size;
    int head;
    int tail;
public:
    Queue(int size){
        arr=new int[size];
        this->size=size;
        head =-1;
        tail =-1;
    }
    bool Isfull(){
        if((tail+1)%size==head&& head!=-1) return 1;
        return 0;
    }
    bool Isemty(){
        if( head==-1 ) return 1;
        return 0;
    }
    bool push(int val){
        if(Isfull()) return 0;
        if(head==-1){
            head=0;
            tail=0;arr[head]=val;
            return 1;
        }
        tail=(tail+1)%size;
        arr[tail]=val;
        return 1;
    }
    bool pop(){
        if(Isemty()) return 0;
        head=(head+1)%size;
        if((tail+1)%size==head) head=-1;
        return 1;
    }
    int top(){
        if(Isemty()) return -1;
        return arr[tail];
    }
    void print(){
        if(Isemty()) return;
        if(head<=tail){
            for(int i=head;i<=tail;i++) cout << arr[i] <<" ";
        }
        else{
            for(int i=head;i<size;i++) cout << arr[i] <<" ";
            for(int i=0;i<=tail;i++) cout << arr[i] <<" ";
        }
        cout << endl;
    }
};
int main(){
    Queue a(4);
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.pop();
    a.pop();
    a.push(5);
    a.push(6);    
    a.pop();    
    a.pop();
    cout << a.Isemty()<<" "<< a.Isfull()<<" "<< endl;
    a.print();
}   