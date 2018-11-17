#include <iostream>
#include <new>
#include <sys/sysinfo.h>
using namespace std;

int main()
{    
    double * p;
    double * i;
    long testmemorylimit;
  
    struct sysinfo info;
    
    sysinfo (&info);

    cout << "Total Memory:        " << info.totalram << " bytes" << "\n";
    cout << "Current Free Memory: " << info.freeram << " bytes" << "\n";
    
    testmemorylimit = info.freeram * 0.9 / 8; // number of memory allocation that would fit in 90% mem
    cout << "Number of allocation: " << testmemorylimit << "\n";
    cout << "Press any key to start test! \n";
    getchar();

    p = new (nothrow) double;
    double * firstpointer = p;  // keep track of the first pointer
    *p = 3.14159;
 
    // while loop to allocate memory until 10% free memory remaining
    while ((p != nullptr) && (testmemorylimit != 0)) {
       p++; // incrementing pointer 
       p = new (nothrow) double; // creating pointer
       *p = 3.14159; // add value to memory space
       cout << "Allocation # " << testmemorylimit << " " << p << " " << *p << "\n";
       testmemorylimit--; // decrementing testmemorylimit
    }

    double * lastpointer = p; // keep track of the last pointer;
    cout << "All free memory has been allocated";
    
    // display content of all allocated memory and release memory
    for (i = firstpointer; i = lastpointer; i++) {
       cout << i << " " << *i << "\n";
       delete i; // delete pointer
    }

    return 0;
}
