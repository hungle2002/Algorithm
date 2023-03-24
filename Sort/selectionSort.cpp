#include<iostream>
using namespace std;
// tim phan tu lon nhat r swap voi phan tu ben da sort
void selectionsort(int* arr, int n){
    for(int i=0;i<n-1;i++){
        int min=1000,pos;
        for(int j=i+1;j<n;j++){
            if(arr[j]<min){
                min=arr[j];
                pos=j;
            }
        }
        if(min < arr[i]) swap(arr[i], arr[pos]);
        for(int k=0;k<n;k++) cout << arr[k]<<" ";
        cout << endl;
    }
}
int main(){
    int arr[6]={9, 2, 8, 1, 0, -2};
    selectionsort(arr, 6);
}