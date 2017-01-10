#include <iostream>
using namespace std;

template <typename T> void counts();
template <typename T> void report(T &);

template <typename TT>
class HasFriendT
{
private:
    TT item;

public:
    HasFriendT(const TT & i) : item(i){ct++;}
    ~HasFriendT() {ct--;}
    friend void counts<TT>();
    friend void report<>(HasFriendT<TT> & );
    static int ct;
};
template <typename T>
int HasFriendT<T>::ct =0;

template <typename T>
void counts()
{
    cout << "template size:" << sizeof(HasFriendT<T>) <<endl;
    cout << "template counts:" << HasFriendT<double>::ct <<endl;
}

template <typename T>
void report(T & hf)
{
    cout << hf.item << endl;
}

int main()
{
    cout << "Start:" << endl;;
    HasFriendT<int> hfil(10);
    HasFriendT<int> hfi2(20);
    HasFriendT<double> hfdb(10.5);
    report(hfil);
    report(hfi2);
    report(hfdb);

    cout << "counts<int>() : ";
    counts<int>();
    cout << "counts<double>():";
    counts<double>();
    return 0;
}
