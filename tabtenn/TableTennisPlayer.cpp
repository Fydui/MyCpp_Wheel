#include "TableTennisPlayer.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer(const string &fn,
        const string & ln, bool ht):firstrname(fn),
                lastname(ln),hasTable(ht){}

void TableTennisPlayer::Name() const{
    std::cout << lastname << ", " << firstrname;
}
RatedPlayer::RatedPlayer(unsigned int r,const string & fn,
            const string & ln, bool ht):TableTennisPlayer(fn,ln,ht){
    rating = r;
}
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tp)
             :TableTennisPlayer(tp),rating(r){}
