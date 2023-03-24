#include<iostream>
#include<string>
using namespace std;
int jumpSearch(int arr[], int n, int k, int key){
    int i=0;
    while(i<n){
        int r = i+k;
        if(r>=n) r = n-1;
        if(arr[i] <= key && arr[r] >= key){
            for(int j=i; j<=r; j++){
                if(arr[j] == key){
                    return j;
                }
            }
            return -1;
        }
        i+=k;
    }
    return -1;
}
int main(){
    int n = 10;
    int arr[] = {0, 1, 0, 2, 0, 1, 9};
    cout << jumpSearch(arr, 7, 3, 1);
}
