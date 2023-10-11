#include <iostream>
using namespace std;
#include "QueueList.h" 

int main(){

    QueueList queuePepe;
    
    queuePepe.enqueue(28);
    queuePepe.enqueue(82);
    queuePepe.enqueue(12);
    cout << queuePepe.toString() << endl;  

    queuePepe.dequeue() ;
    cout << queuePepe.toString() << std::endl;
   
}