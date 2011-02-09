#include <QtCore/QCoreApplication>
#include <iostream>
#include "systemwin32.h"
#include <QStringList>

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    init();
    QStringList list( getAllWindow());
    QString strings;
    for (int i = 0; i < list.size(); i++)
      {
           strings += list[i] + "\n";
       }
    cout<<"|-Process name -|"<<"|-Proces Id-|"<<endl;
    cout<<strings.toLocal8Bit().data();
    return a.exec();
}
