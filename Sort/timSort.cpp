#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;
template <class T>
class Sorting {
private:
    static void printArray(T* start, T* end)
    {
        int  size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << " ";
        cout << start[size - 1];
        cout << endl;
    }

public:
static void merge(T* left, T* middle, T* right){
    /*TODO*/
    int len1=middle-left+1;
    int len2=right-middle;
    T a1[len1];
    T a2[len2];
    for(int i=0;i<len1;i++) a1[i]=*(left+i);
    for(int i=0;i<len2;i++) a2[i]=*(middle+i+1);
    // rearrange
    int i=0,j=0,k=0;
    while(i<len1 && j<len2){
        if(a1[i]<a2[j]){
            *(left+k)=a1[i++];
            k++;
        }
        else{
            *(left+k)=a2[j++];
            k++;
        }
    }
    while(i<len1){
        *(left+k)=a1[i++];
            k++;
    }
    while(j<len2){
         *(left+k)=a2[j++];
            k++;
    }
}

static void InsertionSort(T* start, T* end) {
    // TODO
    for(T* i =start+1; i<=end; i++){
        T* j =i-1;
        T tmp = *i;
        while(j >= start){
            if(tmp < *j){
                *(j+1) = *j;
            }
            else break;
            j--;
        }
        *(j+1) = tmp;
    }
}

static void TimSort(T* start, T* end, int min_size) {
    // TODO
    // You must print out the array after using insertion sort and everytime calling method merge.
    end--;
    for(T* i=start; i<=end; i+=min_size){
        if(i+min_size-1 >= end){
            InsertionSort(i, end);
        }

        InsertionSort(i, i+min_size-1);
    }
    cout <<"Insertion Sort: ";
    printArray(start, end+1);
    int count=1;
    // merge
    for(int size=min_size; size< end-start+1; size*=2){

        for(T* left = start; left < end; left+= 2*size){

            T* mid = left+size-1;
            T* right;
            if(left+2*size-1 > end){
                right = end;
            }
            else right = left+2*size-1;
            if(mid<end)
            merge(left, mid, right);
            cout <<"Merge "<< count << ": ";
            count++;
            printArray(start, end+1);
        }
    }
}
};
int main(){
    int array[] = { 19, 20, 18, 17 ,12, 13, 14, 15, 1, 2, 9, 6, 4, 7, 11, 16, 10, 8, 5, 3 };
    int min_size = 4;
    Sorting<int>::TimSort(&array[0], &array[20], min_size);
}