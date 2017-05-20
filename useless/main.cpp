#include <iostream>
#include <string>
using namespace std;
class Useless
{
  private:
    int n;
    string * pc;
    static int ct;
    void ShowObject() const;
  public:
    Useless();
    explicit Useless(int k);
    Useless (int k, string ch);
    Useless (const Useless & f);
    Useless (Useless && f);
    ~Useless();
    Useless operator +(const Useless &f) const;
    void ShowData() const;
};

int Useless::ct = 0;

Useless::Useless()
{
    ++ct;
    n = 0;
    pc = nullptr;
    cout << "默认构造函数Useless()被调用,objects数量:" << ct << endl;
    ShowObject();
}

Useless::Useless(int k) : n(k)
{
    ++ct;
    cout << "构造函数Useless(int k)被调用,objects数量:" << ct << endl;
    pc = new string[n];
    ShowObject();
}

Useless::Useless(int k, string ch) : n(k)
{
    ++ct;
    cout << "构造函数Useless(int k, string ch)被调用,objects数量:" << ct << endl;
    pc = new string[n];
    for(int i = 0; i < n; i++)
         pc[i] = ch;
    ShowObject();
}

Useless::Useless(const Useless & f) : n(f.n)
{
    ++ct;
    cout << "构造函数Useless(const Useless & f)被调用,objects数量:"<< ct << endl;
    pc = new string[n];
    for(int i = 0; i < n; i++)
        pc[i] = *f.pc;
    ShowObject();
}

Useless::Useless(Useless && f) :n(f.n)
{
    ++ct;
    cout << "移动语义构造函数Useless(Useless && f)被调用,objects数量:" << ct << endl;
    pc = f.pc;
    f.pc = nullptr;
    f.n = 0;
    ShowObject();
}

Useless::~Useless()
{
    cout << "析构函数被调用; objects减少;" << --ct << endl;
    cout << "删除objects" << endl;
    ShowObject();
    delete [] pc;
}

Useless Useless::operator +(const Useless & f) const
{
    cout << "进入operator+()" << endl;
    Useless temp = Useless(n + f.n);
    for(int i = 0; i < n; i++)
        temp.pc[i] = pc[i];
    for(int i = n; i < temp.n; i++)
        temp.pc[i] = f.pc[i - n];
    cout << "temp objects:" <<endl;
    cout << "离开operator+()" << endl;
    return temp;
}

void Useless::ShowObject() const
{
    cout << "元素个数:" << n;
    cout << "数据地址:" << (void *)pc << endl;
}

void Useless::ShowData() const
{
    if (n == 0)
        cout << "object 为空" << endl;
    else
        for(int i = 0; i < n; i++)
            cout << pc[i];
    cout << endl;
}

int main()
{
    Useless one(10,"X");
    Useless two = one;
    Useless three(20,"O");
     Useless four(one + three);
    cout << "object one:" << endl;
    one.ShowData();
    cout << "object two: " << endl;
    two.ShowData();
    cout << "object three:" << endl;
    three.ShowData();
    cout << "object four: " << endl;
    four.ShowData();

    return 0;
}

