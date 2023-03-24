#include <iostream>
using namespace std;
int ccount=0;
template<class T>
class Heap {
protected:
    T* elements;
    int capacity;
    int count;
public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[]elements;
    }
    void push(T item);
    int getItem(T item);
    void remove(T item);
    void clear();
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }
private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};
template<class T>
void Heap<T>::push(T item){
    if(count == capacity){
        ensureCapacity(count);
    }
    elements[count] = item;
    reheapUp(count);
    count++;
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    int *arr = new int[minCapacity*2];
    for(int i=0; i<count; i++){
        arr[i] = elements[i];
    }
    delete elements;
    elements = arr;
    capacity = minCapacity*2;
}

template<class T>
void Heap<T>::reheapDown(int position){
   int left = position*2+1;
   int right = position*2+2;
   if(left < count){
      int large=left;
      if(right<count && elements[right] > elements[left]){
         large = right;
      }
      if(elements[large] > elements[position]){
         swap(elements[large], elements[position]);
         reheapDown(large);
      }
   }
}

template<class T>
void Heap<T>::reheapUp(int position){
    if(position >0){
        int pos = (position-1)/2;
        if(elements[pos] < elements[position]){
            swap(elements[pos], elements[position]);
            ccount+=1;
            reheapUp(pos);
        }
    }
}
template<class T>
int Heap<T>::getItem(T item) {
    // TODO: return the index of item in heap
    for(int i=0; i<count; i++){
        if(elements[i] == item){
            return i;
        }
    }
    return -1;
}

template<class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    int pos = getItem(item);
    if(pos == -1){
        return;
    }
    swap(elements[pos], elements[count-1]);
    count--;
    reheapUp(pos);
    reheapDown(pos);
}

template<class T>
void Heap<T>::clear() {
    // TODO: delete all elements in heap
    delete elements;
    count=0;
}

int main(){
Heap<int> maxHeap;
int arr[] =  {73, 79, 47, 93, 65, 96, 44, 80, 85, 49, 37, 14, 38, 84, 22};
for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
    maxHeap.push(arr[i]);
maxHeap.printHeap();
cout <<endl<< ccount;
}