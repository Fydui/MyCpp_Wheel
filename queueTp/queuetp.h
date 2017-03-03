#ifndef QUEUETP_H
#define QUEUETP_H

template <class Item>
class QueueTp
{
private:
    enum{Q_SIZE = 10};
     class Node
     {
     public:
         Item item;
         Node * next;
         Node(const Item & i): item(i),next(nullptr){}
     };
     Node* front;
     Node* rear;
     int items;
     const int qsize;
     QueueTp(const QueueTp & q){}
     QueueTp & operator=(const QueueTp & q){return *this;}
public:
    QueueTp(int qs = Q_SIZE);
    ~QueueTp();
    bool isempty() const {return items == 0;}
    bool isfull() const {return items == qsize;}
    int queuecount() const{return items;}
    bool enqueue(const Item &item);
    bool dequeue(Item &item);
};
template<class Item>
QueueTp<Item>::QueueTp(int qs):qsize(qs)
{
    front = rear = 0;
    items = 0;
}

template <class Item>
QueueTp<Item>::~QueueTp()
{
    Node* temp;
    while(front != 0){
        temp = front;
        front = front->next;
        delete temp;
    }
}
template<class Item>
bool QueueTp<Item>::enqueue(const Item &item)
{
    if(isfull())
        return false;
    Node * add = new Node(item);
    items++;
    if(front == 0) front = add;
    else rear->next= add;
    rear = add;
    return true;
}

template<class Item>
bool QueueTp<Item>::dequeue(Item &item)
{
    if(front == 0)
        return false;
    item = front->item;
    items--;
    Node *temp = front;
    front = front->next;
    delete temp;
    if(items == 0)
        rear = 0;
    return true;
}
#endif // QUEUETP_H
