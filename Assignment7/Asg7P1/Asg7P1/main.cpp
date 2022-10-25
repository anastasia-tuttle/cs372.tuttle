//
//  main.cpp
//  Asg7P1
//
//  Created by Anastasia Tuttle  on 10/25/22.
//
#include <iostream>
#include <vector>
#include "Graph.h"
using namespace std;
//vector<vector<int>> &path;
bool Graph::cycle(vector<int> &path) const
{
    // Mark all the vertices as not visited and not part of recursion stack
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
            recStack[i] = false;
        }
        // Call the recursive helper function to detect cycle in different DFS trees
        for (int i = 0; i < V; i++){
            path.push_back(i);
            if (isCyclicUtil(i, visited, recStack, path)) {
                reverse(path.begin(),path.end());
                //path.pop_back();
                return true;
            }
            path.clear();
        }
        path.clear();
        return false;
}

