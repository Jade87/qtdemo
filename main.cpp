#include <QtCore/QCoreApplication>
#include <iostream>
#include "systemwin32.h"
#include <QStringList>
#include <QTime>
#include <QFile>

using namespace std;
 QString strings;
 QFile log("log.txt");

 void update()
 {
     QTime timer;
     timer.start();
     while(1){

         if(timer.elapsed()>1000)
     {
             //system("cls");
         init();
        QStringList list( getAllWindow());
        for (int i = 0; i < list.size(); i++)
        {
           strings += list[i] + "\n";
         }
        cout<<"=====================================================\n";
        cout<<"|"<<strings.toLocal8Bit().data()<<"\n";
        cout<<"=====================================================\n\n";
        log.flush();
        if(log.exists()){}
        if(!log.open(QIODevice::ReadWrite)){}

        log.write("|"+strings.toAscii()+"",1024);
        timer.start();

     }
     strings.clear();
     clearList();
log.close();
 }

 }
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


     update();



    return a.exec();
}
