#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
class Customer{
private:
    long arrive;
    int processtime;
public:
    Customer(){arrive = processtime = 0;}
    void set(long when);
    long when() const{return arrive;}
    int prime() const{return processtime;}
};

class Queue
{
public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    bool enqueue(const Customer &item);
    bool dequeue(Customer &item);
    int queuecount() const;
private:
    struct Node{Customer item; struct Node* next;};
    Queue(const Queue & q) : qsize(0){}
    Queue & operator=(const Queue &q){return *this;}
    enum{Q_SIZE = 10};
    Node *front;
    Node *rear;
    int items;
    const int qsize;
};

#endif // QUEUE_H
