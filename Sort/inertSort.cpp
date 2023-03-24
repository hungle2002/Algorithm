#include<iostream>
using namespace std;
// chen vao dung vi tri tru trai sang phai
void insertsort(int* arr, int n){
    for(int i=1;i<n;i++){
        int j = i-1, tmp = arr[i];
        while( j >= 0){
            if(arr[j] > tmp){
                arr[j+1] = arr[j];
            }
            else break;
            j--;
        }
        arr[j+1] = tmp;
        for(int k=0;k<n;k++) cout << arr[k]<<" ";
        cout << endl;
    }
}
int main(){
    int arr[6]={23, 78, 45, 8, 32, 56};
    insertsort(arr, 6);
}