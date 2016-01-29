#include <iostream>
using namespace std;
typedef struct People People;

struct People{
    int age;
    int height;
    char name[20];
    char father[20];
    char mother[20];
    People *next;
};

int main(){

    People* first = NULL;
    People* current = NULL;
    People* Previos = NULL;
    char test = '\0';

    cout << "Do you want to enter deails of you(y/n)";
    cin >> test;

    if(tolower(test) == 'n'){
        cout << "Bye(Please Enter)";
        cin.clear();
        return 0;

    }

    current = new People;
   if(first == NULL)
       first = current;

   if(Previos != NULL)
       Previos->next = current;

   cout << "Enter the name of you: ";
   cin >> current->name;
   cout << "How old are you? " << current->name << endl;
   cin >> current->age;
   cout << "How heighe for you? " << endl;
   cin >> current->height;
   cout << "What's your father name? " << endl;
   cin >> current->father;
   cout << "What's your motehr name? " << endl;
   cin >> current->mother;

   current->next = NULL;
   Previos = current;
   cout << endl;
   current = first;

   while(current != NULL){

       cout << current->name << "This's your name.\n" << current->age << " This's your age.\n"
            << current->height << " This's your height.\n" << current->mother << " This's your mother's name.\n"
            << current->father << " This's your father's name.\n";

       Previos = current;
       current = current->next;
       delete current;
       current = NULL;
   }
       first = NULL;
       return 0;

   }
