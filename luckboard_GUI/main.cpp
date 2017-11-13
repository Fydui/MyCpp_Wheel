#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <fstream>
#include <QtCore>
#include <QtGui>
#include <time.h>
#include "mod.h"

using namespace std;


int main(int argc, char *argv[])
{
    QTextCodec *xcodec = QTextCodec::codecForLocale() ;
           QString exeDir = xcodec->toUnicode( QByteArray(argv[0]) ) ;
           QString BKE_CURRENT_DIR = QFileInfo(exeDir).path() ;
           QStringList  libpath;
           libpath << BKE_CURRENT_DIR+QString::fromLocal8Bit("/plugins/platforms");
           libpath << BKE_CURRENT_DIR <<BKE_CURRENT_DIR+QString::fromLocal8Bit("/plugins/imageformats");
           libpath << BKE_CURRENT_DIR+QString::fromLocal8Bit("/plugins");
           //libpath << QApplication::libraryPaths();
           libpath << QCoreApplication::libraryPaths();
           QCoreApplication::setLibraryPaths(libpath) ;
           
           
           QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
           QGuiApplication app(argc, argv);
           
    mod* mymod = new mod;
    QString pa =  app.QCoreApplication::applicationDirPath() + "/setting.txt";
    
    int book = 0;
    ifstream inflie;
    string file = pa.toStdString();
    inflie.open(file.data());
    //assert(inflie.is_open());
    string in;
    while(getline(inflie, in)){
        auto found = in.find("=");
        if(found != string::npos){
            string left = "";
            left = in.substr(0,found-1);
            if(left == "END") book = 1;
            if(left == "组数" || book == 0){
                if(left == "组数"){
                    string temp = in.substr(found+2,in.size());
                    mymod->numOfgroup = stoi(temp);
                }
                else{
                    string temp2 = in.substr(found+2,in.size());
                    string temp3 = in.substr(0,found-1);
                    //int c = stoi(temp3);
                    int s_t2 = (temp2.size()-1)/2;
                    vector<string> ts;
                    //mymod.group.push_back(ts);
                    
                    int num_t2 = (s_t2+1)/2;
                    for(int i = -1; i < num_t2; i++){
                        auto t2_s = temp2.find(",");
                        ts.push_back(temp2.substr(0,t2_s));                        
                        temp2 = temp2.substr(t2_s+1,temp2.size());
                        
                    }
                    mymod->group.push_back(ts);
                    ts.clear();
                }
            }
            if((left == "总人" || book == 1)&& left != "END"){
                if(left == "总人"){
                    string temp = in.substr(found+2,in.size());
                    mymod->numOfgroup = stoi(temp);
                }
                else if(left != "= 21"){
                    auto ztemp = in.find("=");
                    string ztemp2 = in.substr(ztemp+2,in.size());
                    mymod->clas.push_back(ztemp2);}
                
            }
        }
        
    }
   
    

    
    QQmlApplicationEngine* engine = new QQmlApplicationEngine;
    QQmlContext* con = engine->rootContext();
    con->setContextProperty("mymod",mymod);
    //auto window = qobject_cast<QQuickWindow*>(engine->rootObjects().first());
    //if (window) {
    //    window->setIcon(QIcon("qrc:/myico.ico"));
    //}
    engine->load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine->rootObjects().isEmpty())
        return -1;
    
    return app.exec();
}
