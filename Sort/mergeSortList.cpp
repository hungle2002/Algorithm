#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int _val = 0, ListNode* _next = nullptr) : val(_val), next(_next) { }
};

// You must use the nodes in the original list and must not modify ListNode's val attribute. 
// Hint: You should complete the function mergeLists first and validate it using our first testcase example

// Merge two sorted lists
ListNode* mergeLists(ListNode* a, ListNode* b) {
    ListNode* head;
    if(a->val > b->val){
        head = b;
        b=b->next;
        }
    else{ 
        head = a;
        a=a->next;
    }
    ListNode* cur =head;
    while(a!=NULL && b!=NULL){
        if(a->val < b->val){
            cur->next=a;
            cur = cur->next;
            a=a->next;
        }
        else{
            cur->next=b;
            cur=cur->next;
            b=b->next;
        }
    }
    while(a!=NULL){
        cur->next=a;
        cur = cur->next;
        a=a->next;
    }
    while(b!=NULL){
        cur->next=b;
        cur=cur->next;
        b=b->next;
    }
    return head;
}

// Sort and unsorted list given its head pointer
ListNode* mergeSortList(ListNode* head) {
    //dk dung
    if(head->next==NULL) return head;
    // divide
    ListNode* mid=head;
    ListNode* pos = head->next;
    while(pos != NULL){
        pos=pos->next;
        if(pos!=NULL){
            pos=pos->next;
            mid=mid->next;
        }
    }
    ListNode* second = mid->next;
    mid->next=NULL;
    // de quy chia doi
    head = mergeSortList(head);
    second = mergeSortList(second);
    // mergesort
    return mergeLists(head, second);

    return nullptr;
}

int main(){

}