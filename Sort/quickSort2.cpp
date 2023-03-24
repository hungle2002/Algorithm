#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;
template <class T>
class Sorting {
    public:
static T* Partition(T* start, T* end) {
    // TODO: return the pointer which points to the pivot after rearrange the array.
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

static void QuickSort(T* start, T* end) {
    // TODO
    // In this question, you must print out the index of pivot in subarray after everytime calling method Partition.
    // dk dung
    if(start >= end) return;
    // de quy

    T* pivot = Partition(start, end-1);
    cout << pivot-start<<" ";
    QuickSort(start, pivot);
    QuickSort(pivot+1, end);    
}
};
int main(){
    int array[] = { 1, 2, 6, 4, 7, 8, 5, 3 };
Sorting<int>::QuickSort(&array[0], &array[8]);
cout << "\n";
cout << "Array after sorting: ";
for (int i : array) cout << i << " ";
}