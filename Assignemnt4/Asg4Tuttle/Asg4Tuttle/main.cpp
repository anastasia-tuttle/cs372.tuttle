//
//  main.cpp
//  Asg4Tuttle
//
//  Created by Anastasia Tuttle  on 9/11/22.
//
#include <iostream>
using namespace std;
class Circle
{
    public:
        int key;
        Circle *next;
        Circle *prev;
};
int main()
{
    int N,M;
    cout<<"Welcome to the game of Hot Potato.\n";
    cout<<"Enter the number of players (N): ";
    cin>>N;
    cout<<"Enter how many passes you want to make (M): ";
    cin>>M;
    Circle *c;
    c = new Circle[N];
    for(int i=0; i<N; i++)
    {
        (c+i)->key = i+1;
        if (i==N-1) (c+i)->next = c;
        else (c+i)->next = (c+i+1);
        if (i==0) (c+i)->prev = (c+N-1);
        else (c+i)->prev=(c+i-1);
    }
    Circle *current = c;
    cout<<"Order of players that are eliminated: \n";
    for (int i=1; i<N; i++)
    {
        for(int j=1; j<=M; j++)
    {
        current = current->next;
    }
        cout<<current->key<<" ";
        current = current->next;
        current->prev=((current->prev)->prev);
        (current->prev)->next = current;
    }
    cout<<endl<<"Winner of the game is: "<<current->key<<endl<<" Congratulations!\n";
    delete(c);
    
    return 0;
}
