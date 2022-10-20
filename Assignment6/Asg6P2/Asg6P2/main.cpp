//
//  main.cpp
//  Asg6P2
//
//  Created by Anastasia Tuttle  on 10/19/22.
//

//function to remove the leaves on a tree
void removeLeaves(node* &T)
{
    if(T != NULL)
    {
        if(T->left == NULL && T->right == NULL)
        {
            T = NULL;
            return;
        }
        removeLeaves(T->left);
        removeLeaves(T->right);
    }
}
