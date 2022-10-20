//
//  main.cpp
//  Asg6P5
//
//  Created by Anastasia Tuttle  on 10/19/22.
//

#include <iostream>
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
template <typename ValueType>

class Graph
{
public:
    virtual bool adjacent(ValueType x, ValueType y);
    virtual neighbors(ValueType x);
    virtual  void addEdge (ValueType source, ValueType dest);
    virtual void addNode (ValueType x);
    virtual void deleteEdge (ValueType source, ValueType dest);
    virtual void deleteNode (ValueType node);
};
