#define STRICT  1
#include <QApplication>
#include <QTextEdit>
#include <QtGui>
#include "chekos.h"
#include "timer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    showWin lab1("");
    QRect rec(200,200,400,150);
    lab1.setGeometry(rec);
    lab1.show();
    return a.exec();
}
