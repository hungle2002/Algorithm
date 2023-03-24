#include<iostream>
using namespace std;
void reheapup(int arr[], int pos){
    if(pos > 0){ // ton tai parent
        int parent = pos/2;
        if( arr[parent] < arr[pos]){
            swap(arr[parent], arr[pos]);
        }
        reheapup(arr, parent);
    }
}
void reheapdown(int arr[], int pos, int last){
    int lchild = pos*2 + 1;
    int rchild = pos*2 + 2;
    if( lchild <= last){
        int largechild;
        if(rchild <= last && arr[rchild] > arr[lchild]){
            largechild = rchild;
        }
        else largechild = lchild;
        if(arr[largechild] > arr[pos]) swap(arr[largechild], arr[pos]);
        reheapdown(arr, largechild, last);
    }
}
void buildheap(int arr[], int last){
    for(int i=0; i<=last/2; i++){
        reheapdown(arr, i, last);
    }
}
void heapsort(int arr[], int last){
    buildheap(arr, last);
    while(last>0){
        cout << endl;
        swap(arr[0], arr[last]);
        last =last-1;
        reheapdown(arr, 0, last);
    }
}
int main(){
    int arr[6] = {23, 78, 45, 8, 32, 56};
    for(int i=0; i<6; i++) cout << arr[i]<<" ";
    cout << endl;
    heapsort(arr, 5);
    for(int i=0; i<6; i++) cout << arr[i] << " ";
}