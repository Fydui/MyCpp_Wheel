#include <iostream>
using namespace std;

struct node{
    int Data;
    node* next;
};

int addlist(int a,node* now)
{
    cout << "已插入"<< a << endl;
    node* newnode = new node;//新增节点
    while(now!=NULL){       //如果当前节点不为空(没到最后一个)
        if(now->next == NULL || now->Data > a)
        {                   //如果当前节点的后继节点是空的 或者下个节点的值大于输入的
            newnode = new node; //新分配当前节点
            newnode->Data = a;  //输入数据
            newnode->next = now->next;//新节点的后继指针指向当前节点的后继指针所指向的节点
            now->next = newnode;//当前节点的后继指针指向新的节点
            break;
        }
        now = now->next;        //继续下一个节点
    }
    delete newnode;
}

int main()
{
    node* head = NULL;
    node* now = NULL;
    node* last = NULL;

    int a,sum = 0;
    cout <<"请输入次数:";
    cin >> sum;
    for(int i = 0; i<sum;i++){
        cout << "请输入第" << i+1 << "个:";
        cin >> a;
        now = new node;
        now->Data = a;      //把数据插入当前节点
        now->next = NULL;   //把当前节点的指针的后继指针设为NULL
        if(head == NULL) head = now;//如果第一个节点是空的 把当前的节点变成第一个
        else last->next = now;      //如果第一个节点不是空的 把上一个节点的后继指针指向当前节点
        last = now;                 //最后把当前节点变成上一个节点
    }
    addlist(10,head);
    while(head!=NULL){
        cout << head->Data << " ";
        head = head->next;          //输出 如果第一个节点不是空的 那么输出数据 然后把当前节点变成下一个节点
    }
    delete head;
    delete now;
    delete last;
    return 0;
}
