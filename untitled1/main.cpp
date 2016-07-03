#include <iostream>
#include <QtSql>
#include <QString>
#include <string>
#include <QSqlQuery>
#include <qsqlquery.h>
#include <QDebug>
#include <QTextCodec>
#include <QObject>
using namespace std;

int main()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); //添加数据库驱动链接sqlite
    db.setDatabaseName("LAI.db");
    if(!db.open())
    {
        qDebug() <<"can't open sql";
    }
    QSqlQuery query;
    query.exec(QObject::tr("CREATE TABLE LAI(ID INTEGER PRIMARY KEY AUTOINCREMENT,ASK TEXT, ANSWER TEXT)"));
    query.exec(QObject::tr("INSERT INTO LAI VALUES(1,'你好','你好啊')"));
    query.exec(QObject::tr("INSERT INTO LAI VALUES(2,'你叫啥','凉果冻')"));
    query.exec(QObject::tr("INSERT INTO LAI VALUES(3,'你多大','不告诉你')"));
    query.exec(QObject::tr("SELECT * FROM LAI ORDER BY ID ASC"));
    QTextStream cout(stdout,QIODevice::WriteOnly); //中文输出
    while(query.next())
    {
        int id = query.value(0).toInt();
        QString ask = query.value(1).toString();
        QString answer = query.value(2).toString();

        cout << " ID: " <<id << endl;
        cout << " ASK: "<<ask << endl;
        cout <<" ANSWER: " << answer << endl;

    }
    //使用like进行字符串查询
    query.exec(QObject::tr("SELECT * FROM LAI WHERE ASK LIKE '你好%';"));
    while(query.next())
    {
       QString tes = query.value(2).toString();
        cout <<"LIKE: " <<tes;
    }

    //添加表
    /*
    query.exec("INSERT INTO LAI(ID,ASK,ANSWER)VALUES(?,?,?)");

    QVariantList id;
    id << 4;
    query.addBindValue(id);

    QVariantList ask;
    ask << "远看炮塔吓死人";
    query.addBindValue(ask);

    QVariantList answer;
    answer << "近看五队负重轮";
    query.addBindValue(answer);
    query.finish();*/
    query.exec(QObject::tr("INSERT INTO LAI VALUES(4,'远看炮塔吓死人','近看五队负重轮')"));
    query.exec(QObject::tr("SELECT * FROM LAI ORDER BY ID ASC"));
    while(query.next())
    {
        int id = query.value(0).toInt();
        QString ask = query.value(1).toString();
        QString answer = query.value(2).toString();

        cout << " ID: " <<id << endl;
        cout << " ASK: "<<ask << endl;
        cout <<" ANSWER: " << answer << endl;

    }


    //删除数据
    //query.prepare("delete from LAI where id = 2");
    query.exec("delete from LAI where id = 2");
    query.exec(QObject::tr("SELECT * FROM LAI ORDER BY ID ASC"));
    while(query.next())
    {
        int id = query.value(0).toInt();
        QString ask = query.value(1).toString();
        QString answer = query.value(2).toString();

        cout << " ID: " <<id << endl;
        cout << " ASK: "<<ask << endl;
        cout <<" ANSWER: " << answer << endl;

    }
    db.close();

    return 0;
}

























