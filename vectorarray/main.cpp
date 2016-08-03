#include <iostream>
#include <vector>
#include <QString>
#include <string>
#include <QtSql/QSql>
#include <qsqlquery.h>
using namespace std;

QSqlQuery* query;
QString read(vector<vector<QString>> &name,QString Figure,int Sum)
{
    int k = 0;
    QString qslname;
    QString qsl = "SELECT * FROM SG WHERE NAME LIKE " + "'"+ qslname +"%'";
    for(int j = 0; j < 2; j++)
    {
        for(int i = 0; i < 6; i++)
        {
            if(Figure == name[j][i])
            {
                qslname = name[j][i];
                query.exec(qslname);
                while(query->next())
                {
                   QString re = query->value(Sum)->toStdString();
                   return re;
                }
            }
            k++;
        }
    }
    if(k == 12)
    {
        //错误界面
    }

}

vector<vector<QString>> vec(QString* SG,QString* DS)
{
    vector<vector<QString>> array(2);
    for(int i = 0; i< 2;i++)
        array.resize(2);
    array[0].resize(6);
    array[1].resize(6);

    //for(int a = 0; a < 2; a++)
        for(int b = 0; b < 6; b++){
            array[0][b] = SG[b];
            array[1][b] = DS[b];
        }
return array(2);
}

int main()
{
    query = new QSqlQuery;
    QString SG[6] = {"列克星敦","声望","罗德尼","空想","昆西","海伦娜"};
    QString DS[6] = {"航母Ο级","战巡Κ级","战列Μ级","驱逐Α级","重巡Ι级","轻巡Ε级"};

    vector<vector<QString>> list = vec(SG,DS);
    QString name = read(list,"列克星敦",3);


    return 0;
}
