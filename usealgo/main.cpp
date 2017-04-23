#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>
using namespace std;

void display(const string & a)
{
    cout << a << " ";
}

char toLower(char ch){ return tolower(ch);}

string & ToLower(string & st)
{
    transform(st.begin(),st.end(),st.begin(),toLower);
    return st;
}


int main()
{
    vector<string> words;
    cout << "输入单词(quit退出): " << endl;
    string input;
    while (cin >> input && input != "quit")
        words.push_back(input);
    cout << "原始数据: " << endl;
    for_each(words.begin(),words.end(),display);
    cout << endl;
    set<string> word_s;
    transform(words.begin(),words.end(),insert_iterator<set<string>>(word_s,word_s.begin()),ToLower);
    cout << "list: " << endl;
    for_each(word_s.begin(),word_s.end(),display);
    cout << endl;

    map<string,int> wordmap;
    set<string>::iterator si;
    for(si = word_s.begin();si != word_s.end(); si++)
        wordmap[*si] = count(words.begin(),words.end(),*si);

    cout << "新数据: " << endl;
    for_each(word_s.begin(),word_s.end(),display);

    return 0;
}
