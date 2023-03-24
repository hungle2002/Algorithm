#include <iostream>
using namespace std;

template <class T>
class Sorting
{
private:
    static T *Partition(T *start, T *end);

public:
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void insertionSort(T *start, T *end);

    static void hybridQuickSort(T *start, T *end, int min_size);
};
template <class T>
T *Sorting<T>::Partition(T *start, T *end){
    T* i=start+1;
    T* j=end;
    while( i <= j ){
        while(*i < *start) i++;
        while(*j > *start) j--;
        if( i < j ){
            T tmp=*i;
            *i=*j;
            *j=tmp;
            i++; j--;
        }
    }
    T tmp=*start;
    *start = *j;
    *j = tmp;
    return j;
}

template <class T>
void Sorting<T>::insertionSort(T *start, T *end){
    for(T* i =start+1; i<end; i++){
        T* j =i-1;
        T tmp = *i;
        while(j >= start){
            if(tmp > *j){
                *(j+1) = *j;
            }
            else break;
            j--;
        }
        *(j+1) = tmp;
    }
}

template <class T>
void Sorting<T>::hybridQuickSort(T *start, T *end, int min_size){
    // dk dung
    if(start >= end) return;
    //check dk
    if(end - start < min_size){
        cout <<"Insertion sort: ";
        printArray(start, end);
        insertionSort(start, end);
        return;
    }
    //quick sort
    cout<<"Quick sort: ";
    printArray(start, end);
    T* pivot = Partition(start, end-1);
    //cout <<"pivot: "<<*pivot;
    hybridQuickSort(start, pivot, min_size);
    hybridQuickSort(pivot+1, end, min_size);
}
int main(){
    int array[] = {1, 2, 6, 4, 7, 8, 5, 3};
    int min_size = 4;
    Sorting<int>::hybridQuickSort(&array[0], &array[8], min_size);
    for(int i=0; i<8; i++) cout << array[i]<<" ";
}