#ifndef MOD_H
#define MOD_H
#include<vector>
#include <string>
#include<QString>
#include <QObject>
using namespace std;
class mod: public QObject
{
    Q_OBJECT
    
public: 
    mod(QObject*p = 0);
    Q_INVOKABLE  QString luckg( QString str){
        int n = str.toInt();
        n = n -1;
        int znum = group[n].size() -1;
        srand((unsigned)time(NULL));
        int s = rand()%znum;
        
        return QString::fromStdString(group[n][s]);
    }
    
    Q_INVOKABLE QString luckc(){
        int cnum = clas.size();
        srand((unsigned)time(NULL));
        int s = rand() % cnum;
        
        return QString::fromStdString(clas[s]);
    }
    int numOfgroup = 0;
    int numOfclass = 0;
    vector<vector<string>> group;
    vector<string> clas;
};

#endif // MOD_H
