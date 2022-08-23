#include <iostream>
#include <chrono>
using namespace std;

void moveDisks(int, int, int, int);
void printIt(int , int , int );
void timer();

int main()
{
    const int FROMPEG = 1;
    const int TOPEG = 3;
    const int TEMPPEG = 2;
    const int NUMDISKS = 3;
    for (auto numdisks: {3,5,10,15,20,25,30,31,32,33})
    {
      cout << "Numdisks: " << numdisks << endl;
      moveDisks(numdisks, FROMPEG, TOPEG, TEMPPEG);
      cout << "Moved " << numdisks << " pegs"
           << " from peg " << FROMPEG
           << " to peg " << TOPEG << endl;
      timer();
    }
}

void moveDisks(int num, int fromPeg, int toPeg, int tempPeg)
{
     if (num > 0) {
        moveDisks(num -1, fromPeg, tempPeg, toPeg);
        printIt(num, fromPeg, toPeg);
        moveDisks(num-1, tempPeg, toPeg, fromPeg);
     }
}
void timer ()
{
    double sum = 0;
    double add = 1;
    auto start = std::chrono::steady_clock::now();
    int iterations = 1000*1000*1000;
    for(int i=0; i<iterations; i++)
    {
        sum +=add;
        add /=2.0;
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout<<"Time measured: "<<elapsed_seconds.count()<<"s\n";
}

void printIt(int disk, int fromPeg, int toPeg)
{
  // Do nothing for timing test, but otherwise
  cout<< "Move disk " << disk
      << " from pef " << fromPeg
      << " to peg " << toPeg << endl;
   
}
