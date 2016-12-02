#ifndef TABLETENNISPLAYER_H
#define TABLETENNISPLAYER_H
#include <string>
using namespace std;
//类继承 简单使用派生类

class TableTennisPlayer //基类
{
private:
    string firstrname;
    string lastname;
    bool hasTable;
public:
    TableTennisPlayer(const string & fn = "none",const string & ln = "node", bool ht = false);
    void Name() const;
    bool HasTable() const {return hasTable;}
    void ResetTable(bool v) {hasTable = v;}
};

class RatedPlayer : public TableTennisPlayer
{
private:
    unsigned int rating;
public:
    RatedPlayer(unsigned int r = 0, const string & fn = "none",
                const string & ln = "none",bool ht = false);
    RatedPlayer(unsigned int r, const TableTennisPlayer & tp);
    unsigned int Rating() const {return rating;}
    void ResetTable(unsigned int r){rating = r;}
};
#endif // TABLETENNISPLAYER_H
