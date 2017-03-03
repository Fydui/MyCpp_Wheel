#include <queuetp.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    QueueTp<string> cs(5);
    string temp;

    while(!cs.isfull())
    {
        cout << "enter your name:";
        getline(cin,temp);
        cs.enqueue(temp);
    }
    cout << "the queue is full . processing" << endl;
    while(!cs.isempty())
    {
        cs.dequeue(temp);
        cout << "Processing: " << temp << endl;
    }
}


