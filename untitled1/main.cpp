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
{   //QTextCodec* codec = QTextCodec::codecForName("UTF-8");

    QStringList drivers = QSqlDatabase::drivers();
    drivers.removeAll("QSQLITE");
    foreach (QString driver, drivers)
    {
        qDebug()<<"\t"<<driver;
    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("LAI.db");
    if(!db.open())
    {
        qDebug() <<"can't open sql";
    }
    QSqlQuery query;
    query.exec(QObject::tr("CREATE TABLE LAI(ID INTEGER PRIMARY KEY AUTOINCREMENT,"
               "ASK TEXT, ANSWER TEXT)"););
    query.exec(QObject::tr("INSERT INTO LAI VALUES(1,'你好','你好啊')");
    query.exec("INSERT INTO LAI VALUES(2,'你叫啥','凉果冻')");
    query.exec("INSERT INTO LAI VALUES(3,'你多大','不告诉你')");
    query.exec("SELECT * FROM LAI ORDER BY ID ASC");
    while(query.next())
    {
        int id = query.value(0).toInt();
        QString ask = query.value(1).toString();
        QString answer = query.value(2).toString();
        qDebug()<<id<<ask<<answer;

    }

    db.close();
}
