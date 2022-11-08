//
//  main.cpp
//  Asg9QuickSort
//
//  Created by Anastasia Tuttle  on 11/8/22.
//

#include <iostream>
#include <ctime>
#include <vector>
#include <chrono>
using namespace std;
template<class T> void swap(T *a, T *b)
{
    T t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int start, int end)
{
    int pivot = a[end];
    int i = (start-1);
    for(int j=start; j<=end-1; j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(a[i+1], a[end]);
    return (i+1);
}
void quick_sort(int a[], int start, int end)
{
    if(start<end)
    {
        int pivot_index = partition(a, start, end);
        quick_sort(a, start, pivot_index-1);
        quick_sort(a, pivot_index+1, end);
    }
}
int main()
{
  int a[] = {5, 10, 20, 50, 100, 1000, 10000, 50000};
  int n = sizeof(a)/sizeof(a[0]);
  cout<<"Before"<<endl;
  for(int i=0; i<n; i++) cout<<a[i]<<" "; cout<<endl;
    auto start = std::chrono::steady_clock::now();
  quick_sort(a, 0, n-1);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double>elapsed_seconds = end - start;
  cout<<"After"<<endl;
  for(int i=0; i<n; i++) cout<<a[i]<<" "; cout<<endl;
    std::cout<<"Elapsed wall time(s): "<<elapsed_seconds.count();
    std::cout<<std::endl;
  return 0;
}

