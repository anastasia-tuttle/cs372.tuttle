//
//  main.cpp
//  Asg6P1
//
//  Created by Anastasia Tuttle  on 10/19/22.
//

#include <iostream>
#include "Tree.h"
int main()
{
    node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
 
    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);
 
    return 0;
}
