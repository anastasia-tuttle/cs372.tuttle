//
//  main.cpp
//  Asg9SelectionSort
//
//  Created by Anastasia Tuttle  on 11/8/22.
//
#include <iostream>
 
using namespace std;
 
// Sort arr[] of size n using Selection Sort.
void SelectionSort (int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; ++i)
    {
        for (j = i+1; j < n; ++j)
        {
            // Comparing consecutive data and switching values if value at i > j.
            if (arr[i] > arr[j])
            {
                arr[i] = arr[i]+arr[j];
                arr[j] = arr[i]-arr[j];
                arr[i] = arr[i]-arr[j];
            }
        }
        // Value at i will be minimum of all the values above this index.
    }
}
 
int main()
{
    int a[] = {5, 10, 20, 50, 100, 1000, 10000, 50000};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<"Before"<<endl;
    for(int i=0; i<n; i++) cout<<a[i]<<" "; cout<<endl;
    auto start = std::chrono::steady_clock::now();
    SelectionSort(a, n);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double>elapsed_seconds = end - start;
    cout<<"After"<<endl;
    for(int i=0; i<n; i++) cout<<a[i]<<" "; cout<<endl;
    std::cout<<"Elapsed wall time(s): "<<elapsed_seconds.count();
    std::cout<<std::endl;
    return 0;
}
