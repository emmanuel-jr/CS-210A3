/*
   Name: Emmanuel Idun
   Student #: 200418000
   Course: CS 210-001
   Assignment # 3, Q.6
   Date due: February 18, 2020

*/



#include <iostream>
#include <iomanip>
#include "timer.h"    //derived from mylibrary.lib (a static library)
using namespace std;


//Non-Recursive/Linear function implementation
int nonRec(int n)
{

    int next;
    int n1 = 0, n2 = 1;

    if (n == 0 || n == 1)
        next = n;
    else
    {
        for (int i = 1; i < n; i++)
        {
            next = n1 + n2;
            n1 = n2;
            n2 = next;
        }
    }


    return next;
}

//Recursive function implementation
int fib(int a)
{
    int next;

    if (a == 0 || a == 1)
        next = a;
    else
        next = fib(a - 2) + fib(a - 1);

    return next;
}




int main()
{
    int n, dummy, dum;
    double timePerSearch;
    Timer  searchTimer;        //defined in "timer.h"
    cout << "Enter the position of the term: ";
    cin >> n;
   int numSearches = n + 1;   //number of numbers in the sequence given the nth position

    cout << scientific << setprecision(3);
    cout << endl << endl;
    cout << "    Function    |  Total Time  |   Time  per  " << endl;
    cout << "     Type       |     (s)      |   Search(s)  " << endl;
    cout << "----------------|--------------|--------------" << endl;


    // Recursive Function --
    // Determine how long it takes to calculate number 
    // in a particular position in the Fibonacci sequence
    searchTimer.start();
    dummy = fib(n);
    searchTimer.stop();

    timePerSearch = searchTimer.getElapsedTime() / (double(numSearches));   //time taken to calculate next element in sequence

    //Output sample info for Recursive Function
    cout << "Recursive       |"
        << setw(14) << searchTimer.getElapsedTime() << "|"
        << setw(14) << timePerSearch << endl;



    // Non-Recursive Function --
    // Determine how long it takes to calculate number
    // in a particular position in the Fibonacci sequence
    searchTimer.start();
    dum = nonRec(n);
    searchTimer.stop();

    timePerSearch = searchTimer.getElapsedTime() / (double(numSearches));       //time taken to calculate next element in sequence

    //Output sample info for Non-Recursive Function
    cout << "Non-Recursive   |"
        << setw(14) << searchTimer.getElapsedTime() << "|"
        << setw(14) << timePerSearch << endl;

    cout << endl << endl;

    //testing output solution
    cout << "Using recursive function, the " << n << "th term : " << dummy << endl;
    cout << "Using non - recursive function, the " << n << "th term : " << dum << endl;
    
    return 0;
}