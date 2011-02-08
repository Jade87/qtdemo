#define STRICT  1
#include <QApplication>
#include <QTextEdit>
#include <QtGui>
#include "chekos.h"
#include "timer.h"
#include <QMainWindow>




int main(int argc, char *argv[])
{
    QApplication a(argc,argv);

    showWin lab1("");

    lab1.setFixedHeight(11);
    lab1.setFixedWidth(250);
  //  lab1.setWindowTitle("Test");
    lab1.show();
    return a.exec();
}
