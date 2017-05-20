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
    cout << "Ĭ�Ϲ��캯��Useless()������,objects����:" << ct << endl;
    ShowObject();
}

Useless::Useless(int k) : n(k)
{
    ++ct;
    cout << "���캯��Useless(int k)������,objects����:" << ct << endl;
    pc = new string[n];
    ShowObject();
}

Useless::Useless(int k, string ch) : n(k)
{
    ++ct;
    cout << "���캯��Useless(int k, string ch)������,objects����:" << ct << endl;
    pc = new string[n];
    for(int i = 0; i < n; i++)
         pc[i] = ch;
    ShowObject();
}

Useless::Useless(const Useless & f) : n(f.n)
{
    ++ct;
    cout << "���캯��Useless(const Useless & f)������,objects����:"<< ct << endl;
    pc = new string[n];
    for(int i = 0; i < n; i++)
        pc[i] = *f.pc;
    ShowObject();
}

Useless::Useless(Useless && f) :n(f.n)
{
    ++ct;
    cout << "�ƶ����幹�캯��Useless(Useless && f)������,objects����:" << ct << endl;
    pc = f.pc;
    f.pc = nullptr;
    f.n = 0;
    ShowObject();
}

Useless::~Useless()
{
    cout << "��������������; objects����;" << --ct << endl;
    cout << "ɾ��objects" << endl;
    ShowObject();
    delete [] pc;
}

Useless Useless::operator +(const Useless & f) const
{
    cout << "����operator+()" << endl;
    Useless temp = Useless(n + f.n);
    for(int i = 0; i < n; i++)
        temp.pc[i] = pc[i];
    for(int i = n; i < temp.n; i++)
        temp.pc[i] = f.pc[i - n];
    cout << "temp objects:" <<endl;
    cout << "�뿪operator+()" << endl;
    return temp;
}

void Useless::ShowObject() const
{
    cout << "Ԫ�ظ���:" << n;
    cout << "���ݵ�ַ:" << (void *)pc << endl;
}

void Useless::ShowData() const
{
    if (n == 0)
        cout << "object Ϊ��" << endl;
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

