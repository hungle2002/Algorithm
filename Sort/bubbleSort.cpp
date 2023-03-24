#include<iostream>
using namespace std;
void bubblesort(int* arr, int n){
    for(int i=1;i<n;i++){
        bool flag=1;
        int j=n-1;
        while(j>=i){
            if(arr[j]<arr[j-1]){ swap(arr[j], arr[j-1]);flag=0;}
            j--;
        }
        if(flag) break;
    }
}
int main(){
    int arr[6]={23, 78, 45, 8, 32, 56};
    for(int i=0;i<6;i++) cout << arr[i]<<" ";
    cout << endl;
   bubblesort(arr, 6);
    for(int i=0;i<6;i++) cout << arr[i]<<" ";
    cout << endl;
}