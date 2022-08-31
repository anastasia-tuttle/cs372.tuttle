//
//  Header.h
//  Asg2Part1
//
//  Created by Anastasia Tuttle  on 8/30/22.
//

#ifndef Header_h
#define Header_h
#endif /* Header_h */
#include <vector>
using namespace std;
template<typename T>  // Vector<int> aVect;
class Vector
{
    T* arr;
    int capacity;
    int current;
    
    public :
    Vector()
    {
        arr = new T[1];
        capacity = 1;
        current = 0;
    }
    ~Vector()
    {
        delete [] arr;
        arr = nullptr;
    }
void push(T data)
{
    //if the number of elements is equal to the capacity
    if (current == capacity)
    {
        T* temp = new T[2 * capacity];
        for (int i = 0; i < capacity; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        capacity *=2;
        arr = temp;
        }
        arr[current] = data;
        current++;
}
void push_back(T data, int index)
{
    if (index == capacity)
        push(data);
    else
        arr[index] = data;
}
T get(int index)
{
    if (index < current)
        return arr[index];
}
void pop()
{
    current --;
}
int size()
{
    return current;
}
int getcapacity()
{
    return capacity;
}
void print()
{
    for (int i = 0; i < current; i++)
    {
        cout<<arr[i]<<" ";
    }
        cout<<endl;
}

    private :
        void timer();
};
       
