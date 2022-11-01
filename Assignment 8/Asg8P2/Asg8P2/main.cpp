//
//  main.cpp
//  Asg8P2
//
//  Created by Anastasia Tuttle  on 10/30/22.
//
#include <iostream>
using namespace std;

bool bears(int n)
{
    int lastDigit, lastButOneDigit, product;
    cout<<"\nNumber is "<<n;
    if (n < 42)
        return false;

    if (n == 42)
        return true;
    if (n%5 == 0)
    {
        if(bears(n-42))
        {
            return true;
        }
    }
    if (n%2 == 0)
    {
        if(bears(n/2))
        {
            return true;
        }
    }
    if(n%4 == 0|| n%3 == 0)
    {
        lastDigit=n%10;
        lastButOneDigit=(n%100)/10;
        product = lastDigit * lastButOneDigit;
        return product != 0 && bears(n - product);
    }

    return false;
}

int main()
{
    int num;
    bool hasReached;
    cout<<"Enter the number: ";
    cin>>num;
    hasReached = bears(num);
    if(hasReached)
    {
        cout<<"\nYou have reached the goal!";
    } else {//
        cout<<"\nYou failed\n";
    }
    return 0;
}

