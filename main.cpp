#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAXDATA 0x3f3f3f3f
using namespace std;
//MaxHeap
template <class T>
class Heap {
private:
    T *elements;
    int capacity;
    int size;
public:
    void Push(T data);
    T Pop();
    void Print();
    bool IsFull();
    bool IsEmpty();
    Heap(int maxsize) {
        elements=(T *)malloc((maxsize+1)*sizeof(T));
        size=0;
        capacity=maxsize;
        elements[0]=MAXDATA;
    }
};

template <class T>
bool Heap<T>::IsFull() {
    if(capacity==size) {
        return true;
    }
    return false;
}

template<class T>
void Heap<T>::Push(T data) {
    if(IsFull()) {
        printf("The heap is full!\n ");
        return;
    }
    ++size;
    int i;
    for( i=size; elements[i/2]<data; i=i/2) {
        elements[i]=elements[i/2];
    }
    elements[i]=data;
}

template<class T>
void Heap<T>::Print() {
    for(int i=1; i<=size; i++) {
        printf("%d ",elements[i]);
    }
}

template<class T>
bool Heap<T>::IsEmpty() {
    if(size==0)return true;
    return false;
}

template<class T>
T  Heap<T>::Pop() {
    int a,b;
    if(IsEmpty()) {
        printf("The heap is empty!\n");
        return 0;
    }
    T maxItem=elements[0];
    T temp=elements[size--];
    for(int i=1; i<=size; i=a) {
        a=i*2;
        b=i*2+1;
        if(b<=size&&elements[a]<elements[b])a=b;
        if(elements[a]<=temp) {
            break;
        } else {
            elements[i]=elements[a];
        }
    }
    elements[a/2]=temp;
    return maxItem;
}
int main() {
    Heap<int>*maxHeap=new Heap<int>(10);
    maxHeap->Push(4);
    maxHeap->Push(5);
    maxHeap->Push(6);
    maxHeap->Push(10);
    maxHeap->Push(7);
//    printf("%d ",maxHeap->size);
//    printf("%d ",maxHeap->capacity);
//    printf("%d ",maxHeap->elements[2]);
maxHeap->Print();
puts("");
    maxHeap->Pop();
    maxHeap->Pop();
  maxHeap->Pop();
    maxHeap->Print();
    return 0;
}
