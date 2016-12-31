#include <Worker.h>
#include <cstring>
const int LIM = 5;
int main(){
    Worker* a[LIM];
    int c;
    for(c = 0; c <LIM; c++){
        char choice;
        cout << "请输入类型:" << endl;
        cout << "w:waiter s:singer t:singing waiter q:quit\n";
        cin >> choice;
        while (strchr("wstq",choice) == NULL) {
            cout << "Error" << endl;
            cin >> choice;
        }
        if(choice == 'q') break;
        switch (choice) {
        case 'w':a[c] = new Waiter;
                 break;
        case 's':a[c] = new Singer;
                 break;
        case 't':a[c] = new SingingWaiter;
            break;
        }
    cin.get();
    a[c]->Set();
    }
    for(int i = 0; i< c; i++){
        cout << endl;
        a[i]->Show();
        delete a[i];
    }
    cout << "DONE" << endl;
return 0;
}
