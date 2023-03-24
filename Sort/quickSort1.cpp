#include<iostream>
using namespace std;

int partition(int a[], int L, int R, int key){
        int iL=L, iR=R;
        while(iL<=iR){
            while(a[iL]< key) iL++;
            while(a[iR]> key) iR--;
            if(iL <=iR){
                swap(a[iL], a[iR]);
                iL++;iR--;
            }
        }
        for(int i=0;i<9;i++) cout << a[i] <<" "; cout << endl;
        return iL;
}

void quickSort(int a[], int L, int R){
    //dk dung
    if(L>=R) return;

    //tao khoa
    int key=a[(L+R)/2];

    // tao chot
    int parti=partition(a,L,R,key);

    //goi lai ham
    quickSort(a,L,parti-1);
    quickSort(a,parti,R);

}
int main(){
    int a[9]={1, 2, 7, 6, 5, 8, 2, 3, 4};
    for(int i=0;i<9;i++) cout << a[i] <<" ";
    cout << endl;
    quickSort(a,0,8);
    for(int i=0;i<9;i++) cout << a[i] <<" ";
}