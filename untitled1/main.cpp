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
        //qDebug()<<id<<ask<<answer;
        //string sask = ask.toStdString();
        //string sanswer = answer.toStdString();
        cout << " ID: " <<id << endl;
        cout << " ASK: "<<ask << endl;
        cout <<" ANSWER: " << answer << endl;

    }
    query.exec(QObject::tr("SELECT * FROM LAI WHERE ASK LIKE '你好%';"));
    while(query.next())
    {
       QString tes = query.value(2).toString();
        cout <<"LIKE: " <<tes;
    }


    db.close();

    return 0;
}

























