#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<const int, string> Pair;
typedef multimap<int, string> MapCode;

int main(){
    MapCode codes;

    codes.insert(Pair(415,"booy"));
    codes.insert(Pair(510,"next"));
    codes.insert(Pair(718,"do"));
    codes.insert(Pair(718,"or"));
    codes.insert(Pair(510,"♂"));

    cout << "415:" << codes.count(415) << endl;
    cout << "718:" << codes.count(718) << endl;
    cout << "510:" << codes.count(510) << endl;

    cout << "遍历输出:" <<endl;
    MapCode::iterator it;
    for(it = codes.begin(); it != codes.end(); ++it)
        cout << " "<<(*it).first << " " << (*it).second << endl;

    pair<MapCode::iterator,MapCode::iterator>ra = codes.equal_range(718);
    cout << "输出所有718:" << endl;
    for(it = ra.first; it != ra.second; ++it)
        cout << (*it).second << endl;

    return 0;

}
