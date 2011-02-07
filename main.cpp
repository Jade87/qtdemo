#define STRICT  1
#include <QApplication>
#include <QTextEdit>
#include <QtGui>
#include "chekos.h"





int main(int argc, char *argv[]) {

QApplication a(argc,argv);
QLabel *lab1 = new QLabel();

init();
QStringList list(getAllWindow());
    QString strings;
    for (int i = 0; i < list.size(); i++)
        {
            strings += list[i] + "\n";
        }
    lab1->setText(strings);
lab1 -> show();
return a.exec();
}
