#include<iostream>
using namespace std;

void merge(int a[],int L,int mid, int R){
    int len1=mid-L+1;
    int len2=R-mid;
    // init 2 arr
    int arr1[len1],arr2[len2];
    //copy the value
    for(int i=0;i<len1;i++) arr1[i]=a[i+L];
    for(int j=0;j<len2;j++) arr2[j]=a[mid+j+1];
    // arrange
    int k=L;
    int i=0,j=0;
    while(i<len1 && j<len2){
        if(arr1[i]<arr2[j]){
            a[k++]=arr1[i++];
        }
        else a[k++]=arr2[j++];
    }
    while(i<len1) a[k++]=arr1[i++];
    while(j<len2) a[k++]=arr2[j++];
}
void mergeSort(int a[], int L, int R){
    //dk dung
    if(L>=R) return;
    //dk pho bien
    mergeSort(a,L,(L+R)/2);
    mergeSort(a,(L+R)/2+1,R);
    merge(a,L,(L+R)/2,R);
}
int main(){
   int a[6]={1,3,5,2,4,6};
   for(int i=0;i<6;i++) cout << a[i] <<" ";
   cout<< endl;
    mergeSort(a,0,5);
   for(int i=0;i<6;i++) cout << a[i] <<" ";
//   0 1 2 3 4 5 6 7

}