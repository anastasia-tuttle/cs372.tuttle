//
//  main.cpp
//  Asg8P1
//
//  Created by Anastasia Tuttle  on 11/1/22.
//
#include<iostream>
#include<vector>
#define NODE 20
using namespace std;
vector<sting>graph[NODE][NODE] =
    {{'Adam Sandler' 'Andrew Garfield' 'Blake Lively' 'Tom Holland' 'David Schwimmer'}
    {'Any Poehler' 'Dylan Obrien' 'Anastasia Tuttle' 'Ed Westwick' 'Eddie Murphy' }
    {'Cameron Diez' 'Hugh Jackman' 'Jake M. Johnson' 'Elizabeth Olsen' 'John Travolta' }
    {'Keanu Reeves' 'Jennifer Aniston' 'Julie Andrews' 'Kevin Bacon' 'Nicole Kidman'}};

void traverse(int u, bool visited[]) {
   visited[u] = true; //mark v as visited
   for(int v = 0; v<NODE; v++) {
      if(graph[u][v]) {
         if(!visited[v])
            traverse(v, visited);
      }
   }
}
bool isConnected() {
   bool *vis = new bool[NODE];
   for(int u; u < NODE; u++) {
      for(int i = 0; i<NODE; i++)
         vis[i] = false;
         traverse(u, vis);
      for(int i = 0; i<NODE; i++) {
         if(!vis[i])
            return false;
      }
   }
   return true;
}
int main() {
   if(isConnected())
      cout << "You are connected to Kevin Bacon.";
   else
      cout << "You are not connected to Kevin Bacon.";
}
