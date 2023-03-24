#include<iostream>
using namespace std;
class Node{
    int data;
    Node* next;
    Node* previous;
public:
    Node(int val){
        this->data=val;
        next=NULL;
        previous=NULL;
    }
    friend class List;
};
class List{
    Node* head;
    Node* tail;
    int count;
public:
    List(){
        head=NULL;
        tail=NULL;
        count=0;
    }
    void add(int val){
        Node* nNode=new Node(val);
        if(count == 0){
            count = 1;
            head = nNode;
            tail = head;
        }
        else{
            count++;
            tail->next = nNode;
            nNode->previous=tail;
            tail=tail->next;
        }
    }
    void print(){
        Node* tmp = head;
        while(tmp != NULL){
            cout << tmp->data <<" ";
            tmp = tmp->next;
        }
        cout << endl;
    }
    int removeAt(int index){
        int tmp;
        if(index==0){
            tmp = head->data;
            head=head->next;
            if( count == 1) tail = NULL;
        }
        else if(index == count-1){
            tmp = tail->data;
            tail=tail->previous;
            tail->next=NULL;
        }
        else{
            Node* search = head;
            for(int i=0; i<index; i++){
                search = search->next;
            }
            search->previous->next=search->next;
            search->next->previous=search->previous;
        }
        count --;
        return tmp;
    }
    int removeItem(int item){
        
    }
};
int main(){
    List* list = new List();
    for(int i=0; i<2; i++){
        list->add(i);
    }
    list->print();
    list->removeAt(1);
    list->print();

}