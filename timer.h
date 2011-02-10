#ifndef TIMER_H
#define TIMER_H
//#include "chekos.h"
#include <QTimer>
//#include <QTextEdit>
#include <QFile>
class showWin
{
    private :
            bool t_show;
            QString strings;
            QString time;
            QFile file;
            char a[1024];

    protected:
         virtual QString timerEvent(QTimerEvent*)
         {

            init();
            QStringList list(getAllWindow());
            for (int i = 0; i < list.size(); i++)
             {
                 strings += list[i] + "\n";
             }
         return strings;
        }
    public :
            showWin(const QString& strText,
                    int nInterval = 1000,
                    QWidget* pwgt = 0)


    {
        startTimer(nInterval);
       QTextStream st(&file);
    }


};

#endif // TIMER_H
