#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;

template <class T>
class Sorting {
private:
    static void printArray(T* start, T* end)
    {
        int size = end - start;
        for (int i = 0; i < size; i++)
            cout << start[i] << " ";
        cout << endl;
    }

public:
static void sortSegment(T* start, T* end, int segment_idx, int n) {
    // TODO
    start+=n;
   for(T* i = start+segment_idx; i<=end; i+=segment_idx){
        T* j =i-segment_idx;
        T tmp = *i;
        while(j >= start){
            if(tmp < *j){
                *(j+segment_idx) = *j;
            }
            else break;
            j-=segment_idx;
        }
        *(j+segment_idx) = tmp;
    }
}

static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases) {
    // TODO
    // Note: You must print out the array after sorting segments to check whether your algorithm is true.
    for(int i=num_phases-1; i>=0; i--){
        for(int j=0; j<num_segment_list[i]; j++){
        sortSegment(start, end-1, num_segment_list[i],j);
        }
        cout <<num_segment_list[i] <<" segments: ";
        printArray(start, end);
    }
    
}
};
int main(){
    int num_segment_list[] = {1, 3, 5};
    int num_phases = 3;
    int array[] = { 10, 9, 8 , 7 , 6, 5, 4, 3, 2, 1 };

    Sorting<int>::ShellSort(&array[0], &array[10], &num_segment_list[0], num_phases);
}