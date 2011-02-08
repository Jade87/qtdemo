#define STRICT  1
#include <QApplication>
#include <QTextEdit>
#include <QtGui>
#include "chekos.h"
#include "timer.h"

int main(int argc, char *argv[])
{

    QApplication a(argc,argv);
     // wTimer t;
    showWin lab1("");
   // QTimer *timer = new QTimer(this);
  //  connect(&t.timer,SIGNAL(timeout()),this,SLOT(t.updateWinList()));
  //  timer->start(1000);
    QRect rec(200,200,400,150);
    lab1.setGeometry(rec);
    lab1.show();
    return a.exec();
}
