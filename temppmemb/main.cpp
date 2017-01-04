#include <iostream>
using namespace std;

template <typename T>
class beta
{
private:
    template<typename V>
    class miao
    {
    private:
        V val;
    public:
        miao(V v = 0) : val(v){}
        void show() const {cout << val << endl;}
        V value() const {return val;}
    };
    miao<T> q;
    miao<int> n;

public:
    beta(T t, int i) : q(t),n(i) {}
    template <typename U>
    U blab(U u,T t) {return ((n.value() + q.value()) * u/t);}
    void bshow() const {q.show(); n.show();}
};
int main()
{
    beta<double> guy(3.5,3);
    cout << "T 设置为double类型" << endl;
    guy.bshow();
    cout << "V 设置为 T类型,, 然后V设置为int类型" << endl;
    cout << guy.blab(10.0,2.3) << endl;
    cout << "U被设置为double" << endl;
    cout << "DONE" << endl;
    return 0;
}

