#include <iostream>
using namespace std;

struct node{
    int Data;
    node* next;
};

int addlist(int a,node* now)
{
    cout << "�Ѳ���"<< a << endl;
    node* newnode = new node;//�����ڵ�
    while(now!=NULL){       //�����ǰ�ڵ㲻Ϊ��(û�����һ��)
        if(now->next == NULL || now->Data > a)
        {                   //�����ǰ�ڵ�ĺ�̽ڵ��ǿյ� �����¸��ڵ��ֵ���������
            newnode = new node; //�·��䵱ǰ�ڵ�
            newnode->Data = a;  //��������
            newnode->next = now->next;//�½ڵ�ĺ��ָ��ָ��ǰ�ڵ�ĺ��ָ����ָ��Ľڵ�
            now->next = newnode;//��ǰ�ڵ�ĺ��ָ��ָ���µĽڵ�
            break;
        }
        now = now->next;        //������һ���ڵ�
    }
    delete newnode;
}

int main()
{
    node* head = NULL;
    node* now = NULL;
    node* last = NULL;

    int a,sum = 0;
    cout <<"���������:";
    cin >> sum;
    for(int i = 0; i<sum;i++){
        cout << "�������" << i+1 << "��:";
        cin >> a;
        now = new node;
        now->Data = a;      //�����ݲ��뵱ǰ�ڵ�
        now->next = NULL;   //�ѵ�ǰ�ڵ��ָ��ĺ��ָ����ΪNULL
        if(head == NULL) head = now;//�����һ���ڵ��ǿյ� �ѵ�ǰ�Ľڵ��ɵ�һ��
        else last->next = now;      //�����һ���ڵ㲻�ǿյ� ����һ���ڵ�ĺ��ָ��ָ��ǰ�ڵ�
        last = now;                 //���ѵ�ǰ�ڵ�����һ���ڵ�
    }
    addlist(10,head);
    while(head!=NULL){
        cout << head->Data << " ";
        head = head->next;          //��� �����һ���ڵ㲻�ǿյ� ��ô������� Ȼ��ѵ�ǰ�ڵ�����һ���ڵ�
    }
    delete head;
    delete now;
    delete last;
    return 0;
}
