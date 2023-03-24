#include<iostream>
#include<string>
using namespace std;
int binary_search(int arr[], int l, int r, int key){
    if(l>r) return -1;
    int mid = (l+r)/2;
    if(key < arr[mid]){
        return binary_search(arr, l, mid-1, key);
    }
    else if(key > arr[mid]){
        return binary_search(arr, mid+1, r, key);
    }
    return mid;
}
int main(){
    int n = 10;
    int arr[] = {0, 1, 0, 2, 0, 1, 9};
    cout << binary_search(arr, 0, 6, 9 );
}
