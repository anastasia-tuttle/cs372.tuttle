//
//  main.cpp
//  asg9P2
//
//  Created by Anastasia Tuttle  on 11/8/22.
//

// C++ code to demonstrate the working of
// sort_heap()
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
   vector<int> heap = {5, 10, 20, 50, 100, 1000, 10000, 50000};
   make_heap(heap.begin(), heap.end());
   cout <<"Before Sort : ";
   for (const auto &i : heap)
   {
      cout << i << ' ';
   }
    auto start = std::chrono::steady_clock::now();
   sort_heap(heap.begin(), heap.end());
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double>elapsed_seconds = end - start;
    cout<<"\n After Sort: ";
   for (const auto &i : heap)
   {
       cout << i << ' ';
   }
    std::cout<<"\n Elapsed wall time(s): "<<elapsed_seconds.count();
    std::cout<<std::endl;
}
