#include <iostream>
using namespace std;

struct node{
    int Data;

    node* next;
};

int main()
{
    node* head = NULL;
    node* now = NULL;
    node* last = NULL;
    node* t;

    int a,sum = 0;
    cout <<"请输入次数:";
    cin >> sum;
    for(int i = 0; i<sum;i++){
        cout << "请输入第" << i+1 << "个:";
        cin >> a;
        now = new node;
        now->Data = a;
        now->next = NULL;
        if(head == NULL) head = now;
        else last->next = now;
        last = now;
    }
    t = head;

    cin >> a;
    while(t!=NULL)
    {
        if(t->next == NULL || t->Data > a)
        {
            now = new node;
            now->Data = a;
            now->next = t->next;
            t->next = now;
            break;
        }
        t = t->next;
    }
    t = head;

    while(t!=NULL){
        cout << t->Data << " ";
        t = t->next;
    }
    delete head;
    delete now;
    delete last;
    delete t;
    return 0;
}
