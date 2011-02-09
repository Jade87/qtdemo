#include <QtCore/QCoreApplication>
#include <iostream>
#include "systemwin32.h"
#include <QStringList>
#include <QTime>

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTime time;
    time.start();

    while(1)
    {

    init();
    QStringList list( getAllWindow());
    QString strings;

    for (int i = 0; i < list.size(); i++)
      {
           strings += list[i] + "\n";
       }

    cout<<strings.toLocal8Bit().data();
    strings.clear();
    clearList();
    a.processEvents();
}

    return a.exec();
}
