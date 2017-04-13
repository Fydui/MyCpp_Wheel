#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main(){

    const int N = 6;
    string s1[N] = {"ass","we","can","ass","next","door"};
    string s2[N] = {"my","name","is","van","i'am","actors"};

    set<string> A(s1,s1+N);
    set<string> B(s2,s2+N);

    ostream_iterator<string,char> out(cout , " ");
    cout << "Set A: ";
    copy(A.begin(),A.end(),out);
    cout << endl << "Set B: ";
    copy(B.begin(),B.end(),out);
    cout << endl << "AB并集:";
    set_union(A.begin(),A.end(),B.begin(),B.end(),out);
    cout << endl << "AB交集: ";
    set_intersection(A.begin(),A.end(),B.begin(),B.end(),out);
    cout << endl;

    set<string> C;
    cout << "Set C: " << endl;
    set_union(A.begin(),A.end(),B.begin(),B.end(),insert_iterator<set<string>>(C,C.begin()));
    copy(C.begin(),C.end(),out);
    cout << endl;

    string s3("grungy");
    C.insert(s3);
    cout << "插入grungy:" <<endl;
    copy(C.begin(),C.end(),out);
    cout << endl;
    cout << "输出范围:"<<endl;
    copy(C.lower_bound("g"),C.upper_bound("s"),out);
    cout << endl;

    return 0;
}

